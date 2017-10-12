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
//Appen two arrays together.
#include <iostream>
using namespace std;

// Function prototypes
void sortArray(int [], int);
void showArray(const int [], int);
int *iprepend(int *destination, int *source);

int main()
{
   // Assign types
   int SIZE_1, SIZE_2, count, count_1 = 0, count_2 = 0;
   int *arr1, *arr2, *arr3;

   cout << "Size number for static array: ";
   cin >> SIZE_1;

   int value[SIZE_1];

   //check if cin is fail
    while (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid integer. Try again!\n";
            cout << endl;
            cout <<"Size number for static array: ";
            cin >> SIZE_1;

        }

    for (int count = 0; count < SIZE_1; count++)
        {
            cout << "Enter some numbers: ";
            cin >> value[count];
            count_1++;

            //validate integer
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout <<"Invalid integer. Try again!\n";
                cout <<"Enter some numbers: ";
                cin >> value[count];
                count_1++;
            }
        }

    //Static array
   cout << "Static array values: \n";
   cout << count_1 << ": ";
   showArray(value, SIZE_1);

   //sort the values
   sortArray(value, SIZE_1);
   //display
   cout << "The sorted values are: \n";
   showArray(value, SIZE_1);


   cout <<"Size number for dynamic array: ";
   cin >> SIZE_2;
   cout << "\n";

   //check if cin is fail
    while (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid integer. Try again!\n";
            cout << endl;
            cout <<"Size number for dynamic array: ";
            cin >> SIZE_2;


        }

   int *values = new int[SIZE_2];
   int *destination = new int[SIZE_2];

   values[0] = SIZE_2;

    for ( count = 1; count < SIZE_2+1  ; count++)
        {
            cout << "Enter some numbers: ";
            cin >> values[count];
            count_2++;

            //validate integer
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout <<"Invalid integer. Try again!\n";
                cout <<"Enter some numbers: ";
                cin >> values[count];
                count_2++;
            }
        }
    cout << endl;

   //display dynamic array
   iprepend(destination, values);
   cout << "Dynamic array values: \n";
   cout << count_2 << ": ";
   for (count = 1;  count < SIZE_2+1; count++)
       cout << destination[count] << " ";
   // Display the values.
   cout << "\nThe unsorted values are:\n";
   for (count = 1; count < SIZE_2+1; count++)
        cout << values[count] << " ";
        cout << endl;

   // Sort the values.
   sortArray(values, SIZE_2+1);
   // Display them again.
   cout << "The sort values are:\n";
   showArray(values, SIZE_2+1);

   //Append both array together.
   int size1(SIZE_1), size2(SIZE_2);
   arr1 = value;
   arr2 = values;

   arr3 = new int;

   for(count = 0; count <size1+size2; count++)
   {
       if (count <size1)
            arr3[count] = arr1[count];
       else
            arr3[count] = arr2[count-size1];

   }
   cout << endl;
   //concatenate the arrays
   cout << "The two arrays are concatenated..\n";
   cout << count_1 + count_2 << ": ";
   for (count = 0; count < size1+size2; count++)
        cout <<arr3[count] << ", ";


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

