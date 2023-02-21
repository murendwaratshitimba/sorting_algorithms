#include "sort.h"

/**
* recursive_radix_sort - radix sort algorithm - LSD
* the number of do arecursion is linear depend with
* the #digits of max number
* @array: unsorted array of integer
* @result: possible result
* @size: size of the array
* @lsd: least significant digit (1 last: 1, 2nd last: 1*10, 3: 1*10*10)
*
* Return: void
*/
void recursive_radix_sort(int *array, int *result, size_t size, int lsd)
{
int i, idx_start, idx_index;
int index[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


for (i = 0; i < (int)size; i++)
index[(array[i] / lsd) % 10] += 1;


if (index[0] == (int)size)
return;


for (i = 1; i < 10; i++)
index[i] += index[i - 1];

for (i = 9; i > 0; i--)
index[i] = index[i - 1];
index[0] = 0;

for (i = 0; i < (int)size; i++)
{

idx_index = (array[i] / lsd) % 10;
idx_start = index[idx_index];

result[idx_start] = array[i];

index[idx_index]++;
}

for (i = 0; i < (int)size; i++)
array[i] = result[i];
print_array(array, size);
recursive_radix_sort(array, result, size, lsd * 10);
}

/**
* radix_sort - radix sort algorithm - LSD
* properties:
* [LSD] least significant digit
* stable -> not relevant to sort equals values
* lenght of index table = base of number(binary, 10, hexa)
* how many times sort -> max number of digit of nbr
* @array: unsorted array of integer
* @size: size of the array
*
* Return: void
*/
void radix_sort(int *array, size_t size)
{
int *result;

if (!array || size <= 1)
return;
result = malloc(sizeof(int) * size);
if (!result)
return;

recursive_radix_sort(array, result, size, 1);
free(result);
}
