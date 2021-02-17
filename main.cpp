#include <iostream>
#include <string>
#include <bitset>
#include "utils/TimeSeries.h"
//#include "utils/pattern.cpp"

using namespace std;


namespace {
    string isOn(char letter) {
        if (letter == 'o')
            return "1";
        else
            return "0";
    }
}

int auto1d(int rule, char *positions, int limit) {
    const string dictionary = bitset<8>(rule).to_string();
    string parent(positions);
    int max_lines = limit;

    int length = parent.size();
    int state{0};

    cout << parent << endl;

    while (max_lines > 0) {
        string child{};
        for (int i = 0; i < length; i++) {
            if (i == 0) {
                state = bitset<3>(string("0" + isOn(parent[i]) + isOn(parent[i + 1]))).to_ulong();
            } else if (i == length - 1) {
                state = bitset<3>(string(isOn(parent[i - 1]) + isOn(parent[i]) + "0")).to_ulong();
            } else {
                state = bitset<3>(string(isOn(parent[i - 1]) + isOn(parent[i]) + isOn(parent[i + 1]))).to_ulong();
            }
            child += dictionary[7 - state] == '0' ? " " : "o";
        }
        cout << child << endl;
        max_lines--;
        if (parent.compare(child) == 0)
            break;
        parent = child;

    }
    return limit - max_lines;
}


int main() {
    const int generated_rows = auto1d(18, "          o          ", 20);
    cout << "Number of rows" << generated_rows << endl;


/*    TimeSeries ts(5, 20);
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
    return 0;*/
}
