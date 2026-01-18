#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int zero;
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<int> pl; 
  vector<int> mi; 

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if (num > 0) pl.push_back(num);
    else if (num == 0) zero++;
    else mi.push_back(num);
  }

  sort(pl.begin(), pl.end(), greater<>()); // 큰 수부터
  sort(mi.begin(), mi.end()); // 작은 수부터

  long long sum = 0;

  for (int i = 0; i + 1 < pl.size(); i += 2) {
    if (pl[i] == 1 || pl[i+1] == 1) {
      sum += pl[i] + pl[i+1];
    } else {
      sum += pl[i] * pl[i+1];
    }
  }
  if (pl.size() % 2 == 1) {
    sum += pl.back();
  }

  for (int i = 0; i + 1 < mi.size(); i += 2) {
    sum += mi[i] * mi[i+1];
  }
  if (mi.size() % 2 == 1) {
    if (zero == 0) sum += mi.back();
  }

  cout << sum;
  return 0;
}
