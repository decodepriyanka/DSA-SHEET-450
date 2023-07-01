// ques - https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
// Given an array, rotate the array by one position in clock-wise direction.
/*

Input:
N = 5
A[] = {1, 2, 3, 4, 5}
Output:
5 1 2 3 4
*/

// ----------------------SOLUTION -------------------------
#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    int temp = arr[n-1]; // store the last element in temp 
    for(int i =n-1;i>=1;i--){
        arr[i]=arr[i-1];
    }
    arr[0] = temp;
    
}
int main()
{
    int n;
    cin >> n;
  
    int a[n];
 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
   
  rotate(a,n);
   for (int i = 0; i < n; i++)
    {
      cout<< a[i]<<" ";
    }
  
    return 0;
}
// --------------------Approach 2 -------------------
void rotate(int arr[], int n)
{
    vector<int> ans;
    ans.push_back(arr[n-1]);
    for(int i=0; i<n; i++ ){
        ans.push_back(arr[i]);
    }
    for(int i=0; i<n; i++ ){
        arr[i]=ans[i];
    }
