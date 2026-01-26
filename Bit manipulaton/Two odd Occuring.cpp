// Given an unsorted array, arr[] of positive numbers that contains even number of occurrences for all numbers except two numbers. Return that two numbers in decreasing order which has odd occurrences.
vector<int> twoOddNum(vector<int>& arr) {
        int temp =0;
        
        for(int i=0; i<arr.size();i++){
            temp^=arr[i];
        }
        
        int check = temp & (-temp);  // unset right most set bit
        int ansA=0, ansB=0;
        
        for(int i=0;i<arr.size();i++){
            if(check & arr[i]){  
                ansA ^=  arr[i];
            }
            else{
                ansB ^=arr[i];
            }
        }
        
        return (ansB > ansA ? vector<int>{ansB,ansA} : vector<int>{ansA, ansB});
        
    }
