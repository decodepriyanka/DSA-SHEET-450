ques - https://practice.geeksforgeeks.org/problems/common-elements1132/1
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Example 1:

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.

  ----------------------------- Solution ---------------------------------------------------------------
   vector <int> commonElements (int ar1[], int ar2[], int ar3[], int n1, int n2, int n3)
        {
          int i = 0, j = 0, k = 0;
            vector<int> ans;
            int p1, p2, p3;
         
            p1 = p2 = p3 = INT_MIN;
         
            while (i < n1 && j < n2 && k < n3) {
               
                while (ar1[i] == p1 && i < n1)
                    i++;
         
                while (ar2[j] == p2 && j < n2)
                    j++;
         
                while (ar3[k] == p3 && k < n3)
                    k++;
         
                if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) {
                    ans.push_back(ar1[i]);
                    p1 = ar1[i];
                    p2 = ar2[j];
                    p3 = ar3[k];
                    i++;
                    j++;
                    k++;
                }
         
                else if (ar1[i] < ar2[j]) {
                    p1 = ar1[i];
                    i++;
                }
         
                else if (ar2[j] < ar3[k]) {
                    p2 = ar2[j];
                    j++;
                }
         
                else {
                    p3 = ar3[k];
                    k++;
                }
            }
            
            return ans;
