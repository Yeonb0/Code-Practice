#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int A, P; 
vector<int> visited(300000, 0);

void dfs(int a) {
	if(visited[a] == 3) return;
	visited[a]++;
	
	int next = 0;
	while(a) {
		next += pow((a % 10), P);
		a /= 10;
	}
	dfs(next);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> P;
	dfs(A);
	int ans = 0;
	for(int i = 1; i <= 300000; i++) {
		if (visited[i] == 1) ans++;
	}
	cout << ans;
	return 0;
}