#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath> 
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> v;
  unordered_map<int, int> m;
  int tot = 0;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    tot += num;
    v.push_back(num);
    m[num]++;
  }

  sort(v.begin(), v.end());

  // 평균 
  cout << (int)round((double)tot / n) << "\n";

  // 중앙값
  cout << v[n / 2] << "\n";

  // 최빈값
  int maxFreq = 0;
  for (auto &p : m) {
    if (p.second > maxFreq) {
      maxFreq = p.second;
    }
  }

  vector<int> modes;
  for (auto &p : m) {
    if (p.second == maxFreq) {
      modes.push_back(p.first);
    }
  }
  sort(modes.begin(), modes.end());
  if (modes.size() > 1) {
    cout << modes[1] << "\n";
  } else {
    cout << modes[0] << "\n";
  }

  // 범위
  cout << v.back() - v.front() << "\n";

  return 0;
}
