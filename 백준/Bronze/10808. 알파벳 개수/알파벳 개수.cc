#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	char s[101];
	int j = 0;
	cin >> s;
	int a[26] = {0};
	
	while(s[j] != 0){
		for(int k = 0; k < 26; k++){
			if(s[j] == (97+k)){
				a[k]++; j++;
				break; 
			}
		}
	}
	for(int k = 0; k < 26; k++)
		cout << a[k] << " ";
	return 0;
}