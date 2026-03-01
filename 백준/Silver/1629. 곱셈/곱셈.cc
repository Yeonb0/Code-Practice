#include <iostream>
using namespace std;
typedef long long ll;

ll mult(ll a, ll b, ll c){
  if(b == 0) {
    return 1;
  }

  ll half = mult(a, b/2, c);

  if(b % 2 == 0) { // 짝수면 
    return (half * half) % c;
  } else { // 홀수면
    return ((half * half) % c * a) % c;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll a, b, c;
  cin >> a >> b >> c;
  cout << mult(a % c, b, c);
}