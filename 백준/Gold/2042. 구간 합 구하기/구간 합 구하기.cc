#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> tree;
int startIndex;
void makeTree() { // 리프 노드로 구간 합 구하기
	for(int i = startIndex - 1; i > 0; i--) {
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
  }
}

void change(int index, long long value) { // index 위치 value로 바꾸기
	long long diff = value - tree[index]; // 차이 구해서
	while(index > 0) { // 부모로 올라가면서 바꾸기
		tree[index] += diff;
		index /= 2;
	}
}

long long sum(int s, int e) { // s ~ e 구간합 구하기
	long long sum = 0;
	while(s <= e) {
		if(s % 2 == 1) {
			sum += tree[s];
			s++;
		}
		if(e % 2 == 0) {
			sum += tree[e];
			e--;
		}
		s /= 2;
		e /= 2;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	
	int height = 0;
	int length = n;
	while(length != 0) {
		length /= 2;
		height++;
	}
	int treeSize = int(pow(2, height + 1));
    startIndex = treeSize / 2 - 1;
	tree.resize(treeSize);
	
	// 입력
	for(int i = startIndex + 1; i <= startIndex + n; i++) {
		cin >> tree[i];
	}
	makeTree(); // tree 만들기
	
	for(int i = 0; i < m + k; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if(a == 1) {
			change(b + startIndex, c);
		} else {
			b += startIndex;
			c += startIndex;
			cout << sum(b, c) << "\n";
		}
	}
	return 0;	
}