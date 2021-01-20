/*
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)
*/


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        struct {
            bool operator()(vector<int> a, vector<int> b){
                return (a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1]);
            }
        } comp;
        sort(points.begin(), points.end(), comp);
        vector<vector<int>> ans;
        for(int i=0; i<K; i++){
            vector<int> tmp = {points[i][0], points[i][1]};
            ans.push_back(tmp);
        }
        return ans;
    }
};