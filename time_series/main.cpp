#include <iostream>
#include "TimeSeries.h"
using namespace std;

int main() {
    TimeSeries ts(5, 20);
    try {
        for (int time = 5; time <= 15; time++) {
            ts.add(time, time * time);
        }
        ts.add(18, 742.5);
        for (int time = 5; time < 25; time++) {
            cout << "time : " << time << ", Value: " << ts.getValue(time) << endl;
        }

        cout << "time : " << 2 << ", Value: " << ts.getValue(2) << endl;

    }
    catch (char const *e) {
        cout << e << endl;
    }
    return 0;
}
