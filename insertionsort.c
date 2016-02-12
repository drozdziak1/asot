#include <stdio.h>  // printf()
#include <stdlib.h> // calloc(), atoi()

void insertionsort(int* nums, int count); // insertionsort an array of ints

int main(int argc, char const* argv[])
{
    int* nums = calloc(argc - 1, sizeof(int));
    for (int i = 0; i < argc - 1; i++) {
        nums[i] = atoi(argv[i + 1]);
    }

    puts("Your arguments:");
    for (int i = 0; i < argc - 1; i++)
        printf("%d ", nums[i]);

    puts("\n");

    insertionsort(nums, argc-1);

    puts("Your arguments (sorted):");
    for (int i = 0; i < argc - 1; i++)
        printf("%d ", nums[i]);

    free(nums);
    return 0;
}

void insertionsort(int* nums, int count)
{
    int swaps, temp;

    do {
        swaps = 0;

        for (int i = 0; i < count-1; i++) {

            if (nums[i] > nums[i+1])
            {
                temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;

                ++swaps;
            }
        }
    } while (swaps);
}
