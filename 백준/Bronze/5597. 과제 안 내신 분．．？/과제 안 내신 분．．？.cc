#include <iostream>
using namespace std;
bool stu[31];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 28;
	while(n--) {
		int a;
		cin >> a;
		stu[a] = true;
	}
	for(int i = 1; i <= 30; i++) 
		if(!stu[i]) cout << i << "\n";
	return 0;
}