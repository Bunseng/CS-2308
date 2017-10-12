/*
****************************************************
Name: Bunrith Seng
Date: 2/4/17
Problem Number:project 1
Hours spent solving the problem: 7.5 hours
Instructor: Komogortsev, TSU
*****************************************************
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdlib>

using namespace std;

//declarations
double convertFile(double);
void conversion(string&, string&, string&, string&, string&, string&);


//Converts the Fahrenheit to Celsius
double convertFile(double temp)

{
    double result;
    result = (temp - 32)* 5 / 9;
    return result;
}

//Converts to human readable time string
void conversion(string& date, string& y, string& m, string& d, string& hr, string& minute)
{
     y = date.substr(0, 4);
     m = date.substr(4, 2);
     d = date.substr(6, 2);
     hr = date.substr(8, 2);
     minute = date.substr(10, 2);
}

int main()
{
    int     enter;
    string  date,
            month,
            day,
            year,
            hour,
            minute,
            xtemp;
    double  tempfile,
            total = 0;


    ifstream input;
     //Open the input file
    input.open("biodata.dat");

    if (!input)//check if the file open correctly
     {
          cout << "Make sure the file is in the same dir\n";
          return -1;
     }

    ofstream output;
     //Open the output file
    output.open("filtered_biodata.dat");

    if (!output)//check if the file open correctly
     {
          cout << "Make sure the file is in the same dir\n";
          return -1;
     }
     //out a text to a file
     output << "Data output\n\n";
     output << endl;

     //read input file
     input >> enter;

     //Process each value enter
     for (int i = 0; i < enter; i++)

     {
        //read the time and date string and temp in each value enter
        input >>date>> xtemp;

        //Call the function conversion() to convert the time stamp
        //to a human readable string
        conversion(date, year, month, day, hour, minute);
        tempfile = atof(xtemp.substr(1, xtemp.size()).c_str());

        if (xtemp[0] == 'F')

        //Converts F to C by calling function convertFile()
        tempfile = convertFile(tempfile);

        //Keep track the sum of all temp
        total += tempfile;

        //Print the human readable output to filtererd_biodata.dat file
        output << setprecision(2) << fixed << tempfile << " C --- recorded on "
                << month << "/"
                << day << "/" << year << " at " << hour << minute<< endl << endl;

     }
     output << endl;
     //average temp output file
     output << "\nAverage Temp --- " << setprecision(2) << fixed << (total / enter) << " C";

     //Close the input and output files
     output.close();
     input.close();
     return 0;
}
