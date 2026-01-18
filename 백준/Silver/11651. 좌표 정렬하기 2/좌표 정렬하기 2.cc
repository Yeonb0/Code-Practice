#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

pair<int, int> p;
vector<pair<int, int>> v;
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), compare);
	for(int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}