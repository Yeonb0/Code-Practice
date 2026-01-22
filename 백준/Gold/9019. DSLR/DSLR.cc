#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int a, b, Min;
bool vis[10001];
string ans[10001];

void bfs(int s, int e) {
	queue<int> q;
	q.push(s);
	vis[s] = true;
	ans[s] = "";
	
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		
		if(now == e) {
			cout << ans[now] << "\n";
			return;
		} else {
			// D
			int d = (now * 2) % 10000;
			if(!vis[d]) {
			  vis[d] = true;
			  q.push(d);
			  ans[d] = ans[now] + "D";
			}
			
			// S
			int s = (now + 9999) % 10000;
			if(!vis[s]) {
			  vis[s] = true;
			  q.push(s);
			  ans[s] = ans[now] + "S";
			}
			
			// L
			int l = (now % 1000) * 10 + (now / 1000);
			if(!vis[l]) {
			  vis[l] = true;
			  q.push(l);
			  ans[l] = ans[now] + "L";
			}
			
			// R
			int r = (now % 10) * 1000 + (now / 10);
			if(!vis[r]) {
			  vis[r] = true;
			  q.push(r);
			  ans[r] = ans[now] + "R";
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		fill(vis, vis+10001, false);
		fill(ans, ans+10001, "");
		bfs(a, b);
	}
}