#include <bits/stdc++.h>
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
  int n, k, p, m; cin >> n >> k >> p >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int ans = 0, val = v[p - 1];

  multiset<pair<int, int>> mt;
  for (int i = 0; i < k; i++) {
    if (i + 1 == p) {
      mt.insert({ -1, p });
    }
    else
      mt.insert({ v[i], i + 1 });
  }

  queue<pair<int, int>> q;
  for (int i = k; i < n; i++) {
    if (i + 1 == p) {
      q.push({ -1, p });
    }
    else
      q.push({ v[i], i + 1 });
  }

  if (k == n) {
    cout << m / v[p - 1] << endl; return;
  }

  while (m >= 0) {
    auto [cost, id] = *mt.begin();
    mt.erase(mt.begin());

    if (id == p) {
      // cout << cost << " ";
      q.push({ -1, id });
      if (m >= val) ans++;
      else break;
      m -= val;
      mt.insert(q.front()); q.pop();
      continue;
    }
    else {
      q.push({ cost, id });
      if (m >= cost) m -= cost;
      else break;
      mt.insert(q.front()); q.pop();
    }
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
