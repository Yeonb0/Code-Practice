#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
long long ans;

void merge(int p, int q, int r) {
	int left = q - p + 1; // p ~ q 크기
	int right = r - q; // q+1 ~ n 크기
	vector<int> L(left);
	vector<int> R(right);
	// 배열 복사하기
	for(int i = 0; i < left; i++) L[i] = arr[p+i];
	for(int j = 0; j < right; j++) R[j] = arr[q+j+1];
	
	int i = 0, j = 0, k = p; // k는 채울 A 위치
	while(i < left && j < right) { // 배열에 병합 안된 원소가 있으면 arr 처음부터 채우기
        if(L[i] <= R[j]) {
			arr[k] = L[i]; i++;
		} else {
			arr[k] = R[j]; j++;
            ans += (left - i);
		}
		k++;
	}
	// 둘 중 하나 끝내고 나머지 복사
	while(i < left) {
		arr[k] = L[i];
		i++; k++; 
	}
	while(j < right) {
		arr[k] = R[j];
		j++; k++; 
	}
}

void merge_sort(int p, int r) {
	if(p >= r) // 0 or 원소 1개
		return;
	int q = (p+r)/2;
	merge_sort(p, q);
	merge_sort(q+1, r);
	merge(p, q, r);
}		 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	merge_sort(0, n-1);
	cout << ans;
	return 0;
}