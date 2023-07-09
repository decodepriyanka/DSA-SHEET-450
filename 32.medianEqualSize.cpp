https://practice.geeksforgeeks.org/problems/find-the-median0527/1
Given an array arr[] of N integers, calculate the median
 

Example 1:

Input: N = 5
arr[] = 90 100 78 89 67
Output: 89

-----------------------Solution TC = O(nlogn)--------------------------------------------------
  	int find_median(vector<int> v)
		{
		    int median = 0;
		    // Code here.
		    sort(v.begin(),v.end());
		    int n = v.size();
		    if(n%2==0){
		       
		         median = (v[n/2]+v[n/2-1])/2;
		    }
		    else{
		       median = v[n/2];
		    }
		    return median ;
		}
