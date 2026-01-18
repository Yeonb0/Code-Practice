#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[101];
bool chk[101];
int ans = 0;

void dfs(int cur) {
	for(int nex : adj[cur]) {
		if(chk[nex]) continue;
		else {
			ans++; 
			chk[nex] = true;
			dfs(nex);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, v;
	cin >> n >> v;
	while(v--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
    chk[1] = true;
	dfs(1);
	cout << ans;
	return 0;
}