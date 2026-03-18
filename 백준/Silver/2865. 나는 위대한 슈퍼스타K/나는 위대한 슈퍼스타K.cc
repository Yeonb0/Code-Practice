#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

float score[101];
bool vis[101];
float ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int person;
			float sco;
			cin >> person >> sco;
			score[person] = max(score[person], sco);
		}
	}
	
	sort(score + 1, score + n + 1);
	
	for(int i = n; i > n - k; i--) {
		ans += score[i];
	}
    
    cout << fixed;
    cout.precision(1);        
	cout << ans;
	
	return 0;
}