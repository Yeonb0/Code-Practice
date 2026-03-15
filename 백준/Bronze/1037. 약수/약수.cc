#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int num;
	cin >> num;
	
	vector<int> factor;
	
	for (int i = 0; i < num; i++) {
		int f;
		cin >> f;
		factor.push_back(f);
	}
	
	sort(factor.begin(), factor.end());
	
	if (factor.size() % 2 == 0) { // 짝수면
		cout << factor.front() * factor.back();
	} else { // 홀수면
		int mid = factor.size() / 2;
		cout << factor[mid] * factor[mid];
	}
	
	return 0;
}