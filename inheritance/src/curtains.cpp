/*
A furnishing company is manufacturing a new collection of curtains. The curtains are of two colors aqua(a) and black (b). The curtains color is represented as a string(str) consisting of a’s and b’s of length N. Then, they are packed (substring) into L number of curtains in each box. The box with the maximum number of ‘aqua’ (a) color curtains is labeled. The task here is to find the number of ‘aqua’ color curtains in the labeled box.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int L;

    cin >> str;
    cin >> L;

    int res = 0;
    for (int i = 0; i < str.length(); i += L) {
        int cnt = 0;
        for (int j = i; j < i + L && j < str.length(); j++) {
            if (str[j] == 'a') {
                cnt++;
            }
        }
        if (cnt > res) {
            res = cnt;
        }
    }

    cout << res;
    return 0;
}