#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    if(n==0 || k<0){
        return false;

    }
    if(k==0){
        return true;
    }

    //including the element
    bool include=subsetSumToK(n-1,k-arr[n-1],arr);

    //exlcuding the element
    bool exclude=subsetSumToK(n-1,k,arr);

    return include || exclude;
}