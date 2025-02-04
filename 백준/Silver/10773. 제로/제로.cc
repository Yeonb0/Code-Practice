#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k, n;
	int sum = 0;
	stack<int> stack;
	cin >> k;
	
	// 스택 쌓기
	while(k--) {
			cin >> n;
			if (n) stack.push(n);
			else stack.pop();
	}
	
	// 더하기
	while(!stack.empty()) {
			sum += stack.top();
			stack.pop();
	}
	cout << sum;
	
	return 0;
}