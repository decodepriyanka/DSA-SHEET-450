ques - https://leetcode.com/problems/next-permutation/
Input: nums = [1,2,3]
Output: [1,3,2]

----------------------Solution ------------------------------------
   void nextPermutation(vector<int>& nums) {
       int n = nums.size()-1;
       int inf = 0;
       for(int i=n;i>0;i--){
           if(nums[i]>nums[i-1]){
               inf = i;
               break;
           }
           
       }
       if(inf==0) { // case when elements are in drecreasing order 5 4 3 2 1 simply sort this
           sort(nums.begin(),nums.end());
           }
        else{
            int min = INT_MAX;
            int toswap = nums[inf-1];
            for(int j =inf;j<=n;j++){
                if(nums[j]-toswap>0 && nums[j]-toswap<min){
                   swap (nums[j], nums[inf-1]);
                }
            }
            sort(nums.begin()+inf,nums.end());
        }
        

    }

----------------------Solution 2 ------------------ TC - O(N)------------------------------
     void nextPermutation(vector<int>& a) {
     
        //find a[i]>a[i+1]
        int toswap=INT_MIN,withswap=INT_MIN;
        for(int i=a.size()-1;i>0;i--){
            if(a[i]>a[i-1]){
                toswap=i-1;
                break;
            }
        }
        //edge case
        if(toswap==INT_MIN) return reverse(a.begin(),a.end());
        //just greater element than toswap.
        else{
            for(int i=a.size()-1;i>toswap;i--){
                if(a[i]>a[toswap]){
                    withswap=i;
                    break;
                }
            }
            swap(a[toswap],a[withswap]);
            return reverse(a.begin()+toswap+1,a.end()); 
        }
    }
