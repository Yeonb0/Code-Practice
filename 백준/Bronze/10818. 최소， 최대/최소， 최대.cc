#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int max = nums.front(), min = nums.front();
	for (int i = 1; i < n; i++) {
		if (min > nums[i]) min = nums[i];
		if (max < nums[i]) max = nums[i];
	}
	cout << min << " " << max;
	
	return 0;
}