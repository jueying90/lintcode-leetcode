#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
//时间复杂度O(n),空间复杂度O(n)
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL)
        return NULL;
    int *res = (int*)malloc(numsSize * sizeof(int));
    int *left = (int*)malloc(numsSize * sizeof(int));
    int *right = (int*)malloc(numsSize * sizeof(int));
    left[0] = 1;
	int i;
    for (i = 1;i < numsSize; i++)
        left[i] = left[i-1] * nums[i-1];
    right[numsSize-1] = 1;
    for (i = numsSize-2; i >= 0; i--)
    {
        right[i] = right[i+1]*nums[i+1];
    }
    for (i = 0;i < numsSize; i++)
        res[i] = left[i] * right[i];
    *returnSize = numsSize;
    free(left);
    free(right);
    return res;
}
//时间复杂度O(n),空间复杂度O(1)
int* productExSelf(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL)
        return NULL;
    int *res = (int*)malloc(numsSize * sizeof(int));
    res[numsSize - 1] = 1;
	int i;
    for (i = numsSize - 1;i > 0; i--)
        res[i-1] = res[i] * nums[i];
    int left = 1;
    for (i = 0; i < numsSize; i++)
    {
        res[i] *= left;
        left *= nums[i];
    }
    *returnSize = numsSize;
    return res;
}

int main()
{
	int nums[10] = {1,2,3};
	int res_size = 0;
	int *res = productExceptSelf(nums, 3, &res_size);
	int i;
	for (i = 0; i < res_size; i++)
		printf("%d ",res[i]);
	printf("\n");
	return 0;
}