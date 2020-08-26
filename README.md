# Learn-Dynamic-Programming
Dynamic Programming Standard Problems.

Some basic DP Problems based on Longest Common Subsequence(LCS) :
Consider X and Y as two strings whose lengths are m & n respectively,
1. Shortest Common SuperSequence : It's nothing but SCS(X,Y) = (m+n-LCS(X,Y)).
SCS means a shortest sequence containing both strings X & Y.
2. Minimum No of Insertion & Deletion to convert A->B : Let m > n then, Delete Operations = m-LCS(X,Y) and Insert Operations = n-(LCS(X,Y).
3. Longest Palindromic Subsequence : LPS(X) = LCS(X,reverse(X)).
4. Minimum No of Deletions to make a string palindrome : Length of string - LPS(X).
5. Printing SCS - Similar to printing LCS as discussed above with some minute code variations.
6. Longest Repeating Subsequence : Here, the whole subsequence must repeat in the string. We just add a condition where current indexes shouldn't be equal. The code remains same as in LCS.
7. Sequence Pattern Matching : Here, we just check if size of pattern equals LCS of both the strings.
