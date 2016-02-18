#include <stdio.h>  // printf()
#include <stdlib.h> // calloc(), atoi()
#include <math.h>   // pow()

#include "die.h"   // die()
#include "queue.h" // Queue, q_node

#define BASE 10
#define NDIGITS 2 * BASE - 1 // How many buckets will we use?

void radixsort(int* nums, int count); // Radixsort an array of ints (LSD variant)

int radix_len(int num); // Returns decimal digit count of a number

/* This function returns a digit on pos position.
 * radix_digit(*something*, 1) returns the LSD.
 *
 * NOTE: Bear in mind that it's capable
 * of returning values below 0 for
 * negative num arguments.
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
    int digit, max;
    Queue buckets[NDIGITS]; // One index per digit, including negatives

    // Don't bother working on one-element and empty array
    if (count < 2)
        return;

    for (int i = 0; i < NDIGITS; i++) { // Nullify each queue
        buckets[i].head = NULL;
        buckets[i].tail = NULL;
    }

    // Find the biggest number width
    max = radix_len(nums[0]);
    for (int i = 1; i < count; i++)
        if (radix_len(nums[i]) > max)
            max = radix_len(nums[i]);

    // Go through each column
    for (int i = 1; i <= max; i++) {
        // of each element
        for (int j = 0; j < count; j++) {

            // to get the i-th digit from j-th nums[] element,
            digit = radix_digit(nums[j], i) + BASE - 1; // compensate for negative digits

            // and enqueue it to the corresponding digit-th bucket.
            q_enq(buckets + digit, nums[j]);
        }

        // Take each element of nums[],
        for (int j = 0; j < count; j++)
            for (int k = 0; k < NDIGITS; k++)   // and fill it with whatever
                while (buckets[k].head != NULL) // we find in each non-empty bucket.
                    nums[j++] = q_deq(buckets + k);
    }
}

int radix_len(int num)
{
    int i;

    // Try %'ing num by powers of BASE until it stops changing num's value
    for (i = 1; num % (int)pow(BASE, i) != num; i++)
        ;

    return i;
}

int radix_digit(int num, int pos)
{
    if (pos < 1)
        die("Requested a digit on an invalid position");

    num %= (int)pow(BASE, pos);     // Chop the left part off
    num /= (int)pow(BASE, pos - 1); // Chop the right part off

    return num;
}
