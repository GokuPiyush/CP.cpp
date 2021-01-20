/*
Given a string s, find the length of the longest substring without repeating characters.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(), ans=0;
        for(int i=0; i<n; ){
            unordered_map<char, int> mp;
            int len=0;
            for(int j=i; j<n; j++, i++){
                if(mp[s[j]]){
                    i = mp[s[j]];
                    break;
                }
                mp[s[j]] = j+1;
                len++;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};