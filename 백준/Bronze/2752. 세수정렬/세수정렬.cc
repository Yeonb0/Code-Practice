#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	// 총 경우 6개 
	if (a >= b && a >= c){ // a가 가장 클 때
		if (b >= c) // a > b > c
			cout << c << " " << b << " " << a;
		else        // a > c > b
			cout << b << " " << c << " " << a;
	} else if (b >= a && b >= c){ // b가 가장 클 때
		if (a >= c) // b > a > c
			cout << c << " " << a << " " << b;
		else        // b > c > a
			cout << a << " " << c << " " << b;
	} else { // c가 가장 클 때
		if (a >= b) // c > a > b
			cout << b << " " << a << " " << c;
		else        // c > b > a
		  cout << a << " " << b << " " << c;
	}
	return 0;
}