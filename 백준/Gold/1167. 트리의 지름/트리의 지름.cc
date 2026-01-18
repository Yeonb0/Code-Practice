#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v[100001];
vector<bool> visit(100001, false);
int n, k;
int dis;

void dfs(int a, int cur) {
	visit[a] = true;
	if(dis < cur) {
		k = a;
		dis = cur;
	}
	for(auto node : v[a]) {
		if(!visit[node.first]) {
			dfs(node.first, cur+node.second);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) { // 트리 입력
		int node, link, len;
        cin >> node;
		while(true) {
			cin >> link;
			if(link == -1) break;
            cin >> len;
			v[node].push_back({link, len});
		}
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++) visit[i] = false;
	dis = 0;
	dfs(k, 0);
	cout << dis;
	return 0;
}