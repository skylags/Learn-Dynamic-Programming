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
Coin Change Problem(Minimum No of Coins to make a sum S)
Given an array of coins[], denoting the types of denominations available.
Also, given a sum S, we have to find the minimum no of coins to select diiferent set of coins
such that total amount is S.
This is similar to other problems as well but it requires some extra initialisation.
Here, we need to initialize the second row of matrix according to the sum divisible by
each of the types of coins.
 */

int MinCoinChange(int coins[], int n, int S)
{
    int dp[n+1][S+1];
    /*
     Initialize the first row and column as zero similar we have done in
     01 KnapSack type(CountOfSubsetSum).
     */
    int MAX = 99999;
    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= S ; j++)
        {
            if(i==0)
                dp[i][j] = MAX-1;
            else if(j == 0)
                dp[i][j] = 0;
        }
    }
    /*
     Initialize second row of matrix
     */
    for(int i = 1 ; i <= S ; i++)
    {
        if(i % coins[0] == 0)
            dp[1][i] = i/coins[0];
        else dp[1][i] = MAX-1;
    }
    /*
     Include it or discard it.
     Remember, including it doesn't mean it can't be included further,
     hence dp[i][j-coins[i-1]] is used here.
     */
    for(int i = 2 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= S ; j++)
        {
            if(coins[i-1] <= j)
                dp[i][j] = min(dp[i][j-coins[i-1]]+1 , dp[i-1][j]);
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
    
    cout << MinCoinChange(coins,n,S);
    /*
     Test Input
     3 5
     1 2 3
     Output
     2
     */
    return 0;
}
/*
 Umang Agrawal
 */


