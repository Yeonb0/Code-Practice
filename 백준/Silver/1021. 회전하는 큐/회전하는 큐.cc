#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	deque<int> d;
	vector<int> v(m);
	int count = 0;
	for (int i = 1; i <= n; i++) d.push_back(i);
	for (int i = 0; i < m; i++) cin >> v[i];
	for (int i = 0; i < m; i++) {
		while (true) {
			// 처음이 바로 찾는 숫자면
			if (d.front() == v[i]) {
				d.pop_front();
				break;
			}
			// 아니면
			// 찾는 위치 인덱스 찾기
			int pos = find(d.begin(), d.end(), v[i]) - d.begin();
			if (pos <= d.size()/2) { // 2번 사용
				d.push_back(d.front());
				d.pop_front();
				count++;
			} else { // 3번 사용
				d.push_front(d.back());
				d.pop_back();
				count++;
			}
		}
	}
	cout << count;
	return 0;
}