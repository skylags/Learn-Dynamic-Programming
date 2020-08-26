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
 Subset Sum Problem
 Here, in this problem, we're given an array and a sum S.
 We have to tell whether a subset existes in the array such that
 the sum of its elements equals S.
 Eg : {2,3,7,8,10}
 S : 11
 Answer : YES -> {3,8}
 Basically, here also we'll fill our dp[n+1][sum+1] and thus our answer will
 be stored in dp[n][sum]
 This is a variation of KnapSack Problem, because here also either we include
 the current elemet or discard it, same as in item selection of 01 KnapSack.
 */

int SubsetSum(int arr[], int n, int S)
{
    int dp[n+1][S+1];
    /*
     Initialize the matrix as follows, for sum = 0, all n's are possible,
     but if n == 0, no sum is possible except sum = 0
     Thus initialize first row as 0 and first column as 1.
     */
    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= S ; j++)
        {
            if(j == 0)
                dp[i][j] = 1;
            else if(i == 0)
                dp[i][j] = 0;
            else dp[i][j] = 0;
        }
    }
    /*
     Now, fill the matrix same as we filled in 01 KnapSack Problem.
     */
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= S ; j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][S];
    /*
     This will return number of subsets possible in arr[] whose sum is S.
     */
}
int32_t main()
{
    int n,S;
    cin >> n >> S;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    cout << SubsetSum(arr,n,S) ;
    /*
     Test Input
     
     */
}
/*
 Umang Agrawal
 */


