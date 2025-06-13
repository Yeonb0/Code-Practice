#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string s[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    int x, y;
    cin >> x >> y;

    int day = y;
    for (int i = 1; i < x; i++) day += arr[i];

    cout << s[day % 7];

    return 0;
}
