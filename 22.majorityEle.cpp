Ques - https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/
Given an array of size n and an integer k, find all elements in the array that appear more than n/k times. 

Examples:

Input: arr[] = {3, 1, 2, 2, 1, 2, 3, 3}, k = 4
Output: {2, 3}

------------------------- SOLUTION USING UNORDERED MAP , TC- O(N) , SC - O(N)------------------------------------------------------
  
#include <bits/stdc++.h>
using namespace std;

void majorityEle(int arr[], int n, int k)
{
	int x = n / k;

	unordered_map<int, int> freq;

	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}


	for (auto i : freq) {


		if (i.second > x) {

			cout << i.first << endl;
		}
	}
}


int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;

	majorityEle(arr, n, k);

	return 0;
}


-------------------------- SOLUTION 2  Moore’s Voting Algorithm -----------------------------------------------------------------
  
