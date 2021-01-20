/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.
*/


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i,s=-1,e=-1;
        
        for(i=0; i<intervals.size(); i++){
            if(intervals[i][1]<newInterval[0]){
                ans.push_back(intervals[i]);
            }else if(intervals[i][0]<=newInterval[0]){
                s=intervals[i][0];
                break;
            }else{
                s=newInterval[0];
                break;
            }
        }
        for(i; i<intervals.size(); i++){
            if(intervals[i][1]>=newInterval[1]){
                if(intervals[i][0]<=newInterval[1]){
                    e=intervals[i][1];
                    i++;
                }else{
                    e=newInterval[1];
                }
                vector<int> v{s, e};
                ans.push_back(v);
                break;
            }
        }
        for(i; i<intervals.size(); i++)
            ans.push_back(intervals[i]);
        
        if(s==-1){
            s=newInterval[0];
        }
        if(e==-1){
            e=newInterval[1];
            vector<int> v{s, e};
            ans.push_back(v);
        }
        return ans;
    }
};