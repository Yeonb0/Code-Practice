#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; i++) {
    cin >> A[i];
  }

  vector<int> sorted = A;
  sort(sorted.begin(), sorted.end());
  sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end()); // 중복 제거

  for(int i : A) {
    auto it = lower_bound(sorted.begin(), sorted.end(), i); // 정렬된 위치
    cout << it - sorted.begin() << " ";
  }
  return 0;
}
