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
  int n, m, k; cin >> n >> m >> k;
  vector<int> a(n), b(m + 2);
  b[0] = INT_MIN;
  b[m + 1] = INT_MAX;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < m + 1; i++) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  map<int, vector<int>> prl;
  map<int, vector<int>> prr;
  set<int> st;
  for (int i = 0; i < n; i++) st.insert(i);
  int c = 1;
  for (int i = 0; i < n; i++) {
    while (b[c] < a[i]) c++;
    prl[a[i] - b[c - 1]].push_back(i);
    prr[b[c] - a[i]].push_back(i);
  }

  string s; cin >> s;
  c = 0;
  for (int i = 0; i < k; i++) {
    if (s[i] == 'L') c--;
    else c++;

    if (c < 0) {
      for (auto x : prl[-c]) {
        st.erase(x);
        // cout << x << " ";
      }
    }
    else {
      for (auto x : prr[c]) {
        st.erase(x);
      }
    }
    cout << st.size() << " ";
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
