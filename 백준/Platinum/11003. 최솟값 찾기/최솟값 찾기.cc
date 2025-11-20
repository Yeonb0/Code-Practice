#include <iostream>
#include <utility>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, L;
	cin >> N >> L;
	deque<pair<int, int>> D;
	
	for(int i = 0; i < N; i++) {
		int now; 
		cin >> now;
		while(!D.empty() && D.back().first > now) { 
			D.pop_back();
		}
		D.push_back({now, i});
		if(D.front().second <= i-L) { // 범위 벗어나면
			D.pop_front();
		}
		cout << D.front().first << " ";
	}
	return 0;
}