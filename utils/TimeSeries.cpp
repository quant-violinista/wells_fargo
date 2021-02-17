//
// Created by Prasenjit on 2/16/2021.
//

#include "TimeSeries.h"


TimeSeries::TimeSeries(int start, int duration) : _start(start), _duration(duration) {
    _data = new double[_duration]{};
}

TimeSeries::~TimeSeries() {
    delete[] _data;
    _data = nullptr;
}

void TimeSeries::add(int timestamp, double value) {
    const int pos = timestamp - _start;
    if (pos < 0 || pos >= _duration)
        throw "Invalid timestamp";
    _data[pos] = value;
}

const double TimeSeries::getValue(int timestamp) const {
    const int pos = timestamp - _start;
    if (pos < 0 || pos >= _duration)
        throw "Invalid timestamp";
    return _data[pos];
}