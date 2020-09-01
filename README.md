# Learn-Dynamic-Programming
Dynamic Programming Standard Problems.

Follow Standard DP Problems in the following order, you'll find almost all of them similar,

1. 0/1 KnapSack Problem.
2. Subset Sum Problem.
3. Equal Sum Partition Problem.
4. Count of Subset with given sum.
5. Minimum Subset Sum Difference Problem.
6. Count number of subsets sum with given difference.
7. Target Sum Problem.(Same as 6).
8. Unbounded KnapSack Problem.
9. Rod Cutting Problem.
10. Coin Change Problem(Max No of Ways).
11. Coin Change Problem(Min No of Coins).

Some basic DP Problems based on Longest Common Subsequence(LCS) :
Consider X and Y as two strings whose lengths are m & n respectively,

0. Longest Common Subsequence(Length and printing it both)
1. Shortest Common SuperSequence : It's nothing but SCS(X,Y) = (m+n-LCS(X,Y)).
SCS means a shortest sequence containing both strings X & Y.
2. Minimum No of Insertion & Deletion to convert A->B : Let m > n then, Delete Operations = m-LCS(X,Y) and Insert Operations = n-(LCS(X,Y).
3. Longest Palindromic Subsequence : LPS(X) = LCS(X,reverse(X)).
4. Minimum No of Deletions to make a string palindrome : Length of string - LPS(X).
5. Printing SCS - Similar to printing LCS as discussed above with some minute code variations.
6. Longest Repeating Subsequence : Here, the whole subsequence must repeat in the string. We just add a condition where current indexes shouldn't be equal. The code remains same as in LCS.
7. Sequence Pattern Matching : Here, we just check if size of pattern equals LCS of both the strings.
## DP tutorials and Problem lists
The link below contains links to various DP Learning Resources, You Tube Tutorials, DP related Contests and various typed of DP Problems and link to solve them.<br>
https://codeforces.com/blog/entry/67679
