#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n != 0) pq.push(n);
		else {
			if(pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}
	return 0;		
}