#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int c;
		cin >> c;
        map<string, int> m;
		for(int i = 0; i < c; i++) {
			string name, kind;
			cin >> name >> kind;
			m[kind]++;
		}
		int cnt = 1;
		for(auto a : m) {
			cnt *= (a.second + 1); // 입지 않는 것 포함
		}
		cout << --cnt << "\n";
	}
	return 0;
}