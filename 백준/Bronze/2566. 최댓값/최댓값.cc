#include <iostream>
using namespace std;
int arr[10][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x = 1, y = 1;
	int max = 0;
	for(int i = 1; i < 10; i++) {
		for(int j = 1; j < 10; j++) {
			cin >> arr[i][j];
			if(max <= arr[i][j]) {
				max = arr[i][j];
				x = i;
				y = j;
            }
		}
	}
	cout << max << "\n" << x << " " << y;
	return 0;
}