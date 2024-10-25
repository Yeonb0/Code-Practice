#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a[7];
	int minOdd = 100;
	int sumOdd = 0;
	for(int i = 0; i < 7; i++)
		cin >> a[i];
	for(int i = 0; i < 7; i++)
		if (a[i] % 2 != 0){
			if (a[i] <= minOdd)
				minOdd = a[i];
			sumOdd += a[i];
		}
	if(minOdd == 100) 
		cout << -1;
	else 
		cout << sumOdd << "\n" << minOdd;
	return 0;
}