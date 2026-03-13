#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string a, b;
int DP[1001][1001];
vector<char> ans;

void LCS(int alen, int blen) {
	if(alen == 0 || blen == 0) return;
	if(a[alen-1] == b[blen-1]) { // 같으면 정답 추가 + 왼쪽 위 이동
		ans.push_back(a[alen-1]);
		LCS(alen-1, blen-1);
	} else { // 다르면 큰 수로 이동
		if(DP[alen-1][blen] > DP[alen][blen-1]) {
			LCS(alen-1, blen);
		} else {
			LCS(alen, blen-1);
		}
	}
}		

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b;
	
	for(int i = 1; i <= a.size(); i++) {
		for(int j = 1; j <= b.size(); j++) {
			if(a[i-1] == b[j-1]) { // 같은 문자
				DP[i][j] = DP[i-1][j-1] + 1;
			} else { // 다른 문자
				DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
			}
		}
	}
    
    LCS(a.size(), b.size());
	
	cout << DP[a.size()][b.size()] << "\n";
	for(int i = ans.size()-1; i >= 0; i--) {
		cout << ans[i];
	}
	
	return 0;
}