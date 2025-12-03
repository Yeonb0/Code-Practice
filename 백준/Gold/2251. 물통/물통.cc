#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int Send[6] = {0, 0, 1, 1, 2, 2};
int Receive[6] = {1, 2, 0, 2, 0, 1};
bool visited[201][201];
vector<int> ans;
queue<pair<int, int>> q;
int now[3]; // A, B, C 값

void BFS() {
	q.push({0, 0});
	visited[0][0] = true;
	ans.push_back(now[2]);
	
	while(!q.empty()) {
		auto p = q.front();
		q.pop();
		int A = p.first;
		int B = p.second;
		int C = now[2] - A - B;
		
		// 6개 케이스 
		for(int i = 0; i < 6; i++) {
			int next[] = {A, B, C};
			next[Receive[i]] += next[Send[i]]; // 물 더하기
			next[Send[i]] = 0; // 보낸 물통은 0으로
		
			if(next[Receive[i]] > now[Receive[i]]) { // 용량 초과하면
				next[Send[i]] = next[Receive[i]] - now[Receive[i]]; // 초과 용량 돌리기
				next[Receive[i]] = now[Receive[i]]; // 꽉 채우기
			}
			if(!visited[next[0]][next[1]]) { // 방문 안했으면
				visited[next[0]][next[1]] = true; // 방문하고
				q.push({next[0], next[1]}); // 큐에 넣기
				
				if (next[0] == 0) ans.push_back(next[2]); // A 0이면 답에 넣기
			}
		}
	}
}
	
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> now[0] >> now[1] >> now[2];
	BFS();
	sort(ans.begin(), ans.end());
	for(int n : ans) cout << n << " ";
	return 0;
}