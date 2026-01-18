#include <iostream>
using namespace std;

long long RC(int n, int r, int c) {
  if (n == 0) return 0;

  int half = 1 << (n - 1); // 2^(n-1)
  long long block = 1LL << (2 * n - 2);  // 한 사분면의 크기: half * half

  // 0번 사분면 (좌상)
  if (r < half && c < half)
    return RC(n - 1, r, c);
  // 1번 사분면 (우상)
  if (r < half && c >= half)
    return block + RC(n - 1, r, c - half);
  // 2번 사분면 (좌하)
  if (r >= half && c < half)
    return 2 * block + RC(n - 1, r - half, c);
  // 3번 사분면 (우하)
  return 3 * block + RC(n - 1, r - half, c - half);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, r, c;
  cin >> N >> r >> c;

  cout << RC(N, r, c);
  return 0;
}
