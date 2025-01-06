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

void solve()
{
  ll n; cin >> n;
  vector<ll> a(n), b(n);
  loop(i, n) cin >> a[i];
  loop(i, n) cin >> b[i];
  vector<ll> atas, bawah;
  priority_queue<ll> pq;
  // cout << n << " ";
  // loop(i, n) cout << a[i] << " ";
  loop(i, n) {
    if (a[i] >= b[i]) {
      atas.push_back(a[i]);
      pq.push(b[i]);
    }
    else {
      bawah.push_back(b[i]);
      pq.push(a[i]);
    }
  }

  ll ans = 0;
  // cout << bawah.size() << " ";
  loop(i, atas.size()) {
    ans += atas[i];
  }
  loop(i, bawah.size()) {
    ans += bawah[i];
  }
  // cout << endl;
  cout << ans + pq.top() << endl;
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
