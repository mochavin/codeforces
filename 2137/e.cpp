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
  ll n, k; cin >> n >> k;
  vector<ll> v(n);
  map<ll, ll> mp;
  loop(i, n) {
    cin >> v[i];
    mp[v[i]]++;
  }
  sort(all(v));
  for (auto x : v) cout << x << " ";
  cout << endl;
  ll ans = 0;
  // klo C(0) >= 2, maka 2 langkah auto 0 0 0 0
  // klo == 1
  // klo ada bilangan yang C(x) >= 2, maka akan macet di x
  
  // klo == 0, maka 1 langkah auto 0 0 0 0
  if(v[0] != 0) {
    cout << (k%2 ? 0 : n) << endl; return;
  }
  
  loop(i, n+1) {
    ans+=i;
    // klo ada bilangan C(x) == 0, 0 1 1 1 1 atau 0 2 2 2 2
    if(!mp.count(i)) {
    }
  }

  // 0 1 2 3 4 6 6 8 
  // 0 1 2 3 4 5 5 5

  // 0 2 3 4
  // 0 1 1 1
  // 0 2 2 2
  // 0 1 1 1

  // 0 1 1 3 4
  // 0 2 2 2 2
  // 0 1 1 1 1

  // 0 1 2 2 3 4
  // 0 1 5 5 3 4
  // 0 1 2 2 2 2
  // 0 1 2 2 2 2


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
