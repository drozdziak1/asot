#include <stdio.h>  // printf()
#include <stdlib.h> // calloc(), atoi()
#include <math.h>   // pow()

#include "die.h"   // die()
#include "queue.h" // Queue, q_node

void radixsort(int* nums, int count); // Radixsort an array of ints (LSD variant)

int radix_len(int num); // Returns decimal digit count of a number

/* This function returns a digit on pos position.
 * radix_digit(*something*, 1) returns the LSD.
 *
 * NOTE: Bear in mind that it's capable of
 * returning values below 0 for
 * negative numbers.
 */
int radix_digit(int num, int pos);

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

    radixsort(nums, argc - 1);

    puts("Your arguments (sorted):");
    for (int i = 0; i < argc - 1; i++)
        printf("%d ", nums[i]);

    free(nums);
    return 0;
}

void radixsort(int* nums, int count)
{
    int digit, max = radix_len(nums[0]);
    Queue buckets[19]; // One index per digit, including negatives

    for (int i = 0; i < 19; i++) { // Nullify the shit outta each queue's empty head
        buckets[i].head = NULL;
    }

    // Find the biggest number width
    for (int i = 1; i < count; i++)
        if (radix_len(nums[i]) > max)
            max = radix_len(nums[i]);

    // Go through each column
    for (int i = 1; i <= max; i++) {
        // of each element
        for (int j = 0; j < count; j++) {

            // to get the i-th digit from j-th nums[] element,
            digit = radix_digit(nums[j], i) + 9; // compensate for negative digits with 9,

            // and enqueue j-th element to the corresponding digit-th bucket.
            q_enq(buckets + digit, nums[j]);
        }

        // Take each element of nums[],
        for (int j = 0; j < count; j++)
            for (int k = 0; k < 19; k++)        // and fill it with whatever
                while (buckets[k].head != NULL) // we find in each non-empty bucket.
                    nums[j++] = q_deq(buckets + k);
    }
}

int radix_len(int num)
{
    int i;

    // Try %'ing num by powers of 10 until it stops changing num's value
    for (i = 1; num % (int)pow(10, i) != num; i++)
        ;

    return i;
}

int radix_digit(int num, int pos)
{
    if (pos < 1)
        die("Requested a digit on an invalid position");

    num %= (int)pow(10, pos);     // Chop the left part off
    num /= (int)pow(10, pos - 1); // Chop the right part off

    return num;
}
