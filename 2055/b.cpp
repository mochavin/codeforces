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
ll N = 2e5 + 1;



void solve()
{
  ll n; cin >> n;
  vector<ll> a(n), b(n);
  loop(i, n) cin >> a[i];
  loop(i, n) cin >> b[i];
  int f = 0;
  priority_queue<pair<ll, ll>> pq1;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq2;

  ll sumKurang = 0;
  loop(i, n) {
    if (a[i] < b[i]) {
      f++;
      sumKurang += abs(a[i] - b[i]);
    }
    else {
      pq2.push({ a[i] - b[i], i });
    }
  }
  if (f == 0) {
    cout << "YES" << endl;
    return;
  }

  if (f >= 2 or (!pq2.empty() and pq2.top().first < sumKurang)) {
    cout << "NO" << endl; return;
  }

  cout << "YES" << endl;

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
