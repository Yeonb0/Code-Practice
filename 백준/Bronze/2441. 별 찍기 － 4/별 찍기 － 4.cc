#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i = n; i >= 1; i--){
		for(int k = (n-i); k >= 1; k--)
		  cout << " ";
		for(int j = i; j >= 1; j--)
			cout << "*";
		cout << "\n";
	}
	return 0;
}