#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> num;
    for (int i = 1; i <= 9; i++) {
        cout << num << " * " << i << " = " << num * i << '\n';
    }
}