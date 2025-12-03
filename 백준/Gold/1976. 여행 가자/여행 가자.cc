#include <iostream>
#include <vector>
using namespace std;

int c[201][201];
int p[201];

int find(int a) {
	if(a == p[a]) return a;
	else return(find(p[a]));
}

void uni(int a, int b) {
	 a = find(a);
	 b = find(b);
	 if(a != b) p[b] = a;
}

bool check(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) { 
		for(int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	int route[1001];
	for(int i = 1; i <= m; i++) cin >> route[i];
	
	for(int i = 1; i <= n; i++) p[i] = i;
	
	for(int i = 1; i <= n; i++) { 
		for(int j = 1; j <= n; j++) {
			if(c[i][j] == 1) {
				uni(i, j);
			}
		}
	}
	
	int ch = find(route[1]);
	bool ans = true;
	
	for(int i = 2; i <= m; i++) {
		if(ch != find(route[i])) {
			cout << "NO";
			ans = false;
			break;
		}
	}
	if(ans) cout << "YES";
	return 0;
}