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
 Palindrome Partitioning Problem
 This problem is based on Matrix Chain Multiplication.
 Here, we are just given one string. We have to divide the string in minimum
 pieces such that all the resulting substrings formed are palindrome.
 What is maximum peices asked? We would just divide the string into n-1 pieces where n is
 the size of string because each individual character is palindrome.
 But here in this problem, we have to minimize this partitions.
 For eg : S = nitin, Here, the optimal partition will be 0 -> nitin.
 That itself is a palindrome.
 Hope you are now in pace with the problem statement.
 The approach is to just divide the string at each step, whenever found palindrome, we stop further
 partition.
 */
int dp[102][102];
//Assume size of string as 100.

bool isPalindrome(string s, int i, int j)
{
    if(i == j)
        return true;
    if(i > j)
        return false;
    while(i < j)
    {
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int MinPartition(string s,int i,int j)
{
    //Check for valid matrix available
    if(i >= j)
        return 0;
    if(isPalindrome(s,i,j))
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
        int temp = MinPartition(s,i,k) + MinPartition(s,k+1,j) + 1;
        
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
    string s;
    cin >> s;
    int n = s.size();
    /*
     Test Input 1
     nitin
     Output
     0
     Test Input 2
     CodedoC
     0
     Test Input 3
     abcde
     4
     */
    cout << MinPartition(s,0,n-1) << "\n";
    return 0;
}
/*
 Umang Agrawal
 */


