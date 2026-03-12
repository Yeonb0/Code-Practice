#include <iostream>
#include <queue>
using namespace std;

int a, b;
int ans;

void BFS(int b, int cnt) {
  queue<pair<int, int>> q;
  q.push({b, cnt});
  
  while(!q.empty()) {
    int now = q.front().first;
    int count = q.front().second;
    q.pop();
    
    if(now == a) {
      ans = count;
      return;
    }
    
    if(now < a) {
	    ans = -1;
	    return;
	  }
    
    if(now % 10 == 1) {
      q.push({now / 10, count + 1});
    } else if(now % 2 == 0) {
      q.push({now / 2, count + 1});
    } else {
      ans = -1;
      return;
    }
  }
  
  ans = -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> a >> b;
  
  if(a > b) ans = -1;
  else BFS(b, 1);
  
  cout << ans;
  return 0;
}