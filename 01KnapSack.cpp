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
 KnapSack Problem
 In this Problem, we are given two arrays wt[] , val[] & a capacity W.
 Basically, we have to choose items in such a manner that total value is maximum
 and total weight is less than or equal to maximum capacity W.
 01 Knapsack - means we can't take partial items, either take or not.
 */

//This is matrix in which we'll memorize our recursion
/* Consider n<=100 and W<=1000 */
int dp[102][1002];

/* Function for KnapSack (Recursive) */

int KnapSack_Recursive(int wt[], int val[], int W, int i)
{
    if(W == 0 or i == 0)
        return 0;
    /*
     At each step we have two choices include the current item or not
     It we can't, go to next item,
     If we can, take it once and leave it once, see what results in more value.
     */
    if(wt[i-1] <= W)
        return dp[i][W] = max(val[i-1] + KnapSack_Recursive(wt, val, W-wt[i-1] , i-1), KnapSack_Recursive(wt, val, W, i-1));
    else return dp[i][W] = KnapSack_Recursive(wt,val,W,i-1);
    return dp[i][W];
    /*
     Final Answer will be stored at this dp[i][W]
     which basically means total items i -> n and total weight -> W(Capacity)
     */
}

int KnapSack_TopDown(int wt[], int val[], int W, int n)
{
    /*
     Here, for the same Recursive Code, we'll write Top-Down Approach(without Recursion)
     Here, first we have to initialize our matrix for base conditions.
     */
    int dp[n+1][W+1];
    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= W ; j++)
            if(i ==0 or j ==0)
                dp[i][j] = 0;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= W ; j++)
        {
            if(wt[i-1] <= j)
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int32_t main()
{
    int n,w;
    cin >> n >> w;
    int wt[n],val[n];
    for(int i = 0 ; i < n ; i++)
        cin >> wt[i];
    for(int i = 0 ; i < n ; i ++)
        cin >> val[i];
    /*
     Testing for Some input
     4 7
     1 3 4 5
     1 4 5 7
     Output
     9
     9
     */
    cout << KnapSack_Recursive(wt,val,w,n);
    cout << "\n";
    cout << KnapSack_TopDown(wt,val,w,n);
}
/*
 Umang Agrawal
 */


