#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int cut = round(n*0.15);
	if (n <= 3) cut = 0;
	
	int tot = 0;
	sort(v.begin(), v.end());
	for(int i = cut; i < (n-cut); i++) {
		tot += v[i];
	}
    int div = n - 2 * cut;
    if (n <= 3) cout << round((double)tot/n);
    else cout << round((double)tot/div);
	return 0;
}