#include <iostream>
using namespace std;

long A[21];
int ans[21];
bool vis[21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	A[0] = 1;
	for(int i = 1; i <= n; i++) { // 팩토리얼 초기화
		A[i] = A[i-1] * i;
	}
	
	int q; // 소문제 번호
	cin >> q;
	
	if(q == 1) { // k 번째 순열 찾기
		long k;
		cin >> k;
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1, cnt = 1; j <= n; j++) {
				if(vis[j]) continue; // 이미 사용한 숫자면 다음 loop
				
				// 주어진 K에 따라 각 자리에 들어갈 수 있는 수 찾기
				if(k <= cnt * A[n - i]) {
					k -= ((cnt - 1) * A[n - i]);
					ans[i] = j;
					vis[j] = true;
					break;
				}
				cnt++;
			}
		}
		
		for(int i = 1; i <= n; i++) { // 정답 출력
			cout << ans[i] << " ";
		}
	}
	
	else { // 주어진 순열이 몇 번째 순열인지 구하기
		long k = 1;
		
		for(int i = 1; i <= n; i++) {
			cin >> ans[i];
			long cnt = 0;
			
			for(int j = 1; j < ans[i]; j++) {
				if(vis[j] == false) {
					cnt++; // 미사용 숫자 개수만큼 카운트
				}
			}
			
			k += cnt * A[n - i]; // 자릿수 개수에 따라 순서 더하기
			vis[ans[i]] = true;
		}
		cout << k;
	}				
	return 0;
}