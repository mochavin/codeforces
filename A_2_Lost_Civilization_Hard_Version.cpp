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
  for (auto& i : v) cin >> i;

  vector<pair<ll, ll>> st;
  ll ans = 0, temp = 0;

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() and st.back().first == v[i] + 1) {
      temp -= st.back().second;
      st.pop_back();
    }
    temp += n - i;
    ans += temp;
    st.push_back({ v[i], n - i });
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
