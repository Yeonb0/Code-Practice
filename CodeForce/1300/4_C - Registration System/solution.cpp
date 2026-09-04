#include <iostream>
#include <map>
#include <string>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	map<string, int> DB;
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		
		if (DB.count(name) == 0) {
			DB.insert({name, 1});
			cout << "OK 
";
		} else {
			cout << name + to_string(DB[name]) + "
";
			DB[name]++;
		}
	}
	return 0;
}