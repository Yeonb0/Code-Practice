#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	for(int i = n; i >= 1; i--){
		for(int j = (n-i); j > 0; j--)
			cout << " ";
		for(int k = 1; k <= 2*i-1; k++) // 부호 수정
			cout << "*";
		cout << "\n";
	} 
	for(int i = 2; i <= n; i++){
		for(int j = (n-i); j > 0; j--)
			cout << " ";
		for(int k = 1; k <= 2*i-1; k++)
			cout << "*";
		cout << "\n";
	} 
	return 0;
}