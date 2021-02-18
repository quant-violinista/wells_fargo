#include <iostream>
#include <string>
#include <bitset>

using namespace std;


int auto1d(int rule, char *positions, int limit) {
    auto isOn = [](char letter) -> string {
        if (letter != ' ')
            return "1";
        else
            return "0";
    };
    const string dictionary = bitset<8>(rule).to_string();
    string parent(positions);
    int lines_left = limit;

    int length = parent.size();
    int state{0};

    cout << parent << endl;

    while (lines_left > 0) {
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
        lines_left--;
        if (parent.compare(child) == 0)
            break;
        parent = child;

    }
    return limit - lines_left;
}


int main() {
    int generated_rows = auto1d(18, "          o          ", 20);
    cout << "Number of rows : " << generated_rows << endl;
    generated_rows = auto1d(204, "          o          ", 20);
    cout << "Number of rows : " << generated_rows << endl;

    return 0;
}
