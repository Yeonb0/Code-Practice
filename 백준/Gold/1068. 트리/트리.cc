#include <iostream>
#include <vector>
using namespace std;

int n, ans, del, root;
vector<int> adj[51];
bool vis[51];

void Delete(int del) { // 서브 트리 제거
  vis[del] = true;
	for(auto i : adj[del]) {
		if(vis[i]) continue;
		else {
			vis[i] = true;
			Delete(i);
		}
	}
}

void DFS(int root) {
    bool isLeaf = true;  
    for(auto i : adj[root]) {
        if(vis[i]) continue;  // 다 삭제된 노드면 true 
        isLeaf = false; // 하나라도 자식 있으면 false
        DFS(i);
    }
    if(isLeaf) ans++;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if(a == -1) {
			root = i;
		} else {
			adj[a].push_back(i);
		}
	}
	cin >> del;
    if(del == root) {
        cout << "0";
    } else {
        Delete(del);
    	DFS(root);
        cout << ans;
    }
	
	return 0;
}