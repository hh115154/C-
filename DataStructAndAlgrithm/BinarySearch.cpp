#include"BinarySearch.h"

    
int BinarySearch::searchInt(vector<int> arr,int val){    
    return bsearch(arr,val,0,arr.size()-1);
}
int BinarySearch::bsearch(vector<int>arr,int val,int left,int right){
    int mid = left+(right-left)/2;
    if(val>arr[mid])
        return bsearch(arr,val,mid+1,right);
    else if(val<arr[mid])
        return bsearch(arr,val,left,mid-1);
    else
        return mid;
    
}

int BinarySearch::peakIndexInMountainArray(vector<int>& arr){
    return bsearchMountain(arr,0,arr.size()-1);
} 

int BinarySearch::bsearchMountain(vector<int>&arr,int le,int ri){
    int mid = le+ (ri-le)/2;
    if(arr[mid-1]<arr[mid]&&arr[mid]>arr[mid+1])
        return mid;
    else
    {
        int tmpl = mid;
        while(arr[tmpl-1]==arr[tmpl])
            tmpl--;

        while(arr[mid] == arr[mid+1])
            mid++;

        if(arr[tmpl-1]<arr[tmpl])
            return bsearchMountain(arr,tmpl,ri);
        else
            return bsearchMountain(arr,le,tmpl-1);
        
    }
}