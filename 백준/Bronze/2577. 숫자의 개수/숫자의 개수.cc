#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// 입력
	int a, b, c;
	cin >> a >> b >> c;
	string result = to_string(a*b*c); // 문자열로 만들기
	int n[10] = {0};
	
	// 숫자 갯수 세기
	for(char a : result){
		n[a - '0']++; 
	}
	
	// 출력
	for(int j = 0; j < 10; j++)
		cout << n[j] << " ";
	
	return 0;
}