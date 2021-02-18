//
// Created by Prasenjit Dutt on 2/16/2021.
//

#include "TimeSeries.h"
#include <algorithm>


TimeSeries::TimeSeries(int duration, int start = 0) : _start(start), _duration(duration) {
    _data = new double[_duration]{};
}

TimeSeries::TimeSeries(const TimeSeries &other) {
    _duration = other._duration;
    _start = other._start;
    _data = new double[other._duration]{};
    std::copy(other._data, other._data + other._duration, _data);
}

TimeSeries &TimeSeries::operator=(const TimeSeries &other) {
    _duration = other._duration;
    _start = other._start;
    _data = new double[other._duration]{};
    std::copy(other._data, other._data + other._duration, _data);
    return *this;
}

TimeSeries::~TimeSeries() {
    delete[] _data;
    _data = nullptr;
}

void TimeSeries::add(int timestamp, double value) {
    const int pos = timestamp - _start;
    if (pos < 0) {
        double *p = new double[_duration]{};
        p[0] = value;
        const int shift = -pos;
        if (shift < _duration) {
            std::copy(_data, _data + _duration - shift, p + shift);
        }
        delete[] _data;
        _data = p;
        p = nullptr;
        _start = timestamp;
    } else if (pos >= _duration) {
        double *p = new double[_duration]{};
        p[_duration - 1] = value;
        const int shift = pos - _duration + 1;
        if (shift < _duration) {
            std::copy(_data + shift, _data + _duration, p);
        }
        delete[] _data;
        _data = p;
        p = nullptr;
        _start += shift;
    } else {
        _data[pos] = value;
    }
}

const double TimeSeries::getValue(int timestamp) const {
    const int pos = timestamp - _start;
    if (pos < 0 || pos >= _duration)
        throw "Invalid timestamp";
    return _data[pos];
}