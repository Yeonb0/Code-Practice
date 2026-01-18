#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int a, b, v;
  cin >> a >> b >> v;

  int day = (v - b - 1) / (a - b) + 1;
  cout << day;

  return 0;
}
