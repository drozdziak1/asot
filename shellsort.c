#include <stdio.h>  // printf()
#include <stdlib.h> // calloc(), atoi()

void shellsort(int* nums, int count); // shellsort an array of ints

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

    shellsort(nums, argc - 1);

    puts("Your arguments (sorted):");
    for (int i = 0; i < argc - 1; i++)
        printf("%d ", nums[i]);

    free(nums);
    return 0;
}

void shellsort(int* nums, int count)
{
    /* val_to_insert - unsorted element
     * into the insertion-sorted part.
     *
     * inner - current index of the current
     * nums[] subarray.
     *
     * interval - how thick we are slicing
     * the nums[] array.
     */
    int val_to_insert, inner, interval = 1;

    // Find a reasonable interval
    while (interval < count / 3)
        interval = interval * 3 + 1;

    while (interval > 0) {

        for (int i = interval; i < count; i++) {

            // Select an element to insert
            val_to_insert = nums[i];
            inner = i;

            // Shift the element towards right
            while (
                inner >= interval
                && nums[inner - interval] >= val_to_insert) {

                nums[inner] = nums[inner - interval];
                inner -= interval;
            }

            // Fill a hole with the element currently being sorted
            nums[inner] = val_to_insert;
        }

        // Recalculate the interval
        interval = (interval - 1) / 3;
    }
}
