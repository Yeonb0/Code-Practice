#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct User {
	int age;
	int order;
	string name;
};

User make_user(int a, int i, string name) {
	User user;
	user.age = a;
	user.order = i;
	user.name = name;
	return user;
}

bool compare(User a, User b) {
	if(a.age == b.age) return a.order < b.order;
	else return a.age < b.age;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a;
	string name;
	vector<User> v;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> name;
		v.push_back(make_user(a, i, name));
	}
	sort(v.begin(), v.end(), compare);
	for(int i = 0; i < n; i++) {
		cout << v[i].age << " " << v[i].name << "\n";
	}
	return 0;
}