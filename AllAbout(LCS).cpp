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
Longest Common Subsequence in a String, i.e, LCS
Here, we're given two strings, we need to find the longest common subsequence
available in both strings.
For eg: X : abcdgh , Y : abedfh
Here, LCS - abdh
 */

/*
Explanation of the Apprach used:
We start from last character say, if it matches, continue to next character,
If not matches, We have two options, 1. Leave current character of X and take complete Y.
2. Leave current character of Y and take complete X.
 */

/*
Let size of both string be less than a thousand.
For memorizing the recursion
 */
int dp[1002][1002];

int LCS(string X, string Y, int n,int m)
{
    if(m == 0 or n == 0)
        return 0;
    if(dp[n][m] != -1)
        return dp[n][m];
    if(X[n-1] == Y[m-1])
        return dp[n][m] = LCS(X,Y,n-1,m-1) + 1;
    return dp[n][m] = max(LCS(X,Y,n-1,m) , LCS(X,Y,n,m-1));
    return dp[n][m];
}

/*
 Similarly top down apprach can be written as
 */

int LCS_TOP_DOWN(string X, string Y, int n,int m)
{
    int dp[n+1][m+1];
    /*
     Initialize base conditions.
     */
    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= m ; j++)
            dp[i][j] = 0;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] +1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

/*
 This approach can be also used to solve Longest Common Substring Problem.
 Just we need to make dp[i][j] = 0 when we find different characters.
 */

 /*
  Printing LCS between two strings
  */

void printLCS(string X,string Y, int n,int m)
{
    /*
     First create the same dp matrix by any of the above two ways.
     Let's use the dp matrix(global) here.
     */
    
    int i = n , j = m;
    /*
     Start from last block[n-1,m-1],
     1. if equal -> (i--,j--)
     2. if unequal -> max({i--,j},{i,j--})
     */
    string common;
    while(i > 0 and j > 0)
    {
        if(X[i-1] == Y[j-1])
        {
            common.push_back(X[i-1]); // or Y[j-1]
            i--;
            j--;
        }
        else
        {
            //choose between (i-1,j) and (i,j-1) 
            if(dp[i-1][j] > dp[i][j-1])
            {
                i--;
            }
            else j--;
        }
    }
    /*
     Notice the string is formed in reverse manner.
     */
    reverse(common.begin(),common.end());
    cout << common;
}
int32_t main()
{
    int n,m;
    string X,Y;
    cin >> n >> m;
    cin >> X >> Y;
    /*
     Initialize the dp table as -1(unvisited).
     */
    memset(dp,-1,sizeof(dp));
    cout << LCS(X,Y,n,m) << "\n";
    printLCS(X,Y,n,m) ;
    return 0;
}
/*
 Umang Agrawal
 */


