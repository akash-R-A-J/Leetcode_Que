#include <stdio.h>

// display function
void display(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

// remove duplicates and return num of unique elements
int removeDuplicates(int *nums, int numsSize)
{
    int count = 1; // tracks unique elements
    for (int i = 1; i < numsSize; i++)
    {
        // get uniquwe elements
        if (nums[i - 1] != nums[i])
        {
            nums[count] = nums[i];
            count++;
        }
    }
    return count;
}

int main()
{
    int nums[] = {1, 1, 1, 2, 2, 3, 4, 4, 5};
    printf("%d ", removeDuplicates(nums, 9));

    return 0;
}