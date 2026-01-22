#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
bool visited[8];
vector<int> v;

void BT(int len) { // BackTracking
	// break point
  if (len == m) {
    for (int i = 0; i < m; i++)
      cout << arr[i] << " ";
    cout << "\n";
    return;
  }

  for (int i = 0; i < n; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    arr[len] = v[i];
    BT(len + 1);
    visited[i] = false; // 반납 
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());
  BT(0);
  return 0;
}
