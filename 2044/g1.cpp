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
  int n; cin >> n;
  vector<int> r(n + 1), d(n + 1);
  loop1(i, n) {
    cin >> r[i];
    d[r[i]]++;
  }
  set<pair<int, int>> s;
  loop1(i, n) {
    s.insert({ d[i], i });
  }

  int ans = 2;
  queue<int> q;
  while (s.size() && s.begin()->first == 0) {
    while (s.size() && s.begin()->first == 0) {
      int k = s.begin()->second; // index tidak ada yang nunjuk
      auto it = s.find({ d[r[k]], r[k] });
      d[r[k]]--;
      if (it != s.end()) {
        s.erase(it);
        q.push(r[k]);
      }
      s.erase(s.begin());
    }
    while (q.size()) {
      s.insert({ d[q.front()], q.front() });
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
