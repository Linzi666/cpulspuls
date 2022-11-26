#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
    int nums1[] = { 1,2,3,0,0,0 };
    int nums2[] = { 2,5,6 };
    int m = 3;
    int n = 3;
    int end = m + n - 1;//合并后的长度
    n = n - 1;
    m = m - 1;
    while (m >= 0 && n >= 0)
    {
        if (nums2[n] > nums1[m])
        {
            nums1[end--] = nums2[n--];
        }
        else
        {
            nums1[end--] = nums1[m--];

        }
    }
    while (n >= 0)
    {
        nums1[end--] = nums2[n--];

    }


}