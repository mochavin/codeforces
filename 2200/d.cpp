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
  int n, x, y; cin >> n >> x >> y;
  vector<int> v(n), in, out;
  int f = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (i >= x and i < y) {
      in.push_back(v[i]);
      if (v[i] == 1) f = 1;
    }
    else out.push_back(v[i]);
  }
  pair<int, int> mnIn = { M, M };
  for (int i = 0; i < in.size(); i++) {
    if (mnIn.first > in[i]) mnIn = { in[i], i };
  }
  vector<int> inn;
  for (int i = 0; i < in.size(); i++) {
    inn.push_back(in[(i + mnIn.second) % in.size()]);
  }

  // f == 0, v[i] == 1 ada di luar
  if (!f) {
    int tx = -1;
    for (int i = 0; i < out.size(); i++) {
      if (out[i] > mnIn.first) {
        break;
      }
      tx = i;
      cout << out[i] << " ";
    }
    for (auto x : inn) cout << x << " ";
    for (int i = tx + 1; i < out.size(); i++) {
      cout << out[i] << " ";
    }
    cout << endl; return;
  }

  // f == 1, v[i] == 1 di dalam
  for (auto x : inn) cout << x << " ";
  for (auto x : out) cout << x << " ";
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
