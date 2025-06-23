#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, x;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x;
        v.push_back(x);
	} 
	sort(v.begin(), v.end());
	cout << v[k-1];
	return 0;
}