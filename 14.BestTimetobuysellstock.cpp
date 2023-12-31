ques - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

  --------------------------Approach 1 -Naive TC - O(n2) --------------------------------------------------------------

   int maxProfit(vector<int>& prices) {
        int n = prices.size();
         int maxProfit = 0;
      for(int i =0;i<n;i++){
         
          for(int j = i+1;j<n;j++){
              if(prices[j]-prices[i]>maxProfit){
                maxProfit = prices[j]-prices[i];
              }
          }
      }
      return maxProfit;
    }
  --------------------------Approach 2 - TC - O(n) --------------------------------------------------------------------

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       int maxProfit = 0;
       int minPrice = prices[0];
       for(int i =0;i<n;i++){
           minPrice = min(minPrice,prices[i]);
           maxProfit = max(maxProfit,prices[i]-minPrice);
       } 
       return maxProfit;
    }
