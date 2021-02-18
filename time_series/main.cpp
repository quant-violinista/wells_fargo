#include <iostream>
#include "TimeSeries.h"

using namespace std;

int main() {

    TimeSeries ts(20, 5);

    for (int time = 5; time < 25; time++) {
        ts.add(time, time * time);
    }

    cout << "****** Test Case 1: in-place insertion ********************" << endl;
    try {
        ts.add(18, 742.5);
        for (int time = 5; time <= 25; time++) {
            cout << "time : " << time << ", Value: " << ts.getValue(time) << endl;
        }
    }
    catch (char const *e) {
        cout << e << endl;
    }

    cout << "****** Test Case 2: right-shift insertion ********************" << endl;
    try {
        ts.add(27, 999.0);
        for (int time = 8; time <= 28; time++) {
            cout << "time : " << time << ", Value: " << ts.getValue(time) << endl;
        }
    }
    catch (char const *e) {
        cout << e << endl;
    }

    cout << "****** Test Case 3: left-shift insertion ********************" << endl;
    try {
        ts.add(2, 777.0);
        for (int time = 2; time <= 22; time++) {
            cout << "time : " << time << ", Value: " << ts.getValue(time) << endl;
        }
    }
    catch (char const *e) {
        cout << e << endl;
    }

    return 0;
}
