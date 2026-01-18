#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	unordered_set<int> set(0);
	cin >> n;
	
	while(n--) {
		int num;
		cin >> num;
		set.insert(num);
	}
	
	cin >> m;
	while(m--) {
		int f_num;
		cin >> f_num;
		cout << set.count(f_num) << "\n";
	}
	return 0;
}