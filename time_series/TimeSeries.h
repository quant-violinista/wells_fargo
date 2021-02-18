//
// Created by Prasenjit Dutt on 2/16/2021.
//

#ifndef WELLS_FARGO_TIMESERIES_H
#define WELLS_FARGO_TIMESERIES_H


class TimeSeries {
    int _start;
    int _duration;
    double *_data;

public:
    TimeSeries() = delete;

    TimeSeries(int duration, int start);

    TimeSeries(const TimeSeries &other);

    TimeSeries &operator=(const TimeSeries &other);

    ~TimeSeries();

    void add(int timestamp, double value);

    const double getValue(int timestamp) const;

};


#endif //WELLS_FARGO_TIMESERIES_H
