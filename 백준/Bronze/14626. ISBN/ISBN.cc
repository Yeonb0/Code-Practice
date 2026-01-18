#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string isbn;
  cin >> isbn;

  int star_index = -1;
  int sum = 0;

  for (int i = 0; i < 13; i++) {
    if (isbn[i] == '*') {
      star_index = i;
      continue;
    }

    int digit = isbn[i] - '0';
    if (i % 2 == 0) sum += digit;
    else sum += digit * 3;
  }

  for (int x = 0; x <= 9; x++) {
    int temp_sum = sum;
    if (star_index % 2 == 0)
      temp_sum += x;
    else
      temp_sum += x * 3;

    if (temp_sum % 10 == 0) {
      cout << x << '\n';
      break;
    }
  }

  return 0;
}
