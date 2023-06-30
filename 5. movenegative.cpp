// ques - https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
#include <bits/stdc++.h>

using namespace std;

void reArrange(int arr[], int n)
{
    int l = 0, h = n - 1;
    while (l < h)
    {
        // case 1 - if l is negative and h is positive
        if (arr[l] < 0 && arr[h] > 0)
        {
            l++;
            h--;
        }
        // case 2 - if low is positive and high is negstive
        else if (arr[l] > 0 && arr[h] < 0)
        {
            swap(arr[l], arr[h]);
            l++;
            h--;
        }
        // case 3 - if both are negative
        else if (arr[l] < 0 && arr[h] < 0)
        {
            l++;
        }
        // case 4 - if both are positive
        else
        {
            h--;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    reArrange(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
