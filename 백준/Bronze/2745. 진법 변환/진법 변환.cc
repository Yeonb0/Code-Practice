#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string N;
    int B;
    cin >> N >> B;

    long long result = 0;
    int value;

    for (int i = 0; i < N.size(); i++) {
        if (isalpha(N[i])) {
            value = N[i] - 'A' + 10;
        } else {
            value = N[i] - '0';
        }
        result = result * B + value;
    }

    cout << result;
    return 0;
}
