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
  string s, t; cin >> s >> t;
  // track [length, s[i]];
  deque<pair<ll, ll>> a, b;
  loop(i, s.length()) {
    ll j = i;
    while (j + 1 < s.length() and s[j + 1] == s[i]) j++;
    a.push_back({ j - i + 1, s[i] });
    i = j;
  }

  loop(i, t.length()) {
    ll j = i;
    while (j + 1 < t.length() and t[j + 1] == t[i]) j++;
    b.push_back({ j - i + 1, t[i] });
    i = j;
  }


  ll ans = 0;
  while (a.size() and b.size()) {
    if (a[0].second == b[0].second) {
      if (a[0].first > b[0].first) { cout << -1 << endl; return; }

      b[0].first -= a[0].first;
      a.pop_front();
      if (b[0].first == 0) b.pop_front();
      continue;
    }

    if (a.size() == 1) { cout << -1 << endl; return; }

    if (a.size() == 2) {
      swap(a[0], a[1]);
    }
    else {
      a[2].first += a[0].first;
      a.pop_front();
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
