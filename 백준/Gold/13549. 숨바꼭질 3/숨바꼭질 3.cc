#include <iostream>
#include <deque>
#include <limits.h>
using namespace std;

int n, k;
int dist[100001];
int ans;

void bfs(int n) {
	deque<int> dq;
	dq.push_front(n);
	
	while(!dq.empty()) {
		auto cur = dq.front();
		dq.pop_front();
		
		if (cur == k) {
			ans = dist[cur];
			return;
		}
		
		if (cur*2 <= 100000 && dist[cur*2] > dist[cur]) {
			dist[cur*2] = dist[cur];
			dq.push_front(cur*2);
		}
		if (cur+1 <= 100000 && dist[cur+1] > dist[cur]+1) {
			dist[cur+1] = dist[cur] + 1;
			dq.push_back(cur+1);
		}
		if (cur-1 >= 0 && dist[cur-1] > dist[cur]+1) {
			dist[cur-1] = dist[cur] + 1;
			dq.push_back(cur-1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	fill(dist, dist+100001, INT_MAX);
	dist[n] = 0;
	
	bfs(n);
	cout << ans;
	
	return 0;
}