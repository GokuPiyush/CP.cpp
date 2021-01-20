/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return 0;
        vector<int> left(n, 0);
        left[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--)
            left[i] = max(prices[i], left[i+1]);
        int ans=0;
        for(int i=0; i<n; i++)
            ans = max(ans, left[i]-prices[i]);
        return ans;
    }
};