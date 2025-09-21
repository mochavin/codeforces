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
  vector<ll> v(n), pre(n + 1, 0);
  loop(i, n) {
    cin >> v[i];
    pre[i] = v[i];
    if (i) pre[i] += pre[i - 1];
    pre[i] %= 3;
  }
  // for (auto x : pre) cout << x << " ";
  loop(i, n) {
    for (int j = i + 1; j < n - 1; j++) {
      ll s1 = pre[i], s2 = pre[j] - pre[i], s3 = pre[n - 1] - pre[j];
      s1 = (s1 + 3) % 3;
      s2 = (s2 + 3) % 3;
      s3 = (s3 + 3) % 3;
      // cout << s1 << " " << s2 << " " << s3 << " ";
      if ((s1 != s2 and s1 != s3 and s2 != s3) || (s1 == s2 and s1 == s3)) {
        // cout << s1 << " " << s2 << " " << s3 << " ";
        cout << i + 1 << " " << j + 1 << endl; return;
      }
    }
  }
  cout << "0 0" << endl;
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
