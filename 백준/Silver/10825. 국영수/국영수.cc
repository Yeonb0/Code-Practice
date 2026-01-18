#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
	string name;
	int kor;
	int eng;
	int mat;
};

Student make_stu(string name, int kor, int eng, int mat) {
	Student stu;
	stu.name = name;
	stu.kor = kor;
	stu.eng = eng;
	stu.mat = mat;
	return stu;
}

bool compare(Student a, Student b) {
	if(a.kor == b.kor) {
		if(a.eng == b.eng) {
			if(a.mat == b.mat) return a.name < b.name;
			else return a.mat > b.mat;
		} else return a.eng < b.eng;
	} else return a.kor > b.kor;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, e, m;
	string name;
	vector<Student> v;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> name >> k >> e >> m;
		v.push_back(make_stu(name, k, e, m));
	}
	sort(v.begin(), v.end(), compare);
	for(int i = 0; i < n; i++) {
		cout << v[i].name << "\n";
	}
	return 0;
}