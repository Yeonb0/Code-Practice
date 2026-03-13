#include <iostream>
#include <algorithm>
using namespace std;

int A[100001];
int L[100001];
int R[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> A[i];
	}
	
	int ans = A[0];
	
	// L[i] 구하기
	L[0] = A[0];
	for(int i = 1; i < n; i++) {
		L[i] = max(A[i], L[i - 1] + A[i]);
		ans = max(ans, L[i]);
	}
	
	// R[i] 구하기
	R[n - 1] = A[n - 1];
	for(int i = n-2; i >= 0; i--) {
		R[i] = max(A[i], R[i + 1] + A[i]);
		ans = max(ans, R[i]);
	}
	
	// 최댓값 구하기
	for(int i = 1; i < n - 1; i++) {
		int tmp = L[i - 1] + R[i + 1];
		ans = max(ans, tmp);
	}
	
	cout << ans;
	return 0;
}