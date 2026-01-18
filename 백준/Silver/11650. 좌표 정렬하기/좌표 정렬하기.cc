#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	pair<int, int> p;
	vector<pair<int, int>> v;
	int a, b;
    
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}