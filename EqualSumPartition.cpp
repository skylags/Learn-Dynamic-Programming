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
 Equal Sum Partition
 Here, in this problem, we're given an array.
 We have to tell whether we can divide the array into two parts such that
 sum of each subsets is same.
 Eg : {1,5,11,5}
 Answer : YES -> {1,5,5} & {11}
 It should be very clear that for the above to happen, the total sum of the array should
 be even. Otherwise, we can't divide that sum into two equal parts.
 Now, let total sum of array is S which is ofcourse even if we're here.
 The problem is reduced to just tell whether a subset is possible in the array whose sum is S/2,
 Other part will be automatically same.
 */

void isSubsetSum(int arr[], int n, int S)
{
    bool dp[n+1][S+1];
    /*
     Initialize the matrix as follows, for sum = 0, all n's are possible,
     but if n == 0, no sum is possible except sum = false
     Thus initialize first row as 0 and first column as true
     */
    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= S ; j++)
        {
            if(j == 0)
                dp[i][j] = true;
            else if(i == 0)
                dp[i][j] = false;
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
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    if(dp[n][S])
        cout << "Possible";
    else cout << "Not Possible";
    /*
     This will return number of subsets possible in arr[] whose sum is S.
     */
}
int32_t main()
{
    int n;
    cin >> n ;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    int S = 0;
    for(int i = 0 ; i < n ; i++)
        S += arr[i];
    /*
     Check whether it is even
     */
    if(S&1)
        cout << "Not Possible";
    else isSubsetSum(arr,n,S/2);
    /*
     Test Input
     5
     1 5 5 11 10
     Output
     Possible {1,5,10} and {5,11}
     */
}
/*
 Umang Agrawal
 */


