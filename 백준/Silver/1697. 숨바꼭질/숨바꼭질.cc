#include <iostream>
#include <queue>
using namespace std;

int dist[100001];
bool visited[100001];
queue<int> q;
int n, k;

void BFS(int n) {
	q.push(n);
	visited[n] = true;
	dist[n] = 0;
	
	while(!q.empty()) {
		int now = q.front();
		q.pop();
	
		if(now == k) {
			cout << dist[now];
			return;
		}
		int nexts[3] = {now - 1, now + 1, now * 2};
		for(int nx : nexts) {
			if(nx < 0 || nx > 100000) continue;
			if(!visited[nx]) {
				visited[nx] = true;
				q.push(nx);
				dist[nx] = dist[now] +1;
			}
		}
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  BFS(n);
}
