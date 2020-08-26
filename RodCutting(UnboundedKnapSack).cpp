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
Rod Cutting Problem
Given a rod of n metres and price of different parts of sizes 1,2,3,...n
We have to cut the rod into pieces such that the sum of price of all pieces is maximum possible.
This is a variation of unbounded knapsack where we have infinite supply of items and we
may take as many items as we want unlike 01 Knapsack where either we take a item once or discard it.
 */

int RodCutting(int n,int price[])
{
    /*
     Take a dp array. Wait! Why 1-D array here and 2-D array in 01 KnapSack.?
     Because here, only one quantity is changing over time, which is n, i.e, we'll take 1,2,3,..n.
     But previously, input had two variables which was n and sum or the target which we wanted to reach with
     each problem.
     */
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 0 ; j < i ; j++)
            dp[i] = max(dp[i], price[j] + dp[i-j-1]);
    }
    /*
     Return last entry
     */
    return dp[n];
}
int32_t main()
{
    int n;
    cin >> n;
    int price[n];
    for(int i = 0 ; i < n ; i++)
        cin >> price[i];
    
    cout << RodCutting(n,price);
    /*
     Test Input
     8
     1,5,8,9,10,17,17,20
     Output
     22
     */
    return 0;
}
/*
 Umang Agrawal
 */


