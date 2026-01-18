#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int, int>> res;
int n, ans;

void hanoi(int n, int from, int to, int via) {
	if(n == 1) {
		ans++;
		res.push_back({from, to});
	} else {
		hanoi(n-1, from, via, to);
		ans++;
		res.push_back({from, to});
		hanoi(n-1, via, to, from);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int from = 1; int via = 2; int to = 3;
	cin >> n;
	hanoi(n, from, to, via);
	cout << ans << "\n";
	for(auto p : res) cout << p.first << " " << p.second << "\n";
	return 0;
}