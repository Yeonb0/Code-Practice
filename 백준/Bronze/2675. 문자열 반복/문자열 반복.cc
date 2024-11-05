#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// 입력
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int r;
		string s;
		cin >> r >> s;
		
		// 출력
		for(char ch : s){
			for(int j = 0; j < r; j++){
				cout << ch;
			}
		}
		cout << "\n";
	}
	return 0;
}