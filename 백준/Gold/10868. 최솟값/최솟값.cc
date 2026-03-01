#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <algorithm>
using namespace std;

vector<int> tree;

void setTree(int i) { // 총 노드 수
	while(i != 1) {
		if(tree[i / 2] > tree[i]) {
			tree[i / 2] = tree[i]; // 더 작은 값으로
		}
		i--;
	}
}
		
int getMin(int s, int e) { // 구간 내 최솟값 구하기
	int Min = INT_MAX;
	
	while(s <= e) {
		if(s % 2 == 1) { // s가 홀수면
			Min = min(Min, tree[s]);
			s++;
		}
		s = s / 2; // 부모로 이동
		if(e % 2 == 0) { // e가 짝수면
			Min = min(Min, tree[e]);
			e--;
		}
		e = e / 2;
	}
	return Min;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	int treeHeight = 0;
	int length = n; 
	
	while(length != 0) {
		length /= 2;
		treeHeight++;
	}
	int treeSize = pow(2, treeHeight + 1);
	int leftNodeStart = (treeSize / 2) - 1;
	
	// 트리 초기화
	tree.resize(treeSize);
	fill(tree.begin(), tree.end(), INT_MAX); // 최소 구하기 -> min 사용 할거니까
	
	// input : n
	for(int i = leftNodeStart + 1; i <= leftNodeStart + n; i++) {
		cin >> tree[i];
	}
	setTree(treeSize - 1); // 트리 만들기
	
	// input : m
	for(int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		s += leftNodeStart;
		e += leftNodeStart;
		cout << getMin(s, e) << "\n";
	}
	return 0;
}