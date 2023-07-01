ques - https://leetcode.com/problems/find-the-duplicate-number/description/
Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

  --------------------Approach 1 --------------------------------------
  sort the array and find the index of duplicate element .TC: O(NLOGN)

int findDuplicate(vector<int>& nums) {
        int ind;
         sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() - 1; i++)
        {
			
            if(nums[i] == nums[i+1])
            {
               ind = nums[i];
                break;
            }
        }
       
        return ind;
    }

--------------------Approach 2 -----------------------------------------------------

  Unordered_set

   int findDuplicate(vector<int>& nums) {
    // using sets 
     unordered_set<int>s;
     for(int i =0;i<nums.size();i++){
         if(s.find(nums[i])!=s.end()){
             return nums[i];
         }
         s.insert(nums[i]);
     }   
  return -1;
    }

---------------------------Approach 3 ---------------------------------BEST APPROACH USING SLOW , FAST POINTER METHOD ------------------


    int findDuplicate(vector<int>& nums) {
      int slow = nums[0]; 
    int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
            
        }while(slow!=fast);
        fast = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
       return slow; 
    }
 
