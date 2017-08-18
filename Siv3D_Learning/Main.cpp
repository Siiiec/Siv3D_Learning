#include <Siv3D.hpp>
#include <boost/format.hpp>
#include <Eigen/Core>
#include <Eigen/QR>
#include <Eigen/Geometry>


//using namespace Eigen;
//using namespace boost;

//double Cost(const matrix<double>& X, const matrix<double>& theta, const matrix<double>& y)
//{
//    const auto m {y.size1()};
//    const matrix<double> h {prod(X, theta)};
//    
//    for (auto a : row(X, 0))
//    {
//        std::cout << a << std::endl;
//    }
//    
//
//    return 0;
//}

double Cost(const Eigen::MatrixXd& X, const Eigen::VectorXd& theta, const Eigen::VectorXd& y)
{
    using namespace Eigen;
    //MatrixXd X_ = X.block(0, 1, X.rows(), X.cols() - 1);
    MatrixXd h = X * theta;

    double cost = (h - y).array().square().sum() / y.rows() / 2;
    
    return cost;
}

std::pair<Eigen::MatrixXd, std::vector<double>> GradientDescent(const Eigen::MatrixXd& X ,Eigen::MatrixXd&& theta, const Eigen::VectorXd& y, double alpha, unsigned itersNum)
{
    using namespace Eigen;
    using namespace std;
    
    vector<double> costHistory(itersNum);
    
    int m = y.rows();
    
    for (unsigned i = 0; i < itersNum; ++i)
    {
        //auto h = X * theta;
        theta = theta - alpha / m * X.transpose() * (X * theta - y);
        
        costHistory[i] = Cost(X, theta, y);

        //if (i % 10 == 0)
        //{
        //    cout << boost::format("cost(%1%)") % i << costHistory[i] << endl;
        //}
    }


    return std::make_pair(move(theta),  move(costHistory));
}

Eigen::MatrixXd NormalEquation(Eigen::MatrixXd&& theta, const Eigen::MatrixXd& X, const Eigen::MatrixXd& y)
{
    //Eigen::MatrixXd pinv = (X.transpose() * X).completeOrthogonalDecomposition().pseudoInverse();
    
    theta = (X.transpose() * X).inverse() * X.transpose() * y;

    return std::move(theta);
}


void Main()
{
    using namespace Eigen;
    using std::cout;
    using std::endl;

    //srand((unsigned int)time(0));
    srand(time(0));

    //Console::Open();
    //
    //
    //MatrixXd X {MatrixXd::Random(10, 2) * 10};
    ////cout << X << endl;
    //X.col(0) = Eigen::MatrixXd::Ones(10, 1);
    ////cout << X << endl;

    //MatrixXd theta = Eigen::MatrixXd::Zero(2, 1);
    //MatrixXd y {MatrixXd::Random(10, 1) * 10};

    //MatrixXd theta2 = Eigen::MatrixXd::Zero(2, 1);
    //
    //cout << "initial cost : " << Cost(X, theta, y) << endl;

    //auto g = GradientDescent(X, std::move(theta), y, 0.03, 1000);

    //theta = std::move(g.first);
    //theta2 = NormalEquation(std::move(theta2), X, y);

    //cout << "theta \n" << theta << endl;
    //cout << "theta2 \n" << theta2 << endl;

    //char c;
    //std::cin >> c;
    //Console::Close();
    


    Window::SetBaseSize(1280, 720);
    Window::Resize(1280, 720);

    const Font font(30);
    constexpr int featureNum = 2;

    MatrixXd X(0, featureNum);
    MatrixXd y(0, 1);
    MatrixXd theta {MatrixXd::Zero(featureNum, 1)};

    std::vector<Vec2> positions;

    GUIStyle style {GUIStyle::Default};
    //style.showTitle = false;
    style.movable = true;
    GUI gui(style);
    gui.setTitle(L"title");
    gui.add(L"button", GUIButton::Create(L"計算"));
    gui.setCenter(Window::BaseCenter());

    int currentSize = 0;
    
    while (System::Update())
    {
        //Transformer2D t(Mat3x2::Scale(0, -1).Translate(Window::BaseHeight(), 0), true);
        //Transformer2D t(Mat3x2::Translate(Window::BaseWidth() / 2, Window::BaseHeight() / 2));
        font(L"ようこそ、Siv3D の世界へ！").draw();

        if (!gui.button(L"button").mouseOver && Input::MouseR.clicked)
        {
            positions.push_back(Mouse::PosF());
            X.conservativeResize(X.rows() + 1, NoChange);
            X.row(X.rows() - 1) = RowVector2d(1, Mouse::PosF().x * 0.01);
            y.conservativeResize(y.rows() + 1, NoChange);
            y.row(y.rows() - 1) = Eigen::Matrix<double, 1, 1>(Mouse::PosF().y * 0.01);
        }
        else if (gui.button(L"button").pushed && !positions.empty())
        {
            //theta = GradientDescent(X, std::move(theta), y, 0.0003, 1000).first;
            theta = NormalEquation(std::move(theta), X, y);
            currentSize = positions.size();
        }


        for (const auto& p : positions)
        {
            Circle(p, 10.0).draw();
        }

        Line(0, theta(0, 0), Vec2(0, theta(0, 0)) + Vec2(1, theta(1, 0)).normalized() * 500).draw(10.0);

        //Circle(Mouse::PosF(), 50).draw({ 255, 0, 0, 127 });
        
        
    }
}
