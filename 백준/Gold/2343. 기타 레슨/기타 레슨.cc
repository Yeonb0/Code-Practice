#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> A(n);
	int st = 0, en = 0;
	for(int i = 0; i < n; i++) {
		cin >> A[i];
		if(st < A[i]) st = A[i];
		en += A[i];
	}
	
	while(st <= en) {
		int mid = (st + en + 1) / 2;
		int sum = 0;
		int count = 0;
		
		for(int i = 0; i < n; i++) { // 필요 블루레이 갯수 세기
			if(sum + A[i] > mid) {
				count++;
				sum = 0;
			}
			sum += A[i];
		}
		if(sum != 0) count++; // 마지막 블루레이
		if(count > m) { // 오른쪽 선택
			st = mid + 1;
		} else { // 왼쪽 선택
			en = mid - 1;
		}
	}
	cout << st;
	return 0;
	
}