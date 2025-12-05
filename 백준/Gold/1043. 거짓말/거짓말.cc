#include <iostream>
#include <vector>
using namespace std;

vector<int> party[51];
int parent[51];
vector<int> tp;
int ans;

int find(int a) {
	if(parent[a] == a) return a;
	else return find(parent[a]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	
	if(a != b) parent[b] = a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++) {
		int per;
		cin >> per;
		tp.push_back(per);
	}
	
	for(int i = 0; i < m; i++) { // 파티 정보 저장
		int a;
		cin >> a;
		for(int j = 0; j < a; j++) {
			int now;
			cin >> now;
			party[i].push_back(now);
		}
	}
	
	for(int i = 0; i <= n; i++) parent[i] = i;
	
	for(int i = 0; i < m; i++) { // 파티끼리 union
		int fp = party[i][0];
		for(int j = 1; j < party[i].size(); j++) {
			uni(fp, party[i][j]);
		}
	}
	
	for(int i = 0; i < m; i++) {
		bool pos = true;
		int cur = party[i][0];
		for(int j = 0; j < k; j++) {
			if(find(cur) == find(tp[j])) {
				pos = false;
				break;
			}
        }
        if(pos) ans++;
	}
	cout << ans;
	return 0;
}