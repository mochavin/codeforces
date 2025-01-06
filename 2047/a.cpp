#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;

void solve()
{
  ll n; cin >> n;
  ll cnt = 1, tmp = 0, ans = 0;
  // 1 --> 1-0
  // 2 --> 9-1
  // 3 --> 25-9
  // 4 --> 49-25

  // total
  // 169
  loop(i, n) {
    ll in; cin >> in;
    tmp += in;
    ll sqr = sqrt(tmp);
    if (tmp & 1 and sqr * sqr == tmp) ans++;
  }
  // cout << tmp << " ";
  cout << ans << endl;
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
