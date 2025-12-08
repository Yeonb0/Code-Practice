#include <iostream>
#include <set>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int T;
  cin >> T;
  while(T--) {
    multiset<long> ms;
    int k;
    cin >> k;
    while(k--) {
      char m;
      long n;
      cin >> m >> n;
      if(m == 'I') {
        ms.insert(n);
      } else {
        if(!ms.empty()) {   // 비어있으면 삭제 명령 무시
          if(n == 1) ms.erase(prev(ms.end()));
          else ms.erase(ms.begin());
        }
      }
    }
    if(ms.empty()) cout << "EMPTY\n";
    else cout << *ms.rbegin() << " " << *ms.begin() << "\n";
  }
  return 0;
}
