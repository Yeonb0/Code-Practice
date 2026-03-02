#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static int MOD = 1000000007;
vector<long> tree;

void setTree(int i); // 구간 곱 트리 만들기
void changeVal(int node, int val); // node 의 값을 val 로 바꾸기
long getMult(int start, int end); // start ~ end 까지 구간합 구하기 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k; 
	int treeHeight = 0;
	int length = n;
	
	// 트리 크기 구하기
	while(length != 0) {
		treeHeight++;
		length /= 2;
	}
	int treeSize = pow(2, treeHeight + 1);
	int leftStartNode = treeSize / 2 - 1;
	tree.resize(treeSize);
	fill(tree.begin(), tree.end(), 1); // 구간 곱이기 때문에 초기값 1 설정

	for(int i = leftStartNode + 1; i <= leftStartNode + n; i++) { // leaf 에 n 입력 받기
		cin >> tree[i];
	}
	setTree(treeSize - 1); // 트리 만들기
	
	for(int i = 0; i < m + k; i++) { // 교환 & 구간 곱 
		long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) { // b의 수를 c로 변경
			changeVal(leftStartNode + b, c);
		} else {
			cout << getMult(leftStartNode + b, leftStartNode + c) << "\n";
		}
	}
	return 0;
}

void setTree(int i) {
	while(i != 1) {
		tree[i / 2] = tree[i / 2] * tree[i] % MOD;
		i--;
	}
}

void changeVal(int node, int val) {
	tree[node] = val;
	// 위로 올라가면서 구간 곱 바꾸기
	while(node > 1) {
		node /= 2;
		tree[node] = ((tree[node * 2] % MOD) * (tree[node * 2 + 1] % MOD)) % MOD;
	}
}

long getMult(int start, int end) {
	long res = 1;
	
	while(start <= end) {
		if(start % 2 == 1) {
			res = res * tree[start] % MOD;
			start++;
		}
		if(end % 2 == 0) {
			res = res * tree[end] % MOD;
			end--;
		}
		start /= 2; 
		end /= 2;
	}
	return res;
}