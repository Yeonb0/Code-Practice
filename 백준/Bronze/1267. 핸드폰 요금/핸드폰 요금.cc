#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int y = 0, m = 0; // 쓰레기 값
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++){
		y += ((a[i] / 30) + 1) * 10;
		m += ((a[i] / 60) + 1) * 15;
	}
	if (y > m)
		cout << "M " << m;
	else if (y == m)
		cout << "Y M " << y;
	else 
		cout << "Y " << y;
	return 0;
}