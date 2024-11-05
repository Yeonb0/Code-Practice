#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// 입력
	string a, b;
	int ca[26] = {0}, cb[26] = {0};
	int d = 0;
	cin >> a >> b;
	
	// 알파벳 갯수 저장
	for(char ch : a)
		ca[ch - 'a']++;
	for(char ch : b)
		cb[ch - 'a']++; // b가 아니라 a
	
	// 비교 후 삭제 할 갯수 구하기
	for(int i = 0; i < 26; i++){
		if(ca[i] > cb[i])
			d += ca[i] - cb[i];
		else if(ca[i] < cb[i])
			d += cb[i] - ca[i];
	}
	
	// 출력
	cout << d;
	
	return 0;
}