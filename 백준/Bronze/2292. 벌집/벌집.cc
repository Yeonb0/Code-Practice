#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int num;
    std::cin >> num;

    int count = 1; // 1번 방 (1층)
    int range = 1; // 현재 층의 마지막 방 번호

    if (num == 1) {
        std::cout << 1;
        return 0;
    }

    // 2층부터 시작
    while (num > range) {
        range += 6 * count; // 다음 층의 마지막 방 번호 계산
        count++;            // 층 수 증가
    }

    std::cout << count;

    return 0;
}