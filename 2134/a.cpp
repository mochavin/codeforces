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

void solve()
{
  ll n, a, b; cin >> n >> a >> b;
  ll f = 0;
  if (n & 1) {
    if (b >= a) {
      if (b & 1) f = 1;
    }
    else {
      if (a & 1 and b & 1) f = 1;
    }
  }
  else {
    if (b >= a) {
      if (b % 2 == 0) f = 1;
    }
    else {
      if (b % 2 == 0 and a % 2 == 0) f = 1;
    }
  }
  cout << (f ? "YES" : "NO") << endl;
}

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
