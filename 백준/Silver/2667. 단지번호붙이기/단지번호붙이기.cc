#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int bor[27][27];
bool visit[27][27];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int num = 0;
int n;

void dfs(int a, int b) {
  visit[a][b] = true;
  for(int i = 0; i < 4; i++) {
    int nx = a + dx[i];
    int ny = b + dy[i];
    if(nx == 0 || nx > n || ny == 0 || ny > n) continue;
    if(!visit[nx][ny] && bor[nx][ny] == 1) {
      num++;
      dfs(nx, ny);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
	// 입력
  for(int i = 1; i <= n; i++) { 
    string str;
    cin >> str;
    for(int j = 0; j < str.size(); j++) {
      bor[i][j+1] = str[j] - '0';
    }
  }
  int count = 0;
  vector<int> ans;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(bor[i][j] == 1 && !visit[i][j]) {
        num = 1;          
        dfs(i, j);        
        ans.push_back(num); // DFS 끝난 후 개수 추가
        count++;
      }
    }
  }
  cout << count << "\n";
  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
  return 0;
}
