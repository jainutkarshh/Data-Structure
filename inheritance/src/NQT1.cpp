/*A chocolate factory is packing chocolates into the packets. The chocolate packets here represent an array of N number of integer values. The task is to find the empty packets(0) of chocolate and push it to the end of the conveyor belt(array).*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result;
    int zeroCount = 0;

    for (int value : arr) {
        if (value == 0) {
            zeroCount++;
        } else {
            result.push_back(value);
        }
    }

    for (int i = 0; i < zeroCount; i++) {
        result.push_back(0);
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }

    return 0;
}

