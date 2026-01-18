#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	unordered_set<int> s;
	int n, m, num;
	cin >> n;
	while(n--) {
		cin >> num;
		s.insert(num);
	}
	
	cin >> m;
	while(m--) {
		cin >> num;
		cout << s.count(num) << " ";
	}
	return 0;
}