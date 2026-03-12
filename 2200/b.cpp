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
  vector<int> v(n), c(101, 0);
  int f = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    c[v[i]]++;
    if (i) {
      if (v[i] < v[i - 1]) f = i + 1;
    }
  }
  if (!f) {
    cout << n << endl; return;
  }

  cout << 1 << endl;


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
