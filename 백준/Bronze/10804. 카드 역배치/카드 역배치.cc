#include <iostream>
#define SWAP(a, b) {int tmp=a; a=b; b=tmp;}
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a[10][2];
	int b[20];
  int s, e, n;
  
	for(int i = 0; i < 20; i++)
		b[i] = i+1;
		
	// 입력	
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 2; j++)
			cin >> a[i][j];
	
	for(int i = 0; i < 10; i++){
		s = a[i][0] - 1;  // 교환 시작 인덱스
		e = a[i][1] - 1;  // 교환 끝 인덱스
		
		n = e - s + 1; // 교환 구간 수
		for(int j = 0; j < n/2; j++)
			SWAP(b[e-j], b[s+j]);
	}
	
	// 출력
	for(int i = 0; i < 20; i++)
		cout << b[i] << " ";
		
	return 0;
}