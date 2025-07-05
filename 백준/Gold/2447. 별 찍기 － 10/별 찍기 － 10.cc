#include <iostream>
using namespace std;

char star[6561][6561];

void draw(int x, int y, int size) {
  if (size == 1) {
    star[x][y] = '*';
    return;
  }

  int div = size / 3;
  for (int dx = 0; dx < 3; dx++) {
    for (int dy = 0; dy < 3; dy++) {
      if (dx == 1 && dy == 1) {
        // 가운데 공백
        for (int i = x + div; i < x + 2 * div; i++) {
          for (int j = y + div; j < y + 2 * div; j++) {
            star[i][j] = ' ';
          }
        }
      } else {
        draw(x + dx * div, y + dy * div, div);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  // 초기화
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      star[i][j] = ' ';

  draw(0, 0, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << star[i][j];
    cout << '\n';
  }

  return 0;
}