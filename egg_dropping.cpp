#include <bits/stdc++.h>
using namespace std;

int minTrials(int n, int k)
{
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    int m = 0;
    while (dp[m][n] < k)
    {
        m++;
        for (int x = 1; x <= n; x++)
        {
            dp[m][x] = 1 + dp[m - 1][x - 1] + dp[m - 1][x];
        }
    }
    cout << "\nThe dp table made using memoization is:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return m;
}
int main()
{
    int n, k;
    cout << "Enter the number of total floors in the building: ";
    cin >> k;
    cout << "Enter the number of eggs available for tests: ";
    cin >> n;
    int res = minTrials(2, 36);
    cout << "Minimum number of trials "
            "in worst case with "
         << n << " eggs and " << k << " floors is ";
    cout << res;
    return 0;
}
