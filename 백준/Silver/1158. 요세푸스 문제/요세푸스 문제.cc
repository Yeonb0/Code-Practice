#include <iostream>
#include <queue>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	list<int> answer;
	queue<int> people;
	
	// 큐에 원소 넣기
	for(int i = 0; i < n; ) {
		people.push(++i);
	}
	
	int count = 1;
	// 큐가 빌 때 까지
	while(!people.empty()) {
		if (count == k) {
			int plus = people.front();
			people.pop();
			answer.push_back(plus);
			count = 1;
		} else {
			count++;
			int pop = people.front();
			people.pop();
			people.push(pop);
		}
	}

    // 출력
    cout << "<";
    for (auto it = answer.begin(); it != answer.end(); it++) {
        if (it != answer.begin()) cout << ", ";
        cout << *it;
    }
    cout << ">\n";

    return 0;
}