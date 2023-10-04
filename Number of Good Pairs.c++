class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res=0;
        unordered_map<int,int>mp;

        for (auto x :nums){
            res+=mp[x];
            mp[x]++;  

        }
        return res;
    }
};