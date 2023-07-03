ques - https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.


Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.

---------------------------Approach 1 Naive ---- TC : O(n2)-----------------------------------------------------------
 int getPairsCount(int arr[], int n, int k) {
        // code here
        int count = 0;
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                if(arr[i]+arr[j]==k){
                    count++;
                }
            }
        }
        return count;
    }
------------------------------Approach 2 --- TC :O(n) ----------------------------------------------------------------------
 int getPairsCount(int arr[], int n, int k) {
        int c = 0;
      unordered_map<int,int>mp;
      for(int i =0;i<n;i++){
          if(mp.find(k-arr[i])!=mp.end()){
              c= c+mp[k-arr[i]];
          }
          mp[arr[i]]++;
      }
      return c;
    }
