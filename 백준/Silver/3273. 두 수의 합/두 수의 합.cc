#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// 입력
	int a[2000001] = {0}; // 가능한 모든 수의 배열
	int n; // 배열 길이
	cin >> n;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		a[num]++;
	}
	int x; // 합 입력
	cin >> x;
	int p = 0; // 합의 쌍
	
	// 쌍 찾기
	for(int i = 1; i < (x+1)/2; i++){
		if(a[i] == 1 && a[x-i] == 1) p++;
	}
	
	// 출력 
	cout << p;
	
	return 0;
}