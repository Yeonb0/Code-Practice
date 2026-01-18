#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> A(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int i = 0, j = n-1;
	int count = 0;
	while(i < j) {
		if(A[i] + A[j] > m) j--;
		else if(A[i] + A[j] < m) i++;
		else {
			count++; i++; j--;
		}
	}
	cout << count;
	return 0;
}