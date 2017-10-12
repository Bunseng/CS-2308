// File Name: p2_b_s329.cpp
//
// Author: Bunrith Seng
// Date: 07/23/2017
// Assignment Number: 2
// CS 2308 Summer 2017
// Instructor: Dan Tamir
//

// This program uses the bubble sort algorithm to sort an
// array in ascending order.
#include <iostream>
//#include <ctype.h>
using namespace std;

// Function prototypes
void sortArray(int [], int);
void showArray(const int [], int);
int *iprepend(int *destination, int *source);

int main()
{
   // Assign types
   int SIZE, count;
   int *values, *destination;

   cout <<"Enter number of size elements: ";
   cin >> SIZE;
   cout << "\n";

   //check if cin is fail
    while (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid integer. Try again!\n";
            cout << endl;
            cout <<"Enter number of size elements: ";
            cin >> SIZE;

        }

   values = new int[SIZE];
   destination = new int[SIZE];

   values[0] = SIZE;

    for ( count = 1; count < SIZE + 1; count++)
        {
            cout << "Enter some numbers: ";
            cin >> values[count];

            //validate integer
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout <<"Invalid integer. Try again!\n";
                cout <<"Enter some numbers: ";
                cin >> values[count];
            }
        }
   //display
   iprepend(destination, values);
   cout << "The values in destination array: \n";
   for (count = 1;  count < SIZE+1; count++)
       cout << destination[count] << " ";
   // Display the values.
   cout << "\nThe unsorted values are:\n";
   showArray(values, SIZE);

   // Sort the values.
   sortArray(values, SIZE);
   // Display them again.
   cout << "The sort values are:\n";
   showArray(values, SIZE);

   return 0;
}

//***********************************************************
// Definition of function sortArray                         *
// This function performs an ascending order bubble sort on *
// array. size is the number of elements in the array.     *
//***********************************************************

void sortArray(int array[], int size)
{
   bool swap;
   int temp;

   do
   {
      swap = false;
      for (int count = 0; count < (size - 1); count++)
      {
         if (array[count] > array[count + 1])
         {
            temp = array[count];
            array[count] = array[count + 1];
            array[count + 1] = temp;
            swap = true;
         }
      }
   } while (swap);
}
//*************************************************************
// Definition of function showArray.                          *
// This function displays the contents of array. size is the *
// number of elements.                                        *
//*************************************************************

void showArray(const int array[], int size)
{
   for (int count = 0; count < size; count++)
      cout << array[count] << " ";
   cout << endl;
}

int *iprepend(int *destination, int *source)
{
    destination[0] = source[0];
    for (int i = 1; i < source[0]+1; i++)
        destination[i] = source[i];
        return destination;
}
