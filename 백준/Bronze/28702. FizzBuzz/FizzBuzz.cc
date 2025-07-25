#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string fi, se, th;
	cin >> fi >> se >> th;
	int ans;
	if(isdigit(fi[0])) ans = stoi(fi) + 3;
	else if(isdigit(se[0])) ans = stoi(se) + 2;
	else if(isdigit(th[0])) ans = stoi(th) + 1;
    if(ans % 5 == 0) {
        if(ans % 3 == 0) cout << "FizzBuzz";
        else cout << "Buzz";
    } else {
        if(ans % 3 == 0) cout << "Fizz";
        else cout << ans;
    }
	return 0;
}