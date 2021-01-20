/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(2*nums[i] != target && mp[target-nums[i]] || 2*nums[i] == target && mp[nums[i]] >= 2){
                ans.push_back(i);
                ans.push_back(find(nums.begin()+i+1, nums.end(), target-nums[i]) - nums.begin());
                break;
            }
        }
        return ans;
    }
};