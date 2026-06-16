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
  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto& i : a) cin >> i;
  for (auto& i : b) cin >> i;
  ll suma = accumulate(a.begin(), a.end(), 0ll);
  ll sumb = accumulate(b.begin(), b.end(), 0ll);
  if (suma != sumb) {
    cout << "No" << endl; return;
  }

  multiset<int> aa, bb;
  for (auto x : a) aa.insert(x);
  for (auto x : b) bb.insert(x);

  while (!bb.empty()) {
    auto x = bb.begin();
    auto f = aa.find(*x);
    while (aa.find(*x) == aa.end()) {
      if (*x <= *aa.begin()) {
        cout << "No" << endl; return;
      }

      if (bb.empty()) {
        cout << (aa.empty() ? "Yes" : "No") << endl;
      }
      int in = *x;
      bb.erase(x); bb.insert(in / 2); bb.insert((in + 1) / 2);
      x = bb.begin();
    }

    aa.erase(aa.find(*x));
    bb.erase(x);
  }

  cout << "Yes" << endl;
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
