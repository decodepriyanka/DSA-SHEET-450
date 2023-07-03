ques - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).

-----------------------Approach 1 Naive - TC : O(n2) --------------------------------------------------
   long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        int inv =0; 
        for(int i=0; i<N-1; i++){
            for(int j=i+1; j<N; j++){
                if(arr[i]>arr[j]){
                    inv++;
                }
            }
        }
        return inv;
    }
--------------------------------Approach 2 - optimised TC : O(nlogn)  ------------------------------------------------
   This problem can be solved by using merge sort algo . When you are merging the two array check if right array is smaller that left one and increment the counter accordingly
int merge(vector<int>&arr, int low, int mid,
		int high)
{
    vector<int>temp;
	int left =low;
	int right = mid+1;
   int c=0;
	while (left<=mid && right<=high) {
		if (arr[left]<=arr[right]) {
		    temp.push_back(arr[left]);
		    left++;
		}
        //right is smaller 
		else {
		temp.push_back(arr[right]);
        c+=(mid-left+1);
		right++;
		}
	
	}


	while (left<=mid) {
	 temp.push_back(arr[left]);
	 left++;
	}

	
	while (right<=high) {
	temp.push_back(arr[right]);
	right++;
	}
for(int i =low ;i<=high;i++){
    arr[i]=temp[i-low];
}
return c ;
}


int mergeSort(vector<int>&arr, int low, int high)
{ 
     int c = 0;
	if (low >= high)
		return c ;

	int mid =low + (high - low) / 2;
	c+=mergeSort(arr,low, mid);
	c+=mergeSort(arr, mid + 1, high);
	c+=merge(arr, low, mid, high);
    return c ;
}


int numberOfInversions(vector<int>&a, int n) {
    return mergeSort(a,0,n-1);
    
}

  
