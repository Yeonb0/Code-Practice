#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v;
	int n, m, num;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	for(int i = 0; i < m; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for(int k : v) cout << k << " ";
	return 0;
}