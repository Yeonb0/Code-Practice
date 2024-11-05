#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	for(int t = 0; t < n; t++){
		string a;
		string b;
		cin >> a >> b;
		bool po = true;
		
		int ca[26] = {0}, cb[26] = {0};
		for(char ch : a)
			ca[ch - 'a']++;
		for(char ch : b)
			cb[ch - 'a']++;
		for(int i = 0; i < 26; i++){
			if(ca[i] != cb[i]){
				po = false;
				break;
			}
		}
		if(po == true)
			cout << "Possible \n";
		else
			cout << "Impossible \n";
	}
	return 0;
}