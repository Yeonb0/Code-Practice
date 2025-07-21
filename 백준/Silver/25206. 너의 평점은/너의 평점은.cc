#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num = 20;
	double tot = 0;
	int mi = 0;
	double sum = 0;
	while(num--) {
		string name, grade;
		double time;
		cin >> name >> time >> grade;
		if(grade == "P") mi++;
		else if(grade == "A+") {
			tot += 4.5 * time; 
			sum += time;
		} else if(grade == "A0") {
			tot += 4.0 * time; 
			sum += time;
		} else if(grade == "B+") {
			tot += 3.5 * time; 
			sum += time;
		} else if(grade == "B0") {
			tot += 3.0 * time; 
			sum += time;
		} else if(grade == "C+") {
			tot += 2.5 * time; 
			sum += time;
		} else if(grade == "C0") {
			tot += 2.0 * time; 
			sum += time;
		} else if(grade == "D+") {
			tot += 1.5 * time; 
			sum += time; 
		} else if(grade == "D0") {
			tot += 1.0 * time; 
			sum += time;
		} else if(grade == "F") sum += time;
	}
	cout << tot / sum;
	return 0;
}