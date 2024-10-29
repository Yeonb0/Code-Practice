#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// 입력
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int s;
	cin >> s;
	
	// s 나온 횟수 세기
	int c = 0;
	for(int i = 0; i < n; i++)
		if(a[i] == s) c++;
		
	// 출력
	cout << c;
	
	return 0;
}