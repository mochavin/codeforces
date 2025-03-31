#include <bits/stdc++.h>
#include <iostream>
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
  ll n, k; cin >> n >> k;
  string s; cin >> s;
  string sr = "";
  set<char> st;
  loop(i, n) {
    sr += s[n - i - 1];
    st.insert(s[n - i - 1]);
  }
  if (st.size() <= 1) {
    cout << "NO" << endl; return;
  }
  int f = 0;
  loop(i, n) {
    if (s[i] < sr[i]) {
      cout << "YES" << endl; return;
    }
    else if (s[i] > sr[i]) {
      cout << (k > 0 ? "YES" : "NO") << endl;
      return;
    }
  }
  cout << (k > 0 ? "YES" : "NO") << endl;

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
