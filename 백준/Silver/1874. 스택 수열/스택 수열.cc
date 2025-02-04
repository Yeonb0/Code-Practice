#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> num;
    stack<int> stack;
    queue<char> answer;
    
    for (int i = n; i >= 1; i--) {
        num.push(i);
    }

    bool no = false;
    int current = 1; // 현재 스택에서 사용 가능한 가장 작은 숫자

    while (n--) {
        int k;
        cin >> k;

        // 스택에서 k를 만들기 위해 push 연산 수행
        while (!num.empty() && num.top() <= k) {
            stack.push(num.top());
            num.pop();
            answer.push('+');
        }

        // 스택의 맨 위가 k이면 pop 연산 수행
        if (!stack.empty() && stack.top() == k) {
            stack.pop();
            answer.push('-');
        }
        // 불가능한 경우
        else {
            no = true;
            break;
        }
    }

    if (no) {
        cout << "NO\n";
    } else {
        while (!answer.empty()) {
            cout << answer.front() << "\n";
            answer.pop();
        }
    }

    return 0;
}
