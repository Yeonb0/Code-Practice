#include <iostream>
using namespace std;
int arr[10001]; // 숫자 범위: 0 ~ 10000

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		arr[a]++;
	}
	for(int i = 0; i <= 10000; i++) {
		while(arr[i]--) cout << i << "\n";
	}
	return 0;
}
