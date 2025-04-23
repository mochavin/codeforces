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
  int n, k; cin >> n >> k;
  vector<ll> a(n);
  int f = 0;
  loop(i, n) {
    cin >> a[i];
    if (a[i] == 0) f++;
  }
  if (f < k) {
    cout << 0 << endl; return;
  }
  vector<ll> v;
  if (k == 1) {
    sort(all(a));
    int ls = 0;
    loop(i, n) {
      if (a[i] == ls) ls++;
    }
    cout << ls << endl; return;
  }
  else if (k == n) {
    cout << (f == n ? 1 : 0) << endl; return;
  }

  int ans = 0;
  set<int> st;
  // loop1(i, (n + k - 1) / k) {
  //   int c = 0;
  //   loop(j, n) {
  //     if (a[j] < i) st.insert(a[j]);
  //     if (st.size() == i) {
  //       c++;
  //       st.clear();
  //     }
  //   }
  //   if (c >= k) ans = i;
  //   st.clear();
  // }

  ll l = 0, r = n;
  while (l < r) {
    int c = 0, mid = (l + r + 1) / 2;
    loop(i, n) {
      if (a[i] < mid) st.insert(a[i]);
      if (st.size() == mid) {
        c++; st.clear();
      }
    }
    // cout << mid << " ";
    if (c >= k) l = mid;
    else r = mid - 1;
    st.clear();
  }

  cout << l << endl;

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
