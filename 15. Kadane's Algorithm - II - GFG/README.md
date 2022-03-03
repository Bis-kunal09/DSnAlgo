# 15. Kadane's Algorithm - II
## Easy 
<div class="problem-statement">
                <p></p><div class="problemQuestion">
<p><span style="font-size:18px">You are given an array <strong>arr</strong> of size <strong>sizeOfArr</strong>. You need to find the <strong>maximum sum</strong> in the array provided that you cannot sum neighboring elements or adjacent elements.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>sizeOfArr = 4
arr[] = {4,5,6,7,8}
<strong>Output: </strong>18<strong>
Explanation:</strong>The given elements are 4 5 6 7 8
For 4, the maximum sum will be 4 as no
element other than 4 from index 0 to 0
For 5, the maximum sum will be 5 as we cannot
add 4 and 5(neighboring elements).
For 6, the maximum sum will be 10 as we can
add 6 and 4.
For 7, the maximum sum will be 12 as we can
add 7 and 5.
For 8, the maximum sum will be 18 as we can
add 4 and 6 and 8.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>sizeOfArr = 5
arr[] = {-9,-8,8,3,-4}
<strong>Output: </strong>8</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a <strong>function </strong>problem. You only need to complete the function <strong>maximumSum()&nbsp;</strong>that takes <strong>array </strong>and <strong>sizeOfArray </strong>and <strong>returns the maximum sum</strong> of the array provided that you cannot sum neighboring elements.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ sizeOfArr ≤ 10<sup>4</sup><br>
-10<sup>3</sup> ≤ arr<sub>i</sub> ≤ 10<sup>3</sup></span></p>
</div>
 <p></p>
            </div>