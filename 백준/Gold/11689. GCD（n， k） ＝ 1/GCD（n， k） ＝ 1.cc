#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long n;
	cin >> n;
	long ans = n;
	
	for(long i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) { // 소인수면
			ans -= ans / i; // 답 줄이기
			while(n % i == 0) n /= i; // 소인수 지우기
		}
	}
	
	if(n > 1) ans -= ans / n;
	cout << ans;	
}