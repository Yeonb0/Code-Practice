#include <iostream>
#include <queue>
using namespace std;

int p[51];
int sum;
typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}
} Edge;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

int find(int a) {
	if(p[a] == a) return a;
	else return p[a] = find(p[a]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if(a != b) p[b] = a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			char c;
			cin >> c;
			int tmp = 0;
			if(c >= 'a' && c <= 'z') {
				tmp = c - 'a' + 1;
			} else if(c >= 'A' && c <= 'Z') {
				tmp = c - 'A' + 27;
			}
			sum += tmp;
			if(i != j && tmp != 0) pq.push({i, j, tmp});
		}
	}
	
	for(int i = 0; i < n; i++) p[i] = i;
	int used = 0;
	int ans = 0;
	
	while(!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		
		if(find(now.s) != find(now.e)) { // 사이클 X라면
			uni(now.s, now.e);
			ans += now.v;
			used++;
		}
	}
	if(used == n-1) cout << sum - ans;
	else cout << -1;
	return 0;
}