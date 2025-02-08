#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	int sum1 = a + b - c;
	string str = to_string(a) + to_string(b);
	int sum2 = stoi(str) - c;
	cout << sum1 << "\n" << sum2;
	
	return 0;
}