What you have learnt till now about getting ACs:
------------------------------------------------

1. `long long`. Remember. Always.
2. Global variables, if you have the slightest doubt they will overflow.
3. Garbage values are a bitch in C++. Always look out.
4. Out of index creeps in very easy. Look out.
5. Use printf if your solution seems like it will barely pass.
6. Just because you think you know how to solve the problem, does not mean you will.
7. `long long` initializes slower than `int`.
8. Your DP might be overcounting (eg with overlapping tiling problems).
Always do a mental image.
9. Your DP might not be checking all cases (for any general DP), try to induce mentally.
10. Question your sanity.
11. Don't forget the modulus.
12. First time AC is good but not the most important. You can test
the waters using a simple submission. Or maybe if you think you can brute force it
and ensure some points, do it before going on to implement large solution.


Nice problems to look through:
------------------------------

**Note:** Needs a lot of updating. Look through all problem solutions
just to be safe.

1. [Ladder](http://codeforces.com/problemset/problem/279/C)
   Cute DP.
2. [Xor Tree](http://codeforces.com/problemset/problem/429/A)
   Amazing DFS problem!
3. [To Add or Not to Add](http://codeforces.com/problemset/problem/231/C)
   Good question. Teaches you how to make functions that are monotonic and binary search through
   them to reduce complexity. Here it goes from O(N²) to O(N lg N)
