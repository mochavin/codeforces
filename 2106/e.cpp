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
  ll n, q; cin >> n >> q;
  vector<ll> v(n + 1);
  unordered_map<ll, ll> mp;
  loop1(i, n) {
    cin >> v[i];
    mp[v[i]] = i;
  }

  while (q--) {
    ll f = 0;
    ll l, r, k; cin >> l >> r >> k;
    ll pos = mp[k], needBigger = 0, needSmaller = 0;
    ll availBigger = n - k, availSmaller = k - 1;
    if (pos < l || pos > r) f = 1;
    else
      while (l < r) {
        ll mid = (l + r) / 2;
        if (mid > pos) {
          if (v[mid] < k) needSmaller++, availBigger--;
          else availBigger--;
          r = mid - 1;
        }
        else if (mid < pos) {
          if (v[mid] > k) needBigger++, availSmaller--;
          else availSmaller--;
          l = mid + 1;
        }
        else {
          break;
        }
      }
    if (availBigger < 0 || availSmaller < 0 || f == 1) {
      cout << -1 << " "; continue;
    }
    // minimum answer is this:
    ll ans = needSmaller + needBigger;
    cout << ans + labs(needSmaller - needBigger) << " ";

  }
  cout << endl;

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
