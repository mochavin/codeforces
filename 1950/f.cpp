#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 5;

void solve()
{
  ll a, b, c;cin >> a >> b >> c;
  if (a + 1 != c) {
    cout << -1 << endl;
    return;
  }
  if (a + b + c == 1) {
    cout << 0 << endl; return;
  }

  ll curr = 1, child = 0, ans = 1;
  loop(i, a + b) {
    if (curr == 0) {
      swap(child, curr);
      ans++;
    }
    curr--;
    child += (i < a ? 2 : 1);
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
