#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    int num[5];
    int ver = 0;
    for (int i = 0; i < 5; i++) {
        cin >> num[i];
        ver += num[i] * num[i];
    }
    cout << ver % 10;
    return 0;
}