#include <stdio.h>  // printf()
#include <stdlib.h> // calloc(), atoi()

void mergesort(int* nums, int p, int r);
void merge(int* nums, int p, int q, int r);

int main(int argc, char const* argv[])
{
    int* nums = calloc(argc - 1, sizeof(int));

    for (int i = 0; i < argc - 1; i++)
        nums[i] = atoi(argv[i + 1]);

    puts("Your arguments:");

    for (int i = 0; i < argc - 1; i++)
        printf("%d ", nums[i]);

    puts("\n");

    mergesort(nums, 0, argc - 2);

    puts("Your arguments (sorted):");

    for (int i = 0; i < argc - 1; i++)
        printf("%d ", nums[i]);

    free(nums);
    return 0;
}

void mergesort(int* nums, int p, int r)
{
    int q;
    if (p < r) {

        q = (p + r) / 2;

        mergesort(nums, p, q);
        mergesort(nums, q + 1, r);

        merge(nums, p, q, r);
    }
}

// p - start index, q - middle index,  r - end index
void merge(int* nums, int p, int q, int r)
{
    int* temp = calloc(r - p + 1, sizeof(int));

    /* Set i, j, k to starting indices of the left half,
     * right half and temp[], respectively.
     */
    int i = p, j = q + 1, k = 0;

    while (i <= q && j <= r) {

        if (nums[j] < nums[i]) {

            temp[k] = nums[j];
            ++j;
        }
        else {

            temp[k] = nums[i];
            ++i;
        }
        ++k;
    }

    // Append the remainder of the bigger half to temp[]
    if (i <= q) {

        while (i <= q)
            temp[k++] = nums[i++];
    }
    else {

        while (j <= r)
            temp[k++] = nums[j++];
    }

    for (int i = 0; i < r - p + 1; i++)
        nums[p + i] = temp[i];

    free(temp);
}
