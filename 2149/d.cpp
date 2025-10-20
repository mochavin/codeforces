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
  ll n; cin >> n;
  string s; cin >> s;
  ll ca = 0, cb = 0;
  loop(i, n) {
    if (s[i] == 'a') ca++;
    else cb++;
  }
  ll mna = LLONG_MAX, mnb = LLONG_MAX;
  ll cura = 0, curb = 0, ansa = 0, ansb = 0;
  loop(i, n) {
    if (s[i] == 'a') {
      ll kanan = --ca;
      ansa += min(i - cura, n - kanan - 1 - i);
      // cout << i - cura << " ";
      cura++;
    }
    else {
      ll kanan = --cb;
      ansb += min(i - curb, n - kanan - 1 - i);
      curb++;
    }
    // cout << ansa << " " << ansb << endl;
  }
  cout << min(ansa, ansb) << endl;

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
