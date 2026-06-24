#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 10;

bool isP(ll x) {
  if (x == 2 or x == 3) return true;
  int sq = sqrt(x);
  for (int i = 2; i <= sq + 1; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

void solve()
{
  ll n; cin >> n;
  ll currPrime = 1;
  // cout << isP(10) << " ";
  for (int i = 0; i < n; i++) {
    for (ll j = currPrime + 1; j < 1e9; j++) {
      // cout << j << " " << isP(j) << endl;
      if (isP(j)) {
        cout << j * currPrime << " ";
        currPrime = j;
        break;
      }
    }
  }
  cout << endl;
}
// 4 + 8 + 6
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
