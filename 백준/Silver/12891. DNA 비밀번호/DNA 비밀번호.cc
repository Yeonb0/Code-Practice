#include <iostream>
#include <string>
using namespace std;

int a, c, g, t;
int aa = 0, cc = 0, gg = 0, tt = 0;
int cnt = 0;
int S, P;
string dna;

void Add(char c) {
  if (c == 'A') aa++;
  else if (c == 'C') cc++;
  else if (c == 'G') gg++;
  else if (c == 'T') tt++;
}

void Remove(char c) {
  if (c == 'A') aa--;
  else if (c == 'C') cc--;
  else if (c == 'G') gg--;
  else if (c == 'T') tt--;
}

void Check() {
  if (aa >= a && cc >= c && gg >= g && tt >= t)
    cnt++;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> S >> P;
  cin >> dna;
  cin >> a >> c >> g >> t;

  // 초기 윈도우 설정
  for (int i = 0; i < P; i++) {
    Add(dna[i]);
  }

  Check();

  // 슬라이딩 윈도우
  for (int i = P; i < S; i++) {
    Remove(dna[i - P]);
    Add(dna[i]);
    Check();
  }

  cout << cnt;
  return 0;
}
