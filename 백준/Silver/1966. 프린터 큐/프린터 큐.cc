#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
        // 입력
		int num, k;
		cin >> num >> k;
		queue<pair<int, int>> q;
		int ans = 0;
		int arr[10] = {0, };
		for(int i = 0; i < num ; i++) {
			int pri;
			cin >> pri;
			q.push({i, pri});
			arr[pri]++;
		}
        // 프린터 큐
		bool found = false;
		for(int i = 9; i >= 1; i--) {
			int count = arr[i];
			while(count != 0) {
				auto fr = q.front();
				if(fr.second == i) {
					count--;
					q.pop();
					ans++;
					if(fr.first == k) {
					found = true;
					break;
					}
				} else {
					q.pop();
					q.push(fr);
				}
			}
			if(found) break;
		}
		cout << ans << "\n";
	}
	return 0;
}