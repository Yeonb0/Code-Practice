#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	
	int ans = 0;
	int count = 0;
	
	for(int i = 1; i < m-1; i++) {
		if(s[i-1] == 'I' && s[i] == 'O' && s[i+1] == 'I') {
			count++;
			i++; // O 다음으로 이동
		} else {
			count = 0;
		}
		if(count >= n) ans++; // 중복 처리
	}

	cout << ans;
	
	return 0;
}