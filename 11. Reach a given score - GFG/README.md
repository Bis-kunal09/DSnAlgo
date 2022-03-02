# 11. Reach a given score
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Consider a game where a player can score <strong>3</strong> or <strong>5</strong> or <strong>10</strong> points in a move. Given a total score <strong>n</strong>, find the number of distinct combinations&nbsp;to reach the given score.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>n = 8
<strong>Output: </strong>1<strong>
Explanation:</strong>when n = 8,{3,5} and {5,3}
are the two possible permutations but
these represent the&nbsp;same cobmination.
Hence output is 1.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>n = 20
<strong>Output: </strong>4<strong>
Explanation:</strong>When n = 20, {10,10},
{5,5,5,5},{10,5,5} and {3,3,3,3,3,5}
are different possible permutations.
Hence output will be 4.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
Complete <strong>count()&nbsp;</strong>function which takes N as an argument and returns the&nbsp;<strong>number of ways/combinations</strong> to reach the given score.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span><br>
<span style="font-size:18px">1 ≤ n ≤ 1000</span></p>
 <p></p>
            </div>