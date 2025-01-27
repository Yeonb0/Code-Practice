#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n; // 초기 문자열
    int m;    // 실행할 명령어 개수
    cin >> n >> m;

    list<char> text(n.begin(), n.end()); // 초기 문자열 복사
    auto cursor = text.end();            // 커서를 문자열 끝으로 초기화

    while (m--) { // 명령어 개수만큼 반복
        char a; // 명령어
        cin >> a;

        if (a == 'L') { // 커서를 왼쪽으로 이동
            if (cursor != text.begin()) cursor--;
        } else if (a == 'D') { // 커서를 오른쪽으로 이동
            if (cursor != text.end()) cursor++;
        } else if (a == 'B') { // 커서 왼쪽 문자 삭제
            if (cursor != text.begin()) {
                cursor = text.erase(--cursor); // 반복자 갱신
            }
        } else if (a == 'P') { // 커서 위치에 문자 추가
            char t;
            cin >> t;
            text.insert(cursor, t);
        }
    }

    for (auto c : text) { // 최종 문자열 출력
        cout << c;
    }
    return 0;
}
