#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long num = 666;
	int n, count = 1;
	cin >> n;
	while(n != count){
		num++;
        string str = to_string(num);
		if(str.find("666") != string::npos) count++;
	}
	cout << num;
	return 0;
}