#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int maxSum = 0; // 가장 큰 합 저장 변수

    // 3중 반복문으로 모든 조합 탐색
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                int sum = v[i] + v[j] + v[k];
                if (sum <= m && sum > maxSum) {
                    maxSum = sum;
                }
            }
        }
    }

    cout << maxSum;
}
