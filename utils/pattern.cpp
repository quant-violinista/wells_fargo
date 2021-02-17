//
// Created by Prasenjit on 2/16/2021.
//

#ifndef WELLS_FARGO_PATTERN
#define WELLS_FARGO_PATTERN

#include <string>
#include<iostream>
#include <bitset>


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
            child += dictionary[state];
        }
        cout << child << endl;
        max_lines--;
        if (parent.compare(child) == 0)
            break;

    }
    return limit - max_lines;
}


#endif
