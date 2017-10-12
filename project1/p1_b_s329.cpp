// File Name: p1_b_s329.cpp
//
// Author: Bunrith Seng
// Date: 07/17/2017
// Assignment Number: 1
// CS 2308 Summer 2017
// Instructor: Dan Tamir
//

// This program uses the selection sort algorithm to sort an
// array in ascending order and descending order.

/*2. Given program comparison and assignment of array operations
    are performed so the running program is with the array of N size is weight
    3. One for comparison and Two for assignment.
    Time complexity of the given sort is O(n^2).
    Outer loop iterate to SIZE times and inner loop iterate SIZE-1 times.
   4.Similar to the ascending sorted order, the time complexity is O(n^2)
*/

#include <iostream>
#include <conio.h>
using namespace std;

// Function prototypes
void selectionSort(int [], int);
void descendingSort(int[], int);
void showArray(int [], int);

int main()
{
   // Define an array with unsorted values
   const int SIZE = 6;
   int values[SIZE] = {5, 7, 2, 8, 9, 1};

   // Display the values.
   cout << "The unsorted values are\n";
   showArray(values, SIZE);

   // Sort the values.
   selectionSort(values, SIZE);

   // Display the values again.
   cout << "The sorted values in ascedning order are\n";
   showArray(values, SIZE);

    //sort the values.
    descendingSort(values, SIZE);

   //Display the value in descending order
   cout << "The sorted values in descending order.\n";
   showArray(values, SIZE);
   getch();
   return 0;
}

//**************************************************************
// Definition of function selectionSort.                       *
// This function performs an ascending order selection sort on *
// array. size is the number of elements in the array.         *
//**************************************************************

void selectionSort(int array[], int size)
{
   int startScan, minIndex, minValue;

   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      minIndex = startScan;
      minValue = array[startScan];
      for(int index = startScan + 1; index < size; index++)
      {
         if (array[index] < minValue)
         {
            minValue = array[index];
            minIndex = index;
         }
      }
      array[minIndex] = array[startScan];
      array[startScan] = minValue;
   }
}
//**************************************************************
//Definition of function selectionSort
//This function perform a descending order in selectionSort                                         *
//**************************************************************
void descendingSort(int array[], int size)
{
    int minValue, maxValue, tempValue;

    for (int i = 0; i < (size/2); i++)
        {
            minValue = array[i];
            maxValue= array[size-i-1];

            tempValue = array[i];
            array[i]= array[size-i-1];
            array[size-i-1]= tempValue;

            tempValue = minValue;
            minValue = maxValue;
            maxValue = tempValue;
        }
}
//**************************************************************
// Definition of function showArray.                           *
// This function displays the contents of array. size is the   *
// number of elements.                                         *
//**************************************************************

void showArray(int array[], int size)
{
   for (int count = 0; count < size; count++)
      cout << array[count] << " ";
   cout << endl;
}
