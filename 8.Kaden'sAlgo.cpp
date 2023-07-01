// Ques - https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
/*Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) 
which has the maximum sum and return its sum

Example 1:

Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
*/
/*-------------------------------------APPROACH 1 ------------------------------------------------------*/
/* Brute force :T.C = O(N2) */
 long long maxSubarraySum(int arr[], int n){
        
   
   
        long long maxSum = INT_MIN;
        for(int i =0;i<n;i++){
               long long sum = 0;
          for(int j =i;j<n;i++){
              sum+=arr[i];
            maxSum = max(sum,maxSum);
          }
          
        }
        return maxSum;
       
        
    }

/*------------------------------------APPROACH 2 OPTIMISED-----------------------------------------------*/

 long long maxSubarraySum(int arr[], int n){
        
        long long sum = 0;
        long long maxSum = INT_MIN;
        for(int i =0;i<n;i++){
            sum+=arr[i];
            maxSum = max(sum,maxSum);
            if(sum<0)sum=0; // wheneven sum becomes negative just make sum equal to zero 
        }
        return maxSum;
       
        
    }


