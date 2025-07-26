#include <iostream>
#include <utility>
using namespace std;

pair<int, int> p[50];

bool bigger(pair<int, int> a, pair<int, int> b) {
  return a.first > b.first && a.second > b.second;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }

  for (int i = 0; i < n; i++) {
    int ans = 1;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (bigger(p[j], p[i])) {
        ans++;
      }
    }
    cout << ans << " ";
  }
  return 0;
}
