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
        
        //�v���J�n
        void start();

        //�v������
        void measure();

        //begin~start�Ԃ�duration�𓾂�
        timer::duration getDuration(int begin, int end) const;
        //i~(i+1)�Ԃ�duration�𓾂�
        timer::duration getDuration(int i) const;

    private:
        std::vector<time_point> m_times;
    };




}


