//
// Created by Prasenjit on 2/16/2021.
//

#ifndef WELLS_FARGO_TIMESERIES_H
#define WELLS_FARGO_TIMESERIES_H


class TimeSeries {
    int _start;
    int _duration;
    double * _data;

public:
    TimeSeries() = delete;
    TimeSeries(int start, int duration);
    ~TimeSeries();
    void add(int timestamp, double value);
    const double getValue(int timestamp) const;

};


#endif //WELLS_FARGO_TIMESERIES_H
