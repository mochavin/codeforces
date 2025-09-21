#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define loop(i,h) for(int i=0;i<h;i++)
#define loop1(i,h) for(ll i=1;i<=h;i++)
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int MOD = 998244353;
const int N = 2e5 + 1;

void solve() {
  ll k; cin >> k;
  // 10^0 . 9 . 1 ; 10^2 . 9 . 2 ;
  ll l = 1, po = 9;
  while (k - po * l > 0) {
    k -= po * l;
    po *= 10; l++;
  }
  ll ans = 0;
  string ls = to_string(po / 9 + (k - 1) / l);
  for (int i = 0; i < (k % l == 0 ? l : k % l); i++) {
    ans += ls[i] - '0';
  }

  ll pref = 0;
  loop(i, ls.size()) {
    ll cd = ls[i] - '0';
    if (cd) {
      // ans += (cd-1) * 10 * (l-1)
    }
    l--;
    pref += cd;
    po /= 10;
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



