#include "MeasureTime.hpp"
#include <iostream>

namespace Utility
{
    namespace
    {
        using namespace std;
        using namespace std::chrono;
    }

    MeasureTime::MeasureTime()
    {

    }

    MeasureTime::MeasureTime(bool start)
    {
        if (start)
            this->start();
    }

    void MeasureTime::start()
    {
        m_times.emplace_back(timer::now());
    }

    void MeasureTime::measure()
    {
        m_times.emplace_back(timer::now());
    }

    MeasureTime::timer::duration MeasureTime::getDuration(int begin, int end) const
    {
        //try
        //{
        //    return m_times.at(end) - m_times.at(begin);
        //}
        //catch (const std::out_of_range& e)
        //{
        //    cerr << "MeasureTime::getDuration() : out of range" << e.what() << endl;
        //
        //}

        return m_times[end] - m_times[begin];
    }

    MeasureTime::timer::duration MeasureTime::getDuration(int i) const
    {
        return getDuration(i, i + 1);
    }


}

