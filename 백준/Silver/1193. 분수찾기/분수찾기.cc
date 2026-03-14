#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  int cnt = 1;
  
  while(1) {
    if(n - cnt > 0) {
      n -= cnt;
      cnt++;
    }
    else break;
  }
  
  int up, down;
  
  if(cnt % 2 == 0) {
    up = n;
    down = cnt - n + 1;
  }
  else {
    up = cnt - n + 1;
    down = n;
  }
  
  cout << up << "/" << down;
  return 0;
}