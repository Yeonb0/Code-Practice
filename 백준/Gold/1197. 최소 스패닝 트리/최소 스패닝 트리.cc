#include <iostream>
#include <queue>
using namespace std;

int p[10001];
typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}
} Edge;

int find(int a) {
	if(p[a] == a) return a;
	else return p[a] = find(p[a]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if(a != b) {
		p[b] = a;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	for(int i = 0; i <= n; i++) p[i] = i;
	for(int i = 0; i < m; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		pq.push(Edge{s, e, v});
	}
	
	int used = 0;
	int ans = 0;
	
	while(used < n-1) {
		Edge now = pq.top();
		pq.pop();
		// Cycle Check
		if(find(now.s) != find(now.e)) { // 사이클이 아니면 연결
			uni(now.s, now.e);
			ans += now.v;
			used++;
		}
	}
	cout << ans;
}