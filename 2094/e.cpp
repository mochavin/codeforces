#include <bits/stdc++.h>
#include <iostream>
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
  ll n; cin >> n;
  vector<ll> a(n);
  int mn = 100;
  vector<ll> isi(32, 0);
  loop(i, n)
  {
    cin >> a[i];
    loop(j, 32) {
      isi[j] += ((a[i] >> j) & 1);
    }
  }
  ll ans = 0;
  loop(i, n) {
    ll cnt = 0;
    loop(j, 32) {
      ll li = ((a[i] >> j) & 1);
      if (li) {
        cnt += ((n - isi[j]) * (1 << j));
      }
      else {
        cnt += (isi[j] * (1 << j));
      }
    }
    // cout << cnt << " ";
    ans = max(cnt, ans);
  }
  cout << ans << endl;


  // loop(i, n) {
  //   ll temp = 0;
  //   loop(j, n) {
  //     temp += a[i] ^ a[j];
  //   }
  //   cout << temp << " ";
  //   ans = max(temp, ans);
  // }
  // cout << ans << endl;
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
