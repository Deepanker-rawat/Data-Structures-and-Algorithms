// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
// Leetcode : https://leetcode.com/problems/counting-bits

vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        for(int i=1;i<=n; i++){
           ans[i] = ans[i & (i - 1)] + 1;
        }

        return ans;


}
