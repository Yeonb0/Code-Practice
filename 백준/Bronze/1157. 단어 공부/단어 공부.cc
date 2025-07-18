#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  int arr[26] = {};
  for (char ch : s) {
    ch = toupper(ch);  
    arr[ch - 'A']++;
  }

  int mx = 0;
  char ans = '?';
  bool same = false;

  for (int i = 0; i < 26; ++i) {
    if (arr[i] > mx) {
      mx = arr[i];
      ans = i + 'A'; 
      same = false;
    } else if (arr[i] == mx && mx != 0) {
      same = true;
    }
  }

  cout << (same ? '?' : ans);
  return 0;
}
