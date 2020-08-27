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
 Matrix Chain Multiplication
 This is a very special + interesting problem.
 Here, we have a list of some matrices. We have to apply brackets in such
 a manner such that the total cost of multiplying all of them is minimum possible.
 For your info : Cost of Multiplying two matrix of order a*b and b*c = a*b*c.
 We have to minimize the total cost.
 Basically, the idea is to put brackets at every possible place and find the answer.
 */
int dp[102][102];
//Assume there are 100 matrices
int MatrixChain(int arr[],int i,int j)
{
    //Check for valid matrix available
    if(i >= j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    //Assume this as answer
    int ans = LLONG_MAX;
    for(int k = i ; k < j ; k++)
    {
        /*
         Temporary answer
         */
        int temp = MatrixChain(arr,i,k) + MatrixChain(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        
        ans = min(ans,temp);
    }
    
    return dp[i][j] = ans;
}

int32_t main()
{
    /*
     Initialize dp table
     */
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    /*
     Test Input
     5
     40 20 30 10 30
     Output
     26000
     */
    cout << MatrixChain(arr,1,n-1) << "\n";
    return 0;
}
/*
 Umang Agrawal
 */


