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
vector<int> minp(1e6 + 1, 0), prime;

void solve()
{
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  if (is_sorted(v.begin(), v.end())) {
    cout << "Bob" << endl; return;
  }

  int ls = 0, f = 0;
  for (auto a : v) {
    if (a == 1) {
      if (a < ls) {
        f = 1; break;
      }
    }
    else {
      int c = minp[a];
      while (c == minp[a]) {
        a /= c;
      }
      if (a > 1) {
        f = 1; break;
      }
      if (c < ls) {
        f = 1;
        break;
      }
      ls = c;
    }
  }

  cout << (f ? "Alice" : "Bob") << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  for (int i = 2; i <= 1e6; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      prime.push_back(i);
    }

    for (auto p : prime) {
      if (i * p > 1e6) break;
      minp[i * p] = p;
    }
  }

  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
