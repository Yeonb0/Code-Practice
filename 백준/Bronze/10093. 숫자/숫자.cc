#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	unsigned long long a, b;
	cin >> a >> b;
	if(b < a){
		unsigned long long temp = a;
		a = b;
		b = temp;
	}
	if (a == b) {
		cout << "0";
	}
	else {
		cout << b-a-1 << "\n"; // 두 수 사이 있는 수 갯수
		for(unsigned long long i = a+1; i <= b-1; i++)
			cout << i << " ";
	}
	return 0;
}