#include <iostream>
using namespace std;

int p[1000001]; // 부모 저장 배열

int find(int a) {
	if(a == p[a]) return a;
	else return(find(p[a])); // 재귀함수
}

void uni(int a, int b) { // 부모끼리 연결
	a = find(a);
	b = find(b);	

	if(a != b) p[b] = a;
}

bool check(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
    
    for(int i = 0; i <= n; i++) p[i] = i;
    
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 0) {
			uni(b, c);
		} else {
			if(check(b, c)) cout << "yes\n";
			else cout << "no\n";
		}
	}
	return 0;
}