#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 5;

void solve()
{
  int n; cin >> n;
  vector<int> v(n), ans(n, -1);
  loop(i, n) {
    cin >> v[i];
    v[i]--;
  }
  string s; cin >> s;
  loop(i, n) {
    if (ans[i] != -1) continue;
    vector<int> bl;
    int it = v[i], sum = (s[i] == '0' ? 1 : 0);
    bl.push_back(i);
    while (it != i) {
      bl.push_back(it);
      if (s[it] == '0') sum++;
      it = v[it];
    }
    loop(j, bl.size()) {
      ans[bl[j]] = sum;
    }
  }
  loop(i, n) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
