#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;

void solve()
{
  ll k, l1, r1, l2, r2; 
  cin >> k >> l1 >> r1 >> l2 >> r2;
  ll fc = 1, ans = 0;
  while(fc <= 1e9 && fc <= r2) {
    ll tottemp = 0;
    // binser lowest valid l2 <= x * fc <= r2
    ll l = 0, r = 1e9;
    while(l < r) {
      ll mid = (l+r)/2;
      if(mid * fc >= l2) r = mid;
      else l = mid + 1;
    }

    tottemp = l;
    // binser highest valid l2 <= x * fc <= r2
    l = 0, r = 1e9;
    while(l < r) {
        ll mid = (l+r)/2;
        if(mid < r2/fc) l = mid + 1;
        else r = mid;
    }

    if(tottemp > r1 || l1 > r) {
      fc*=k;
      continue;
    }
    ll templ = max(tottemp, l1);
    ll tempr = min(l, r1);
    // cout << fc << endl;
    // cout << templ << " " << tempr << " ";
    // cout << endl << "---" << endl;

    tottemp = tempr-templ+1;
    ans += tottemp;

    fc *= k;
  }
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ll t; cin>>t;
  while(t--)
  solve();

  return 0;
}
