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
  string s; cin >> s;
  set<int> st;
  loop(i, s.length()) {
    st.insert(s[i]);
  }
  if (st.size() == 1) {
    cout << "NO" << endl; return;
  }

  cout << "YES" << endl;
  string s2 = s, s3 = s;
  sort(all(s2)); sort(rall(s3));
  if (s == s2) {
    cout << s3 << endl;
  }
  else {
    cout << s2 << endl;
  }


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
