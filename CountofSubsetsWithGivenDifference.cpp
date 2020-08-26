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
No of Subsets with given difference.
Find no of subset pairs such that difference of both of them is dif(given).
Assume sum of both subsets as S1-S2.
Find no of subsets pairs such that S1-S2 = dif, where dif will be given in the problem.
Let's analyse a bit.
Assume Sum as total sum of array elements.
S1-S2 = dif ->(1)
S1+S2 = Sum ->(2)
Solving the above (1) & (2), we get,
S1 = (Sum+dif)/2 - (3),
Hence, this problem is reduced to finding the no of Subsets whose sum is S1 as calculated
in (3).
Refer to CountofSubsetsSum above for the approach to do this . :)
 */


/*
 Umang Agrawal
 */


