#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 5;

void solve()
{
  string s; cin >> s;
  ll n = s.length();
  // 1709
  // 6109
  // 6710
  loop(i, n) {
    int curr = (int)(s[i] - '0'), idxCand = i;
    int mx = curr;
    loop1(j, 9) {
      if (i + j >= n) break;
      int cand = (int)(s[i + j] - '0');
      if (cand - j > mx) idxCand = i + j;
      mx = max(mx, cand - j);
    }
    if (idxCand != i) {
      s[idxCand] -= idxCand - i;
      char temp = s[idxCand];
      // cout << i << " " << idxCand << " " << s << endl;
      for (int j = idxCand; j >= i + 1; j--) {
        // if (i == 1) cout << s[j] << " ";
        s[j] = s[j - 1];
      }
      s[i] = temp;
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
