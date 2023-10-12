// Leetcode Hard 

// Problem Description:

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

// Example 1:


// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9
 

// Constraints:

// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105


// Code:


class Solution {
public:
    void damn(vector<int> &h, vector<int> &right, vector<int> &left){
        int n = h.size();
        int mx = -1;
        for(int i=0; i<n; i++){
            left[i] = mx;
            mx = max(mx, h[i]);
        }
        mx = -1;
        for(int i=n-1; i>=0; i--){
            right[i] = mx;
            mx = max(mx, h[i]);
        }
    }

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> right(n), left(n);
        damn(height, right, left);
        int ans = 0;

        for(int i=0; i<n; i++){
            if(min(right[i], left[i])>height[i])
            ans += min(right[i], left[i]) - height[i];
        }
        return ans;
    }
};