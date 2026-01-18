#include <iostream>
using namespace std;
// DP 테이블
int dp[5001];
int MOD = 1000000;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string num;
  cin >> num;  
	int a[num.size()+1];  // 배열 크기 설정
  // 각 자리 숫자를 배열에 저장
  a[0] = 0;
  for (int i = 1; i <= num.size(); i++) {
	  a[i] = num[i-1] - '0';  // char로 받은 숫자를 정수로 변환
  }
  if((num.size() == 0) || (a[1] == 0)) {
	  cout << 0;
	  return 0;
	}
	dp[0] = 1; dp[1] = 1;
	int temp;
	for(int i = 2; i <= num.size(); i++) {
		if(a[i] >= 1 && a[i] <= 9) 
			dp[i] = (dp[i-1] + dp[i]) % MOD;
		temp = (a[i-1]*10) + a[i];
		if(temp >= 10 && temp <= 26) 
			dp[i] = (dp[i-2] + dp[i]) % MOD;
	}
	cout << dp[num.size()];
	return 0;
}