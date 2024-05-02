#include <stdio.h>

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
int numsSize = sizeof(nums) / sizeof(nums[0]);
    int i , j, tmp;

    // reverse K element from last
    i = numsSize -k;
    j =  numsSize -1;
    while(i < j)
    {
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--; 
    }

    // reverse first K element
    for(i = 0, j = numsSize-1-k; i < j; i++, j--)
    {
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    // reverse Full Array 
    for(i = 0, j = numsSize-1;i < j; i++, j--)
    {
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }


}

