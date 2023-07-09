Ques - https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10

---------------------- Naive Solution , TC - 0(N2)--------------------------------------------------------------------------
   long long trappingWater(int arr[], int n){
        // code here
        long long res = 0;
        for(int i =1;i<n-1;i++){  // we are starting from index 1 to n-2 because the corner bars cant support the water
            int lMax = arr[i]; 
            for(int j =0;j<i;j++){
                lMax = max(lMax,arr[j]);
            }
            int rMax = arr[i]; // find the right max
             for(int j =i+1;j<n;j++){
                rMax = max(rMax,arr[j]);
            }
            res = res+ (min(lMax,rMax)-arr[i]);
            
        }
        return res;
    }
----------------------- Efficient Solution  0(N)-------------------------------------------------------------------------------------
Intuition - Precompute the leftmost bar and rightmost bar . 
Initialize two arrays as left and right . find the left max for every element ,similarly do it for right one 
 long long trappingWater(int arr[], int n){
      
        long long res = 0;
        int lMax[n], rMax[n];
        lMax[0] = arr[0];
        rMax[n-1] = arr[n-1];
        for(int i =1;i<n;i++) lMax[i] = max(arr[i],lMax[i-1]);
        
        for(int i = n-2;i>=0;i--)  rMax[i] = max(arr[i],rMax[i+1]);
        
        for(int i =1;i<n-1;i++)    res = res + min(lMax[i],rMax[i])-arr[i];
        
        return res ;
      
    }
  
