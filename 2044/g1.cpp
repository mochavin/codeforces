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
  vector<ll> r(n + 1), foll(n + 1);
  loop1(i, n) {
    cin >> r[i];
    foll[r[i]]++;
  }
  set<pair<ll, ll>> st;
  loop1(i, n) st.insert({ foll[i], i });
  ll ans = 2;
  queue<ll> q;
  while (!st.empty() and (*st.begin()).first == 0) {
    while (!st.empty() and (*st.begin()).first == 0) {
      ll k = (*st.begin()).second;
      auto it = st.find({ foll[r[k]], r[k] });
      foll[r[k]]--;
      if (it != st.end()) {
        st.erase(it);
        q.push(r[k]);
      }
      st.erase(st.begin());
    }
    while (!q.empty()) {
      st.insert({ foll[q.front()], q.front() });
      q.pop();
    }
    ans++;
  }
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
