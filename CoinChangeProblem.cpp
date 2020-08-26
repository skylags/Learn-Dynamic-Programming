#include <bits/stdc++.h>
using namespace std;
#define int long long int

/*
What is Dynamic Programming.?
Basically, to recognize DP Problems, we have choices.
DP = Recursion + Some Memorization
In Recursive solution, we have a base condition and a choice diagram.
We memorize it to make DP.
*/

/*
Coin Change Problem
Given an array of coins[], denoting the types of denominations available.
Also, given a sum S, we have to find the maximum no of ways to select diiferent set of coins
such that total amount is S.
Basically, different configurations such that sum is S.
This problem is similar to Count of Subset Sum whose sum is S, but here, we may take a element
as many time as we want(Unbounded KnapSack type).
 */

int CoinChange(int coins[], int n, int S)
{
    int dp[n+1][S+1];
    /*
     Initialize the first row and column as zero similar we have done in
     01 KnapSack type(CountOfSubsetSum).
     */
    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= S ; j++)
        {
            if(j==0)
                dp[i][j] = 1;
            else if(i == 0)
                dp[i][j] = 0;
        }
    }
    /*
     Include it or discard it.
     Remember, including it doesn't mean it can't be included further,
     hence dp[i][j-coins[i-1]] is used here.
     */
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= S ; j++)
        {
            if(coins[i-1] <= j)
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][S];
}
int32_t main()
{
    int n,S;
    cin >> n >> S;
    int coins[n];
    for(int i = 0 ; i < n ; i++)
        cin >> coins[i];
    
    cout << CoinChange(coins,n,S);
    /*
     Test Input
     3
     1 2 3
     Output
     5
     */
    return 0;
}
/*
 Umang Agrawal
 */


