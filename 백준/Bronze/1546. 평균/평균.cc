#include <iostream>
using namespace std;
double score[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> score[i];
	double max = score[0];
	double sum = 0;
	for(int i = 0; i < n; i++) {
		if(max <= score[i]) max = score[i];
	}
	for(int i = 0; i < n; i++) {
		sum += (score[i]/max)*100;
	}
	sum /= n;
	cout << sum;
	return 0;
}