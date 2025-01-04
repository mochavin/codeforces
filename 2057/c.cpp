#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 5;

ll eval(ll a, ll b, ll c) {
  return (a ^ b) + (b ^ c) + (a ^ c);
}

ll msb(ll a) {
  ll cnt = 0;
  while (a > 0) a >>= 1, cnt++;
  return cnt - 1;
}

void solve()
{
  ll l, r; cin >> l >> r;
  ll a = 0, b = 0, c = 0;
  for (int i = 62; i >= 0; i--) {
    if (((l ^ r) >> i) & 1ll) {
      a |= (1ll << i);
      b |= (1ll << i) - 1;
      break;
    }
    else {
      a |= (1ll << i) & l;
      b |= (1ll << i) & l;
    }
  }

  c = l;
  while (a == c || b == c) c++;
  // cout << eval(a, b, c) << endl;
  cout << a << " " << b << " " << c << endl;
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
