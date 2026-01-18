#include <iostream>
#include <queue>
using namespace std;

struct compare {
	bool operator()(int a, int b) {
		int absa = abs(a);
		int absb = abs(b);
		if(absa == absb) return a > b;
		else return absa > absb;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	priority_queue<int, vector<int>, compare> Q;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int num;
		cin >> num;
		
		if(num == 0) {
			if(Q.empty()) cout << 0 << "\n";
			else {
				cout << Q.top() << "\n";
				Q.pop();
			}
		}
		else Q.push(num);	
	}
	return 0;
}