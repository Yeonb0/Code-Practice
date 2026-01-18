#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    while (getline(cin, str)) {
        int s = 0, l = 0, n = 0, g = 0;
        for (char c : str) {
            if (c == ' ') g++;
            else if ('0' <= c && c <= '9') n++;
            else if ('A' <= c && c <= 'Z') l++;
            else if ('a' <= c && c <= 'z') s++;
        }
        cout << s << " " << l << " " << n << " " << g << "\n";
    }

    return 0;
}
