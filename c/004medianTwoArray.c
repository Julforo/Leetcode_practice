#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//4.Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *res = (int *)calloc(nums1Size+nums2Size,sizeof(int));
    int m=0;
    int i=0,j=0;
    int res_size = nums1Size + nums2Size;
    double medium = 0;

    if (nums1Size==0&&nums2Size==0)
        return 0.0;

    for (; i < nums1Size && j<nums2Size;){
        if (nums1[i] <= nums2[j]){
            res[m] = nums1[i];
            i++;
            m++;
        }else{
            res[m] = nums2[j];
            j++;
            m++;
        }    
    }
    for (; i < nums1Size; i++){
        res[m] = nums1[i];
        m++;
    }
    for (; j < nums2Size; j++){
        res[m] = nums2[j];
        m++;
    }
    if (res_size%2==0){
        medium = (res[(res_size)/2]+res[(res_size)/2-1])/2.0;
    }else{
        medium = res[(res_size)/2];
    }
    return medium;
}

int main(){
    int a = 2,b=3;
    int a1[2] = {3,34};
    int b1[3] = {1,4,99};
    printf("%f\n",findMedianSortedArrays(a1,a,b1,b));

    return 0;
}
