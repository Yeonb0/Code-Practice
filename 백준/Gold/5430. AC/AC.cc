#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    string func;
    cin >> func;

    int n;
    cin >> n;

    deque<int> D;

    char ch;
    cin >> ch; // '['

    if (n == 0) {
      cin >> ch; // ']'
    } else {
      for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        D.push_back(x);
        cin >> ch; // ',' 또는 ']'
      }
    }

    bool Front = true;
    bool Error = false;

    for (char op : func) {
      if (op == 'R') {
        Front = !Front;
      } else { // 'D'
        if (D.empty()) {
          Error = true;
          break;
        }
        if (Front) D.pop_front();
        else D.pop_back();
      }
    }

    if (Error) {
      cout << "error\n";
      continue;
    }

    cout << "[";
    if (!D.empty()) {
      if (Front) {
        for (int i = 0; i < D.size(); i++) {
          if (i) cout << ",";
          cout << D[i];
        }
      } else {
        for (int i = D.size() - 1; i >= 0; i--) {
          if (i != D.size() - 1) cout << ",";
          cout << D[i];
        }
      }
    }
    cout << "]\n";
  }
  return 0;
}