#include <iostream>
#include <string>
using namespace std;
int al[27] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10,0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
    int sum = 0;
	for(char ch : s) {
		sum += al[ch-'A'];
	}
    cout << sum;
	return 0;
}