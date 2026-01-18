#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> A[10]; // 재료 간 연결 리스트
long lcm; // 최소공배수
bool visited[10];
long D[10]; // 노드 값

long gcd(long a, long b) {
	if(b == 0) return a;
	else return gcd(b, a % b);
}

void DFS(int a) { 
	visited[a] = true;
	for(auto i : A[a]) {
		int next = get<0>(i);
		if(!visited[next]) {
			D[next] = D[a] * get<2>(i) / get<1>(i);
			DFS(next);
		}
	}
}
	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	lcm = 1;
	
	for(int i = 0; i < n-1; i++) {
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		A[a].push_back(make_tuple(b, p, q));
		A[b].push_back(make_tuple(a, q, p));
		lcm *= (p * q) / gcd(p, q);
	}
	
	D[0] = lcm;
	DFS(0);
	
	long g = D[0]; // 최대공약수 구하기
	for(int i = 1; i < n; i++) {
		g = gcd(g, D[i]);
	}
	for(int i = 0; i < n; i++) {
		cout << D[i] / g << " "; // 구한 값 최대 공약수로 나누기
	}
	return 0;
}