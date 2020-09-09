#pragma once
#include <vector>

using namespace std;

class BinarySearch{
    public:
    int searchInt(vector<int> arr,int val);
    //leetcode410，hard
    int splitArray(vector<int>,int m);
    //leetcode1231,hard
    int maximizeSweetness(vector<int>,int m);
    //leetcode852,easy
    int peakIndexInMountainArray(vector<int>& arr) ;
    //leetcode1011,medium
    int shipWithinDays(vector<int>& weights, int D);
    //leetcode1292,medium
    int maxSideLength(vector<vector<int>>& mat, int threshold);

    private:
    int bsearch(vector<int>arr,int val,int left,int right);
    int bsearchMountain(vector<int>&arr,int le,int ri);

};