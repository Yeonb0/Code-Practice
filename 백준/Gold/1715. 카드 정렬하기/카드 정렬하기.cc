#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	int data;
	
	for(int i = 0; i < n; i++) {
		cin >> data;
		pq.push(data);
	}
	
	int a;
	int b;
	int sum = 0;
	
	while(pq.size() != 1) {
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		sum += a+b;
		pq.push(a+b);
	}
	cout << sum;
	return 0;
}