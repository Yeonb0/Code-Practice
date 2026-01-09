#include <iostream>
#include <vector>
using namespace std;

int fruit[10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> A(n);
  for(int i = 0; i < n; i++) {
    cin >> A[i];
  }

  int start = 0;
  int kind = 0;
  int Max = 0;

  for(int end = 0; end < n; end++) {
    if(fruit[A[end]] == 0) kind++;
    fruit[A[end]]++;

    while(kind > 2) { // 과일 종류 3개 이상이면 start 땡기기
      fruit[A[start]]--;
      if(fruit[A[start]] == 0) kind--;
      start++;
    }

    Max = max(Max, end - start + 1);
  }

  cout << Max;
}
