#include <iostream>
#include <string>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int times;
	cin >> times;
	string word[100];
	string ans[100];
	
	for (int i = 0; i < times; i++) {
		cin >> word[i];
		if (word[i].length() > 10) {
			char first = word[i][0];
			char last = word[i][word[i].length()-1];
			int middle = 0;
			for(int j = 1; j < word[i].length()-1; j++) {
				middle++;
			}
  		ans[i] = first + to_string(middle) + last;
    } else {
	    ans[i] = word[i];
	  }
	}
	
	for (int i = 0; i < times; i++) {
		cout << ans[i] + "
";
	}
        
	return 0;
}