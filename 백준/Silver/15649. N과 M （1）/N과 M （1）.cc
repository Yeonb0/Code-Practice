#include <iostream>
using namespace std;

int n, m;
bool visited[8];
int S[8];

void backtracking(int len) {
	if(len == m) {
		for(int i = 0; i < m; ++i) {
			cout << S[i] + 1 << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int i = 0; i < n; ++i) {
		if(!visited[i]) {
			visited[i] = true; // 방문 체크
			S[len] = i; // 수열에 수 사용 
			backtracking(len + 1);
			visited[i] = false; // 수 반납
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	backtracking(0);
}