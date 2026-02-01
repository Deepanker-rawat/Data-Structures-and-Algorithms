int countBitsFlip(int a, int b) {
      
      int temp = a^b;
      
      return __builtin_popcount(temp);
        
    }
