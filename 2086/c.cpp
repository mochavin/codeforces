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
  vector<ll> v(n), d(n);
  map<ll, bool> mp;
  loop(i, n) {
    cin >> v[i];
    v[i]--;
  }
  set<ll> st;
  loop(i, n) {
    cin >> d[i];
    d[i]--;
    while (mp.find(d[i]) == mp.end()) {
      st.insert(d[i]);
      mp[d[i]] = true;
      d[i] = v[d[i]];
    }

    cout << st.size() << " ";
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
