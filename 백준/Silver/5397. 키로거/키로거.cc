#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; // 총 테스트 횟수
	cin >> T;
	while(T--){
		string str; // 문자열
		cin >> str;
		list<char> pw;
		auto cursor = pw.begin(); // 문자열 처음
		for(auto c : str) {
			if (c == '>') {
				if (cursor != pw.end()) cursor++;
			} else if (c == '<') {
				if (cursor != pw.begin()) cursor--;
			} else if (c == '-') {
				if (cursor!=pw.begin()) {
					cursor--;
					cursor = pw.erase(cursor); // 재지정 해주기.
				}
			} else {
				pw.insert(cursor, c);
			}
		}
		for(auto c : pw) cout << c;
		cout << "\n";
	}	
}