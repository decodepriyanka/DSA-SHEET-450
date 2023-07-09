------------------Solution 1 Naive TC - O(n1+n2) , SC - 0(n1+n2) by using simple merge method  ----------------------------------------
Intuition : Take two pointer i and j 
Lets pointer i standing at nums1[0] & j standing at nums2[0]
Whicheven is smaller take it and push in the ds and increment that pointer, do this till both the array reaches end 
after that we will be getting out merged array now if merged array length is :
even = median = (n/2+n/2-1)/2;
Odd = median = n/2
  
 ------- ---------------------------------------------
  
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         vector<int> merged;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()) {
            merged.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()) {
            merged.push_back(nums2[j]);
            j++;
        }
        int mid = merged.size() / 2;
        if ((merged.size() % 2) == 0) {
            return float(merged[mid - 1] + merged[mid]) / 2;
        } else {
            return float(merged[mid]);
        }
    }

-----------------------------Solution 2 Optimised ---------------------------------------------------------------------------

  
