#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < n-i; j++) cout << " ";
		for(int k = 0; k < i; k++) cout << "*";
		cout << "\n";
	}
	for(int i = n-1; i > 0; i--) {
		for(int j = 0; j < n-i; j++) cout << " ";
		for(int k = 0; k < i; k++) cout << "*";
		cout << "\n";
	}
	
	return 0;
}