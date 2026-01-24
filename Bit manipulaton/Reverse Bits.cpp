// Reverse bits of a given 32 bits signed integer
// Leetcode: https://leetcode.com/problems/reverse-bits/description/?envType=problem-list-v2&envId=bit-manipulation

int reverseBits(int n) {
      int ans=0;

      for (int i = 0; i < 32; i++) {
            ans<<=1;
            ans = ans | (n&1);
            n>>=1;
        }

        return ans;
}
