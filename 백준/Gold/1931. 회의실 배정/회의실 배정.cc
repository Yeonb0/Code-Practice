#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
	 int st, en;
	 cin >> st >> en;
	 v.push_back({en, st});
	}
	sort(v.begin(), v.end()); // 끝나는 시간 이른 순
    int ans = 0, t = 0;
	for(int i = 0; i < n; i++) {
		if(t > v[i].second) continue; // 이미 진행중인 회의면 패스
		ans++;
		t = v[i].first; // 회의 끝나는 시간으로 설정
	}
	cout << ans;
	return 0;
}