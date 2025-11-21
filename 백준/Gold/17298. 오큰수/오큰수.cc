#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> arr(n);
  vector<int> ans(n, -1); // 기본값 -1 로
  stack<int> st; // index stack

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] < arr[i]) {
      ans[st.top()] = arr[i];
      st.pop();
    }
    st.push(i);
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
