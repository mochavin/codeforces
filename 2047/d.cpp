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
  vector<ll> v(n), cek(n, 1);
  priority_queue<ll, vector<ll>, greater<ll>> pq, pq3;
  priority_queue<ll> pq2;

  ll mn = M;
  loop(i, n) {
    cin >> v[i];
    mn = min(v[i], mn);
    pq2.push(v[i]);
  }

  ll mncurr = M, f = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (v[i] == mn) {
      pq.push(v[i]), cek[i] = 0;
    }
    else {
      if (mncurr < v[i]) {
        pq.push(v[i] + 1), cek[i] = 0, pq2.push(v[i] + 1), pq3.push(v[i] + 1);
        f = 1;
        // cout << v[i] + 1 << ' ';
      }
    }
    mncurr = min(mncurr, v[i]);
  }

  loop(i, n) {
    if (cek[i]) {
      if (!f) { pq.push(v[i]); continue; }
      if (v[i] > pq3.top()) pq.push(v[i] + 1);
      else pq.push(v[i]);
    }
  }

  loop(i, n) {
    cout << pq.top() << " ";
    pq.pop();
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
