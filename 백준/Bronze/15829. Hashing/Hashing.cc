#include <iostream>
#include <string>
using namespace std;

const int M = 1234567891;
const int r = 31;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int len;
    string input;
    cin >> len >> input;

    long long hash = 0;
    long long power = 1;

    for (int i = 0; i < len; i++) {
        int val = input[i] - 'a' + 1; // 'a' = 1, ..., 'z' = 26
        hash = (hash + (val * power) % M) % M;
        power = (power * r) % M;
    }

    cout << hash << '\n';
    return 0;
}
