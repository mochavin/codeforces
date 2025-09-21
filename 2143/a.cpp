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
  vector<int> v(n + 1);
  loop1(i, n) {
    cin >> v[i];
  }

  int it = 1;
  for (int l = 1, r = n; l <= r;) {
    if (v[l] == it) l++;
    else if (v[r] == it) r--;
    else {
      cout << "NO" << endl; return;
    }
    it++;
    // cout << it << " ";
  }
  cout << "YES" << endl;
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
