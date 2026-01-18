#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[8];
	bool as = true, de = true;
	
	for (int i = 0; i < 8; i++) cin >> arr[i];
	if (arr[0] == 1 || arr[0] == 8) {
		for (int j = 1; j < 8; j++) {
			if (arr[j-1] < arr[j]) de = false;
			if (arr[j-1] > arr[j]) as = false;
		}
		if (as == true) cout << "ascending";
		else if (de == true) cout << "descending";
		else cout << "mixed";
	} else cout << "mixed";
	
	return 0;
}