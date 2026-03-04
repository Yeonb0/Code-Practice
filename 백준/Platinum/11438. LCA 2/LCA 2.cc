#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
vector<vector<int>> tree;
int depth[100001];
bool visit[100001];
int parent[21][100001];
int kmax; // 최대 가능 깊이

void BFS(int node);
int LCA(int a, int b);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	tree.resize(n + 1);
	
	for(int i = 0; i < n - 1; i++) { // edge 입력 받기
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	int temp = 1;
	while(temp <= n) {
		temp <<= 1; // temp * 2
		kmax++;
	}
	
	BFS(1); // 깊이 & 바로 위 부모 구하기
	
	for(int k = 1; k <= kmax; k++) { // 점화식 이용 부모 배열 채우기
		for(int i = 1; i <= n; i++) {
			parent[k][i] = parent[k - 1][parent[k - 1][i]];
		}
	}
	
    int m;
	cin >> m;
	for(int i = 0; i < m; i++) { // lca 쌍 입력
		int a, b;
		cin >> a >> b;
		int ans = LCA(a, b);
		cout << ans << "\n";
	}
	return 0;
}

void BFS(int node) { // 깊이 & 바로 위 부모 저장
	queue<int> q;
	q.push(node);
	visit[node] = true;
	int level = 1;
	int now_size = 1; // level 별 size -> q.size() 로 계산
	int count = 0; // now_size == count 면 다음 level 로
		
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for(int next : tree[now]) {
			if(!visit[next]) {
				visit[next] = true;
				q.push(next);
				parent[0][next] = now; // 부모 노드 저장
				depth[next] = level;
			}
		}
		count++;
		if(count == now_size) {
			now_size = q.size();
			level++;
			count = 0;
		}
	}
}

int LCA(int a, int b) {
	// b 가 더 깊도록 변경
	if(depth[a] > depth[b]) {
		int temp = b;
		b = a;
		a = temp;
	}
	for(int k = kmax; k >= 0; k--) { // 깊이 빠르게 맞추기
		if(pow(2, k) <= depth[b] - depth[a]) { // 깊이 차이가 크면
			if(depth[a] <= depth[parent[k][b]]) {
				b = parent[k][b];
			}
		}
	}
	for(int k = kmax; k >= 0 && a != b; k--) { // 조상 빠르게 찾기
		if(parent[k][a] != parent[k][b]) {
			a = parent[k][a]; 
			b = parent[k][b];
		}
	}
	int ret = a;
	if(a != b) {
		ret = parent[0][ret];
	}
	return ret;
}	