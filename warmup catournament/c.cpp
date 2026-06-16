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
  string s1, s2; cin >> s1 >> s2;
  sort(all(s1));
  sort(all(s2));

  string ans1 = "", ans2 = "";
  for (int i = 0; i < n; i++) {
    ans1 += s1[i];
    ans1 += s2[i];
  }
  for (int i = 0; i < n; i++) {
    ans2 += s2[i];
    ans2 += s1[i];
  }

  cout << min(ans1, ans2);

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  // ll t; cin >> t;
  // while (t--)
  solve();

  return 0;
}
