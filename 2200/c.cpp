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
  string s; cin >> s;
  stack<char> st;
  for (int i = 0; i < n; i++) {
    if (st.size()) {
      if (st.top() == s[i]) st.pop();
      else st.push(s[i]);
    }
    else {
      st.push(s[i]);
    }
  }
  cout << (st.empty() ? "YES" : "NO") << endl;

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
