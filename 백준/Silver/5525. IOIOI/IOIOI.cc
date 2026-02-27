#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;

	string target = "";
	for(int i = 0; i < n; i++) {
		target += "IO";
	}
	target += "I";
	
	int count = 0;
    size_t pos = 0;

     while ((pos = s.find(target, pos)) != string::npos) {
        count++;
        pos += 1; // 한 칸 이동
     }
    cout << count;
    return 0;
}