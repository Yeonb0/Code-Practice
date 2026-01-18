#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, t, p;
	vector<int> size(6);
	cin >> n;
	for (int i = 0; i < 6; i++) cin >> size[i];
	cin >> t >> p;
	int tsum = 0;
	for (int i = 0; i < 6; i++) {
		if (size[i] % t == 0) tsum += (size[i] / t);
		else tsum += (size[i] / t) + 1;
	}
	cout << tsum << "\n" << (n/p) << " " << (n%p);
	return 0;	
}