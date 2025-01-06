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
  ll n; cin >> n;
  string s; cin >> s;
  priority_queue<pair<ll, char>, vector<pair<ll, char>>, greater<pair<ll, char>>> pq;
  priority_queue<pair<ll, char>> pq2;
  map<char, ll> mp;
  loop(i, n) mp[s[i]]++;
  for (auto x : mp) {
    pq.push({ x.second, x.first });
    pq2.push({ x.second, x.first });
  }
  char least = pq.top().second;
  int f = 0;
  loop(i, n) {
    if (!f and s[i] == least) {
      f = 1;
      s[i] = pq2.top().second;
    }
  }
  cout << s << endl;
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
