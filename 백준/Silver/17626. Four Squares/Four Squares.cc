#include <iostream>
#include <algorithm>
using namespace std;

int DP[50001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    DP[i] = i; // 최악의 경우: 1^2을 i번 더한 경우
    for (int j = 1; j * j <= i; j++) {
      DP[i] = min(DP[i], DP[i - j * j] + 1);
    }
  }

  cout << DP[n];
  return 0;
}
