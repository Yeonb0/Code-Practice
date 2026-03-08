#include <iostream>
using namespace std;

int d[16];
long A[16];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    d[0] = 2;
    for(int i = 1; i < 16; i++) {
        d[i] = d[i-1] * 2 - 1;
    }
    
	for(int i = 1; i < 16; i++) {
		A[i] = d[i] * d[i];
	}
	
	int ans;
	cin >> ans;
	
	cout << A[ans];
	return 0;
}