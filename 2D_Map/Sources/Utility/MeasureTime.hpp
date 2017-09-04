#pragma once

#include <chrono>
#include <vector>


namespace Utility
{
    class MeasureTime
    {
    public:
        using timer = std::chrono::steady_clock;
        using time_point = timer::time_point;

        MeasureTime();
        MeasureTime(bool start);
        
        //計測開始
        void start();

        //計測する
        void measure();

        //begin~start間のdurationを得る
        timer::duration getDuration(int begin, int end) const;
        //i~(i+1)間のdurationを得る
        timer::duration getDuration(int i) const;

    private:
        std::vector<time_point> m_times;
    };




}


