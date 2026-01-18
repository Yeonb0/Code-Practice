#include <iostream>
#include <vector>
using namespace std;

struct Node {
  char data;
  char left;
  char right;
};

vector<Node> t(26); 

void pre_order(char cur) {
  if (cur == '.') return;
  cout << cur;
  pre_order(t[cur - 'A'].left);
  pre_order(t[cur - 'A'].right);
}

void in_order(char cur) {
  if (cur == '.') return;
  in_order(t[cur - 'A'].left);
  cout << cur;
  in_order(t[cur - 'A'].right);
}

void post_order(char cur) {
  if (cur == '.') return;
  post_order(t[cur - 'A'].left);
  post_order(t[cur - 'A'].right);
  cout << cur;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char p, l, r;
    cin >> p >> l >> r;
    t[p - 'A'] = {p, l, r};
  }

  pre_order('A');
  cout << "\n";
  in_order('A');
  cout << "\n";
  post_order('A');
  cout << "\n";
  return 0;
}
