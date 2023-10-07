#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&nums,int index,vector<int>output,vector<vector<int>>&ans){
if(index>=nums.size()){
    ans.push_back(output);
    return;
}
 solve(nums,index+1,output,ans);
 int element=nums[index];
 output.push_back(element);
 solve(nums,index+1,output,ans);
}
int main(){
vector<int>output;
vector<int>nums;
nums.push_back(1);
nums.push_back(3);
nums.push_back(8);
nums.push_back(10);
vector<vector<int>>ans;
solve(nums,0,output,ans);
for(auto it:ans){
    for(auto ele:it){
        cout<<ele<<" ";
    }
    cout<<endl;
}
return 0;
}