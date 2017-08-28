
#include <Siv3D.hpp>
#include <Siv3DAddon/LeapMotion.hpp>

void Main()
{
    

    Window::Resize(1280, 720);

    const Font font(30), font2(18);

    LeapMotion::RegisterAddon();

    while (System::Update())
    {
        Graphics3D::FreeCamera();

        for (const auto& hand : LeapMotion::Hands())
        {
            //手のひらの位置
            const Vec3 scaledPos = hand.pos * 0.05;
            Sphere(scaledPos, 0.5).draw(HSV(hand.id * 30).toColor(60));

            const Vec2 screenBase = Graphics3D::ToScreenPos(scaledPos).xy();

            font(hand.isLeft ? L"Left" : L"Right").drawCenter(screenBase.movedBy(20, -160));

            //手のパラメータ表示
            const Circle pinchCircle(screenBase.movedBy(-60, -260), 60);
            const Circle grabCircle(screenBase.movedBy(100, -260), 60);

            pinchCircle.draw(HSV(hand.id * 30).toColor(60));
            pinchCircle.drawPie(0.0, hand.pinchStrength * TwoPi, HSV(hand.id * 30));

            grabCircle.draw(HSV(hand.id * 30).toColor(60));
            grabCircle.drawPie(0.0, hand.grabStrength * TwoPi, HSV(hand.id * 30));

            font2(L"Pinch").drawCenter(pinchCircle.center);
            font2(L"Grab").drawCenter(grabCircle.center);

            for (const auto& finger : hand.fingers)
            {
                for (const auto& joint : finger.joints)
                {
                    Sphere(joint*0.05, 0.2).draw(HSV(finger.id * 10).toColor());
                }
            }

        }

        Box(1).draw();
    }
}
