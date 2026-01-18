#include <iostream>
#include <string>
using namespace std;

char arr[5][15] = { };

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 5; i++) {
    string line;
    getline(cin, line);
    for (int j = 0; j < line.size(); j++) {
      arr[i][j] = line[j];
    }
  }
  for (int j = 0; j < 15; j++) {
    for (int i = 0; i < 5; i++) {
      if (arr[i][j] != 0)  
        cout << arr[i][j];
    }
  }
  return 0;
}