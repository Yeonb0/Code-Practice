#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a[9];
	int sum = 0, extra;
	int in1, in2;
	
	// 입력
	for(int i = 0; i < 9; i++)
		cin >> a[i];
	
	// 가짜 난쟁이 찾기
	for(int i = 0; i < 9; i++)
		sum += a[i];
	extra = sum - 100;
	for(int i = 0; i < 8; i++)
		for(int j = i+1; j < 9; j++){
			if(a[i] + a[j] == extra){
				in1 = i;
				in2 = j;
				break;
			}
		}
	
	// 일곱 난쟁이 배열
	int b[7];
	int idx = 0;
		for(int i = 0; i < 9; i++){
			if(i != in1 && i != in2)
				b[idx++] = a[i];
		}
	
	// 정렬
	sort(b, b+7);
	
	// 출력
	for(int i = 0; i < 7; i++)
		cout << b[i] << "\n";
		
	return 0;
}