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
  int n; cin >> n;
  vector<int> v(n);
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    pq.push({ v[i], i });
  }

  int ans = 0;
  int c = INT_MAX;
  while (!pq.empty()) {
    auto x = pq.top(); pq.pop();
    if (c < x.second) continue;
    c = x.second;
    ans++;
    if (x.second == 0) break;
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
