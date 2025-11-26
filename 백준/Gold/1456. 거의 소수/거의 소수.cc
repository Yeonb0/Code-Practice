#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long a, b;
	cin >> a >> b;
	long A[10000001];
	
	for(int i = 2; i < 10000001; i++) A[i] = i;
	for(int i = 2; i <= sqrt(10000001); i++) { // 에라토스테네스 체
		if(A[i] == 0) continue;
		for(int j = i + i; j < 10000001; j += i) A[j] = 0;
	}
	
	int ans = 0;
	
	for(int i = 2; i < 10000001; i++) {
		if(A[i] != 0) { // 소수면
			long temp = A[i];
			
			while((double)A[i] <= (double)b / (double)temp) {
				if((double)A[i] >= (double)a / (double)temp) {
					ans++;
				}
				temp *= A[i];
			}
		}
	}
	cout << ans;
	return 0;
}