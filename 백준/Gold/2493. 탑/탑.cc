#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> tower(n);
  vector<int> ans(n, 0);
  stack<pair<int, int>> st; // 높이 & 위치

  for(int i = 0; i < n; i++) {
    cin >> tower[i];
    while(!st.empty() && st.top().first < tower[i]) {
      st.pop(); // 낮으면 pop
    }
    if(!st.empty()) {
      ans[i] = st.top().second + 1; 
    }
    st.push({tower[i], i});
  }

  for(int i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
}
