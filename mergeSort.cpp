MergeSort - Divide and merge 
TC - O(nlogn) , SC - O(n)
--------------------------------------------------------------------------------
  
#include <bits/stdc++.h>
using namespace std;


void merge(int arr[], int low, int mid,
		int high)
{
    vector<int>temp;
	int left =low;
	int right = mid+1;

	while (left<=mid && right<=high) {
		if (arr[left]<=arr[right]) {
		    temp.push_back(arr[left]);
		    left++;
		}
		else {
		temp.push_back(arr[right]);
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
}


void mergeSort(int arr[], int low, int high)
{
	if (low >= high)
		return;

	int mid =low + (high - low) / 2;
	mergeSort(arr,low, mid);
	mergeSort(arr, mid + 1, high);
	merge(arr, low, mid, high);
}


void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}


int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, n);

	mergeSort(arr, 0, n-1);

	cout << "\nSorted array is \n";
	printArray(arr, n);
	return 0;
}


