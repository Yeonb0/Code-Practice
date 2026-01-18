#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> map;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	int num;
	cin >> n;
	while(n--) {
		cin >> num;
		map[num]++; // 없으면 생성
	}
	cin >> m;
	while(m--) {
		cin >> num;
		cout << map[num] << " ";
	}
	return 0;
}