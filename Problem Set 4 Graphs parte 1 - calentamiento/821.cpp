#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  for (int ca = 1;; ++ca) {
    
    unordered_map<int, unordered_map<int, int>> g;
    int e = 0;
    int i, j;
    while (GET(i) && GET(j) && (i || j)) {
      ++e;
      g[i][j] = 1;
    }
    if (e == 0) break;

    
    vi nums;
    for (const auto& x : g) nums.push_back(x.first);
    for (int i : nums) {
      for (int j : nums) {
        if (i == j)
          g[i][j] = 0;
        else if (g[i].find(j) == g[i].end())
          g[i][j] = INT_MAX / 3;
      }
    }

    
    for (int k : nums)
      for (int i : nums)
        for (int j : nums) g[i][j] = min(g[i][k] + g[k][j], g[i][j]);

    
    int tot_length = 0;
    int tot = 0;
    for (int i : nums) {
      for (int j : nums) {
        if (i != j) {
          tot_length += g[i][j];
          ++tot;
        }
      }
    }

    printf("Case %d: average length between pages = %.3lf clicks\n", ca,
           double(tot_length) / tot);
  }
  return 0;
}