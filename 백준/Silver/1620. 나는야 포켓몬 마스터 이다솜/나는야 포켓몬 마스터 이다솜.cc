#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
using namespace std;
unordered_map<string, int> poke;
unordered_map<int, string> mon;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		string name;
		cin >> name;
		poke[name] = i;
		mon[i] = name;
	}
	while(m--) {
		string ques;
		cin >> ques;
		if(isalpha(ques[0])) {
			cout << poke[ques] << "\n";
		} else cout << mon[stoi(ques)] << "\n";
	}
	return 0;
}