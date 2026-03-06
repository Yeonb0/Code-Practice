#include <iostream>
using namespace std;

int A[51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int m;
	cin >> m;
	
	int total = 0;
    double ans = 0.0;
	for(int i = 0; i < m; i++) {
		cin >> A[i];
		total += A[i];
	}
	
	int k;
	cin >> k;
	
	for(int i = 0; i < m; i++) {
		double prob = 0.0;
		
		if(A[i] >= k) {
			prob = 1.0;
			for(int j = 0; j < k; j++) {
				prob *= (double)(A[i] - j) / (total - j);
			}
			ans += prob;
		}
	}
    cout.precision(15); // 소수점 15번째까지 출력
	cout << ans; 
	return 0;
}