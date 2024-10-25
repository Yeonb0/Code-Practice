#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a[3][4];
	// 입력
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 4; j++)
			cin >> a[i][j];

	// 출력
	for(int i = 0; i < 3; i++){
		int one = 0;
		for(int j = 0; j < 4; j++)
			if(a[i][j] == 1)
				one ++;
		switch (one) {
			case 0 :
				cout << "D\n";
				break;
			case 1 :
				cout << "C\n";
				break;
			case 2 :
				cout << "B\n";
				break;
			case 3 :
				cout << "A\n";
				break;
			default :
				cout << "E\n";
		}
	}
	return 0;
}