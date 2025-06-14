#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	if(n == 1) {
		cout << "*";
		return 0;
	} else {
		// 1st
		for(int i = 1; i < n; i++) cout << " ";
		cout << "*\n";
	
		// 2nd~  
		for(int i = 2; i <= n-1; i++){
			for(int j = n-i; j > 0; j--) cout << " ";
			cout << "*";
			for(int k = 1; k <= 2*(i-1)-1; k++) cout << " ";
			cout << "*\n";
		}
	
		// last
		for(int i = 1; i <= 2*n-1; i++) cout << "*";
	
		return 0;
	}
}