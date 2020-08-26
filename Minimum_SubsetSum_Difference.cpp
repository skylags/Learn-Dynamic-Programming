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
Minimum Subset Sum Difference
Here, in this problem, we're given an array.
We have to divide our array into two subsets and let their sum is S1 & S2.
We have to minimize the value of abs(S1-S2).
This is similar to Equal Sum Partition Problem where we have to divide such that S1 = S2.
Let's do a small analysis of the problem.
Assume total sum is Range. Thus, minimizing abs(S1-S2) is same as minimizing abs(S2-S1) &
which is also same as minimizing abs((Range-S1)-S1) which is thus minimizing (Range-2*S1).
This value is ofcourse should be near about Range/2.
Just the built dp[n+1][sum+1] matrix can be used to find the answer to this problem.
Refer to CountpfSubsetSum / EqualSumPartiton to explore what this matrix comprises.
Here we'll just push the last row's elements of that matrix up to Range/2 into a vector or a list, and
find the minimum value of (Range-2*v[i]), where v is name of vector/list and Range is total
sum of the array elements.
 */

int SubsetSum(int arr[], int n, int S)
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
    vector<int> v;
    int ans = LLONG_MAX;
    for(int i = 0 ; i <= S/2 ; i++)
    {
        if(dp[n][i])
            v.push_back(i);
    }
    for(int i = 0 ; i < v.size() ; i++)
        ans = min(ans,S-2*v[i]);
    
    return ans;
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
    
    cout << SubsetSum(arr,n,S);
    /*
     Test Input
     6
     2 3 3 2 13 1
     Output
     2 -> {2,3,3,2,1} & {13}
     */
}
/*
 Umang Agrawal
 */

