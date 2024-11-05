#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// 입력
	int a[9] = {0};
	string n;
	int max = 0;
	cin >> n;
	
	// 계산
	for(int i : n){
		if(i == '9')
			a[6]++;
		else
			a[i-'0']++;
	}
	
	a[6] = (a[6] + 1) / 2;
	for(int i = 0; i < 9; i++){
		if (max < a[i])
			max = a[i];
	}
	
	// 출력
	cout << max;
	return 0;
}