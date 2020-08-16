Problem
-------

Given a circular array of N elements, find the maximum sum subarray

Idea
----

Two cases for max sum subarray:
1. Proper subarray of the array, i.e no looping around
Use normal Kadane's to find this one
2. Circular subarray, i.e it wraps around
[3, -1, 2, -1]
Answer to this is [2, -1, 3] or [3, -1, 2], first of which wraps around
Notice the other left over subarray from using [2, -1, 3]
You get [-1], which is a minimum subarray.

Now the idea is that if you find the minimum proper subarray in the array, the
complement array is the maximum sum subarray.
To find minimum sub proper subarray, use Kadane's on negated array.
On negated array, the max sum subarray will be min sum on actual array.

Then just deduct from total sum and take max of Case 1 and Case 2.


