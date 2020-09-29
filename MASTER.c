/************************************
COURSE: Algorithms and Complexity
Homework 3 - Sorting Algorithms
*************************************/

// Libraries
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Total size of the array
// You should change N for the experiments according to the description (see PDF)
#define N 100000

// Function declaration
// Array functions
void createArray (int array[N]);
void printArray (int array[N]);

// Sorting functions
void bubbleSort (int array[N]);
// Define the following functions
//void selectionSort (...)
//void insertionSort (...)
//void mergeSort (...)
//void shellSort (...)
//void quickSort (...)

// Main function where the sorting algorithm is called
int main ()
{
   // Array is static so that the compiler can store it beforehand in memory
   static int arr[N];
   // Variables to measure time
   clock_t t_ini, t_end;
   double t_elapsed;

   // Create the array with random elements
   createArray (arr);
   // WARNING: Only print the array for testing purposes and if N is small
   //printf ("\n\nUNSORTED ARRAY:\n");
   //printArray (arr);

   // Check the initial time
   t_ini = clock();
   printf ("\n\nInitial time: %f", ((double)t_ini));

   // Start the sorting algorithm
   bubbleSort (arr);
   // selectionSort (...)
   // insertionSort (...)
   // mergeSort (...)
   // shellSort (...)
   // quickSort (...)

   // Check the final time and calculate the elapsed time
   t_end = clock() - t_ini;
   printf ("\nFinal time: %f", ((double)t_end));
   t_elapsed = ((double)t_end)/CLOCKS_PER_SEC;
   printf ("\nTotal time: %f segs", t_elapsed);

   // WARNING: Only print the array for testing purposes and if N is small
   //printf ("\n\nSORTED ARRAY:\n");
   //printArray (arr);

   return 0;
}

// Bubble sort algorithm
void bubbleSort (int array[N])
{
   int temp;
   int i,j;
   int swapped = 0;

   for (i = 0; i < N-1; i++)
   {
      swapped = 0;

      for (j = 0; j < N-1-i; j++)
      {
         if (array[j] > array[j+1])
         {
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            swapped = 1;
         }
      }

      if (!swapped)
        return;
   }
}

// ADD HERE THE OTHER SORTING FUNCTIONS

// Prints an array of size N
void printArray (int array[N])
{
   int i;

   printf ("\n\n");
   for (i = 0; i < N; i++)
   {
      printf ("%d, ", array[i]);
   }
}

// Fills an existing array with random values
void createArray (int array[N])
{
   int i;
   time_t t;

   srand((unsigned) time(&t));

   for (i = 0; i < N; i++)
   {
      // NOTE: If N is large try to have large numbers in the array
      // otherwise the array would contain many repeated elements
      array[i] = rand() % 1000000;
   }
}
