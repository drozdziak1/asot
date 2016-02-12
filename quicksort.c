#include <stdio.h>  // printf()
#include <stdlib.h> // calloc(), atoi()
#include <time.h>   // time()

void quicksort(int* nums, int p, int r); // Quicksort an array of ints
int split(int* nums, int p, int r);      // For quicksort
void swap(int* a, int* b);               // Swap two int pointers

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

    quicksort(nums, 0, argc - 2);

    puts("Your arguments (sorted):");
    for (int i = 0; i < argc - 1; i++)
        printf("%d ", nums[i]);

    free(nums);

    return 0;
}

void quicksort(int* nums, int p, int r)
{
    if (p < r) {

        int q = split(nums, p, r);
        quicksort(nums, p, q - 1);
        quicksort(nums, q + 1, r);
    }
}

int split(int* nums, int p, int r)
{
    int cur_pos = p;

    // Pick a random element for a pivot
    int q = rand() % (r - p) + p;
    int q_val = nums[q];

    // Swap the pivot with our rightmost element
    swap(nums + q, nums + r);

    /* Swap every element smaller than the pivot with cur_pos;
     * move the "wall" by incrementing cur_pos.
     */
    for (int i = p; i < r; i++)
        if (nums[i] < q_val)
            swap(nums + i, nums + cur_pos++);

    // At last, swap the pivot with our final cur_pos.
    swap(nums + cur_pos, nums + r);

    return cur_pos;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
