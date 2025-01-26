#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 1;

void solve()
{
  ll n, m; cin >> n >> m;
  vector<ll> a(n), b(m);
  priority_queue<ll> p, q;
  loop(i, n) cin >> a[i];
  loop(i, m) cin >> b[i];
  ll curr = 0;
  loop(i, n) p.push(a[i]);
  loop(i, m) q.push(b[i]);

  ll f = 1;
  while (!p.empty() and !q.empty()) {
    if (p.top() == q.top()) { p.pop(), q.pop(); continue; }
    if (q.top() < p.top() || p.size() < q.size()) { f = 0; break; }
    if (q.top() > p.top()) {
      ll a = q.top();
      // cout << a << " ";
      q.pop();
      if (a % 2) { q.push(a / 2); q.push(a / 2 + 1); }
      else { q.push(a / 2); q.push(a / 2); }
    }
  }
  cout << (f and p.empty() and q.empty() ? "YES" : "NO") << endl;

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
