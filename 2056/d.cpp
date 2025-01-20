#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 5;

void solve()
{
  ll n; cin >> n;
  vector<int> v(n);
  loop(i, n) cin >> v[i];
  ll ans = 0;
  loop1(mean, 10) {
    vector<ll> b(n);
    loop(i, n) {
      if (v[i] > mean) b[i] = 1;
      else b[i] = -1;
    }

    ll sum = n;
    vector<ll> pref(n);
    loop(i, n) {
      pref[i] = sum;
      sum += b[i];
    }

    vector<ll> acc(2 * n + 1, 0);
    sum = n;
    ll j = 0;
    loop(i, n) {
      if (v[i] == mean) {
        while (j <= i) {
          acc[pref[j]]++;
          j++;
        }
      }
      sum += b[i];
      ans += acc[sum];
    }
  }
  cout << n * (n + 1) / 2 - ans << endl;
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
