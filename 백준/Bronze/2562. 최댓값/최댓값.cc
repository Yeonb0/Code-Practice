#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a[9];
	int max = 0, index;
	for(int i = 0; i <= 9; i++)
		cin >> a[i];
	for(int i = 0; i <= 9; i++){
		if(a[i] >= max){
			max = a[i];
			index = i;
		}
	}
	cout << max << "\n" << index+1;
	return 0;
}