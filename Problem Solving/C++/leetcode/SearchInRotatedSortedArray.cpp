class Solution {
public:
#include <bits/stdc++.h>
    int binarySearch(vector<int>nums,int l,int r,int k)
    {
        if(l>r)return -1;
        int mid=l+(r-l)/2;
        if(nums[mid]==k)return mid;
        else if(nums[mid]>k)
            r=mid-1;
        else l=mid+1;
        return binarySearch(nums,l,r,k);
    }
    int get_pivot(vector<int>nums,int l,int r)
    {
        if(l>r)return -1;
        int mid=l+(r-l)/2;
        if(mid<r&&nums[mid]>nums[mid+1])
            return mid;
        if(mid>l&&nums[mid-1]>nums[mid])
            return mid-1;
        if(nums[mid]>nums[l])
        {
            l=mid+1;
        }
        else r=mid-1;
        return get_pivot(nums,l,r);
    }
    int search(vector<int>& nums, int target) {
        int pivot=get_pivot(nums,0,nums.size()-1);
        if(pivot==-1)
            return binarySearch(nums,0,nums.size()-1,target);
        else {
            return max(binarySearch(nums,0,pivot,target),binarySearch(nums,pivot+1,nums.size()-1,target));
        }
    }
};