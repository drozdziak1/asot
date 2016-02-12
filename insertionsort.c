#include <stdio.h>  // printf()
#include <stdlib.h> // calloc(), atoi()
#include <time.h>   // time()

void insertionsort(int* nums, int count); // insertionsort an array of ints
void swap(int* a, int* b);

int main(int argc, char const* argv[])
{
    srand(time(NULL));

    int* nums = calloc(argc - 1, sizeof(int));

    for (int i = 0; i < argc - 1; i++) {
        nums[i] = atoi(argv[i + 1]);
    }

    puts("Your arguments:");
    for (int i = 0; i < argc - 1; i++)
        printf("%d ", nums[i]);

    puts("\n");

    insertionsort(nums, argc - 1);

    puts("Your arguments (sorted):");
    for (int i = 0; i < argc - 1; i++)
        printf("%d ", nums[i]);

    free(nums);
    return 0;
}

void insertionsort(int* nums, int count)
{
    // i - leftmost element of the unsorted part
    for (int i = 1; i < count; i++)
        // j - element currenly being sorted
        for (int j = i; j > 0 && nums[j - 1] > nums[j]; j--)
            swap(nums + j - 1, nums + j);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
