// Given two integers m and n , return the position (1-based from the right) of the rightmost bit where they differ in binary, or -1 if both are identical.
int posOfRightMostDiffBit(int m, int n) {
        
        int count=1;
        while(m>0 or n>0){
            if((m&1) != (n&1)){
                return count;
            }
            
            count++;
            m>>=1;
            n>>=1;
        }
        
        return -1;
}
