#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool check(int num) {
	string str = to_string(num); 
	int s = 0;
	int e = str.size() -1;
	while(s < e) {
		if(str[s] != str[e]) return false;
		s++;
		e--;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	long A[10000001];
	for(int i = 2; i < 10000001; i++) A[i] = i;
	for(int i = 2; i < sqrt(10000001); i++) { // 에라토스테네스의 체
		if(A[i] == 0) continue;
		for(int j = i + i; j < 10000001; j += i) A[j] = 0;
	}
	
	while(true) {
		if(A[n] != 0) { // 소수 check
			if(check(A[n])) { // 팰린드롬 check
				cout << A[n];
				break;
			}
		}
		n++;
	}
	return 0;
}