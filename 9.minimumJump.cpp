ques - https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
Input:
N = 11 
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
Output: 3 
//---------------Solution---------------------------------------
   int jump(vector<int>& nums) {
        int far = 0;
				int jump = 0;
				int curr = 0;
				int n = nums.size();
				for(int i =0;i<n-1;i++){
           far = max(far,nums[i]+i);
					 if(i==curr){
						 curr=far;
						 jump++;
					 }
				}
				return jump;
    }
