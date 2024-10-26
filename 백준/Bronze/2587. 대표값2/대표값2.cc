#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a[5];
	int avg = 0;
	int mid;
	
	for(int i = 0; i < 5; i++)
		cin >> a[i];
	for(int i = 0; i < 5; i++){
		for(int j = i+1; j < 5; j++){
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		avg += a[i];
	}
	avg /= 5;
	mid = a[2];
	cout << avg << "\n" << mid;
	return 0;
}