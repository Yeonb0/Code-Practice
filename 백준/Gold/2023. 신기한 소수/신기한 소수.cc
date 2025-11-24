#include <iostream>
using namespace std;

static int N; // 총 구할 자릿수

bool isPrime(int num) {
	for(int i = 2; i <= num / 2; i++) {
		if(num % i == 0) return false;
	}
	return true;
}

void DFS(int num, int digit) {
	if(digit == N) {
		if(isPrime(num)) cout << num << "\n";
		return;
	}
	for (int i = 1; i < 11; i += 2) {
		if(isPrime(num * 10 + i)) {   // 소수면
			DFS(num*10+i, digit + 1); // 자릿수 + 1 해서 DFS
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);
	
	return 0;
}