#include <iostream>
#include <algorithm>
using namespace std;
// DP 테이블
int a[100001];
int dp[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[1] = a[1];
    int ans = dp[1];  // 초기값
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1] + a[i], a[i]); 
        ans = max(ans, dp[i]); 
    }
    cout << ans << "\n";
    return 0;
}
