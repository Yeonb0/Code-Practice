#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
unordered_map<string, string> map;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while(n--) {
		string site, pw;
		cin >> site >> pw;
		map[site] = pw;
	}
	while(m--) {
		string find;
		cin >> find;
		cout << map[find] << "\n";
	}
	return 0;
}