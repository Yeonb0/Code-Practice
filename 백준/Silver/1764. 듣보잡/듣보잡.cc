#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

set<string> lis;
set<string> see;
vector<string> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	string name;
	cin >> n >> m;
	while (n--) {
		cin >> name;
		lis.insert(name);
	}
	while (m--) {
		cin >> name;
		see.insert(name);
	}
	set_intersection(lis.begin(), lis.end(), see.begin(), see.end(), back_inserter(ans));
	cout << ans.size() << "\n";
	for(string na : ans) {
		cout << na << "\n";
	}
	return 0;
}