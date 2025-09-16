#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, W;
        cin >> n >> W;
        vector<int> wt(n), val(n);
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        for (int i = 0; i < n; i++)
            cin >> val[i];

        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int w = 1; w <= W; w++)
            {
                if (wt[i - 1] <= w)
                    dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
                else
                    dp[i][w] = dp[i - 1][w];
            }
        }
        cout << dp[n][W] << endl;
    }
}
