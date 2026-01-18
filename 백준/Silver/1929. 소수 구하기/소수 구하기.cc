#include <iostream>
using namespace std;

bool num[1000001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int s, e;
  cin >> s >> e;
  num[0] = num[1] = true;
  for (int i = 2; i * i <= e; i++) {
    if (num[i]) continue;
    for (int j = i * i; j <= e; j += i) {
      num[j] = true; 
    }
  }
  for (int i = s; i <= e; i++) {
    if (!num[i]) cout << i << "\n";
  }
  return 0;
}