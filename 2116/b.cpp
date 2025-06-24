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

vector<ll>pre(N, 0);

void solve()
{
  ll n; cin >> n;
  vector<ll> a(n), b(n);
  vector<pair<ll, ll>> p(n), q(n);
  loop(i, n) cin >> a[i];
  loop(i, n) cin >> b[i];
  p[0] = { a[0], 0 }; q[0] = { b[0], 0 };
  cout << (pre[a[0]] + pre[b[0]]) % M << " ";
  loop1(i, n - 1) {
    ll mx = 0;
    if (a[i] > p[i - 1].first) {
      p[i] = { a[i], i };
    }
    else {
      p[i] = p[i - 1];
    }
    if (b[i] > q[i - 1].first) {
      q[i] = { b[i], i };
    }
    else {
      q[i] = q[i - 1];
    }
    if (p[i].first == q[i].first) {
      if (p[i].first + (b[i - p[i].second]) > q[i].first + a[i - q[i].second]) {
        cout << (pre[p[i].first] + pre[(b[i - p[i].second])]) % M << " ";
      }
      else {
        cout << (pre[q[i].first] + pre[(a[i - q[i].second])]) % M << " ";
      }
      continue;
    }
    if (p[i] > q[i]) {
      cout << (pre[p[i].first] + pre[b[i - p[i].second]]) % M << " ";
    }
    else {
      cout << (pre[q[i].first] + pre[a[i - q[i].second]]) % M << " ";
    }
  }
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  pre[0] = 1;
  loop(i, N - 1) {
    if (i) {
      pre[i] = (2 * pre[i - 1]) % M;
    }
  }
  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
