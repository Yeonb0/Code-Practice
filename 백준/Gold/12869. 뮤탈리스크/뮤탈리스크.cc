#include <iostream>
#include <queue>
#include <utility>
#include <limits.h>
#include <algorithm>
#define INF 99999
using namespace std;

int n;
int a, b, c;
int hp[61][61][61];
int dx[3] = {1, 3, 9};

int dp(int a, int b, int c) {
	if (a == 0 && b == 0 && c == 0) return 0;
	if (hp[a][b][c] != 0) return hp[a][b][c];
	
	hp[a][b][c] = INF;
	
	do { // 6 가지 경우의 수에 대해 DP 
    int na, nb, nc;
		na = max(0, a-dx[0]);
		nb = max(0, b-dx[1]);
		nc = max(0, c-dx[2]);
		hp[a][b][c] = min(hp[a][b][c], dp(na, nb, nc) + 1);
	} while (next_permutation(dx, dx+3)); // permutation 만들기
    
  return hp[a][b][c];
}
	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	if (n == 3) {
		cin >> a >> b >> c;
	} else if (n == 2) {
		cin >> a >> b;
	} else
		cin >> a;
	int ans = dp(a, b, c);
	
	cout << ans;
	return 0;
}