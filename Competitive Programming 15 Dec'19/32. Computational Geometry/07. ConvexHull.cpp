#include<bits/stdc++.h>
using namespace std;

struct point{int x, y;};
vector<point> convexHull(point p[], int n){
    vector<point> hull;
    int left = 0;
    for(int i=0; i<n; i++){
        if(p[left].x>p[i].x){
            left = i;
        }
    }
    int a = left;
    do{
        hull.push_back(p[a]);
        int b = (a+1)%n;
        for(int i=0; i<n; i++){
            int x1 = p[b].x-p[a].x;
            int y1 = p[b].y-p[a].y;
            int x2 = p[i].x-p[a].x;
            int y2 = p[i].y-p[a].y;
            if(x1*y2-x2*y1<0){
                b = i;
            }
        }
        a = b;
    }while(a!=left);
    return hull;
}

int main() {
    int n = 7;
    //cin>> n;
    point p[n] = {{0,0}, {4,0}, {4,4}, {0,4}, {1,1}, {2,2}, {3,3}};
    //for(int i=0; i<n; i++) cin>> p[i].x;
    //for(int i=0; i<n; i++) cin>> p[i].y;
    
    vector<point> hull = convexHull(p, n);
    for(auto it = hull.begin(); it!=hull.end(); it++){
        cout<< it->x<< ' '<< it->y<< endl;
    }
}

/*
Convex Hull
Send Feedback
Given a set of points in the plane. the convex hull of the set is the smallest convex polygon that contains all the points of it.
Find out the convex hull for the given set of points.
Input Format
Integer N(Number Of points)
Array of X coordinates
Array of Y coordinates
Output Format
X coordinate and Y coordinate of all the points seperated by space. Order doesn't matter.
Sample Testcase
Input
7
2 1 6 5 3 7 9
2 5 1 5 7 6 4
Output
1 5
2 2
6 1
9 4
7 6
3 7
*/