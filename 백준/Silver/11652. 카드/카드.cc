#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<long long, int> m;     
    long long k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        m[k]++;
    }

    long long mk = m.begin()->first;
    int mx = 0;
    for (const auto& pair : m) {
        if (pair.second > mx) {
            mx = pair.second;
            mk = pair.first;
        }
    }

    cout << mk;
    return 0;
}
