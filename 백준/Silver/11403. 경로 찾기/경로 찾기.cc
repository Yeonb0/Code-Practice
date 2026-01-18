#include <iostream>
using namespace std;

int A[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
	
	// Floyd-Warshall
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(A[i][k] == 1 && A[k][j] == 1) 
					A[i][j] = 1;
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}