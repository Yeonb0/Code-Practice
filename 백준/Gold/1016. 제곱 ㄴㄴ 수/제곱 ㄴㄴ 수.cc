#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long min, max;
	cin >> min >> max;
	vector<bool> check(max - min + 1, 0);
	
	// 에라토스테네스 체 변형
	for(long long i = 2; i * i <= max; i++) {
		long long pow = i * i;
		long long st_index = min / pow;
		if(min % pow != 0) st_index++; // 나머지 있으면 +1
		for(long long j = st_index; pow * j <= max; j++) { // 제곱수 true로 바꾸기
			check[(int)((j * pow) - min)] = true;
		}
	}
	
	int ans = 0;
	for(int i = 0; i <= max-min; i++) {
		if(!check[i]) ans++;
	}
	cout << ans;
	return 0;
}