/*
****************************************************
Name: Bunrith Seng
Date: 2/09/17
Problem Number:project 2
Instructor: Komogortsev, TSU
*****************************************************
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

//Global constants
const int SIZE = 257;//pos starts at 0, added 1 to size
const int F_NAME = 11;//added 1
const int L_NAME = 13;//added 1
const int ID = 7;//added 1
const int TEST_SCORES = 6;


//prototypes
int studentInfo(char[], char[], char[], char[], int[]);
int lowScore(int[]);
double averageDrop(int[], int);
char Grade(float);
void sumGrade(char);
void writeToFile(fstream &);
void resultToFile(char[] , char[], char[], int[], float, char, fstream&);

int main()
{

int counter = 0;
int counter2 = 0;
int counter3 = 0;
int counter4 = 0;
int counter5 = 0;


//open data file and write to output
fstream inFile;
inFile.open ("student_input.dat", ios::in);
if(!inFile)
{
    cout << "No file found.  Terminating the program.\n";
    return -1;
}

fstream outFile;
outFile.open("student_results.dat", ios::out);
if(!outFile)
{
    cout << "File no found. Program terminating...\n";
    return -1;
}

//declaration
char lsize[SIZE];
char fName[F_NAME];
char lName[L_NAME];
char iD[ID];
int testScores[TEST_SCORES];
int lo_score;
float average;
char grade;
//char sumL;
writeToFile(outFile);

//process
while(inFile.getline(lsize, SIZE))
{
    //parse students info
    int student = studentInfo(lsize, fName, lName, iD, testScores);
    if(!student)//check for error
    {
        cout << "Negative score input. Terminating..\n";
        return -1;
    }
    else//parsing without an error
    {
        lo_score = -1;
        if (student > 5)
                lo_score = lowScore(testScores);
        average = averageDrop(testScores, lo_score);
        grade = Grade(average);
        //sumL = sumGrade(grade);

        /*if (grade == 'A')
        {
            counter++;
        }
        else if (grade == 'B')
        {
            counter2++;
        }
        else if (grade == 'C')
        {
            counter3++;
        }
        else if (grade == 'D')
        {
            counter4++;
        }
        else if (grade == 'F')
        {
            counter5++;
        } */

        //output file
        resultToFile(lName, fName, iD, testScores, average, grade, outFile);
    }
}

/*outFile << endl << endl << "Grade Totals:";

if (counter > 0)
{
    outFile << endl << endl << "A - " << counter;
}
if (counter2 > 0)
{
    outFile << endl << endl << "B - " << counter2;
}
if (counter3 > 0)
{
    outFile << endl << endl << "C - " << counter3;
}
if (counter4 > 0)
{
    outFile << endl << endl << "D - " << counter4;
}
if (counter5 > 0)
{
    outFile << endl << endl << "F - " << counter5;
} */

inFile.close();
outFile.close();
return 0;
}

//functions' process
int studentInfo(char lsize[], char fName[], char lName[], char iD[], int scores[])
{
    char tempScr[10];
    int tmpScr = 0;
    int countScore = 0;
    int i=0,
        j=0;

    if (!lsize[i]) //empty line
        return 0;
    //get first name
    while(lsize[i] != ' ' && lsize[i] != '\t')
        fName[j++] = lsize[i++];
        fName[j] = '\0';
    while (lsize[i] == ' ' || lsize[i] == '\t')
        i++;
    //get last name
    j=0;
    while (lsize[i] != ' ' && lsize[i] != '\t')
        lName[j++] = lsize[i++];
        lName[j] = '\0';
    while (lsize[i++] == ' ' || lsize[i] == '\t');
        i++;
    //get id
    j=0;
    while (lsize[i] != ' ' && lsize[i] != '\t')
        iD[j++] = lsize[i++];
        iD[j] = '\0';
    while (lsize[i] == ' ' || lsize[i] == '\t' )
        i++;

    //get all scores
    j=0;
    while (lsize[i])
    {
       while(lsize[i] && lsize[i] != ' ' && lsize[i] != '\t')
        tempScr[j++] = lsize[i++];
        tempScr[j] = '\0';
        tmpScr = atoi(tempScr);
        if (tmpScr <0)//check for negative number
            return 0;
        scores[countScore] = atoi(tempScr);
        j =0;
        countScore++;
        while(lsize[i] == ' ' || lsize[i] == '\t')
            i++;
    }

    //fill last score with -1
    if (countScore != TEST_SCORES)
        scores[countScore] = -1;

    return countScore;
}
//****************
int lowScore(int scores[])
{
 int lo_score = scores[0];
 for (int i = 1; i<TEST_SCORES; i++)
 {
     if(scores[i] < lo_score)
     {
         lo_score = scores[i];
     }
 }
 return lo_score;
}
//****************
double averageDrop(int scores[], int dropScore)
{
    double sum = 0;
    for( int i = 0; i < TEST_SCORES; i++)
    {
        sum += scores[i];
    }
    return (sum-dropScore)/( TEST_SCORES - 1);
}
//****************
char Grade(float avg)
{
    if (avg >= 89.5)
        return 'A';
    if (avg >= 79.5 && avg < 89.5)
        return 'B';
    if (avg >= 69.5 && avg < 79.5)
        return 'C';
    if (avg >= 59.5 && avg < 69.5)
        return 'D';
    else
        return 'F';
}
void sumGrade(char letter, fstream &outFile)
{
    int counter = 0;

    if (letter == 'A' && counter > 0)
    {
        counter++;
        outFile << endl << "A - " << counter;
    }
    if (letter == 'B' && counter > 0)
    {
        counter++;
        outFile << endl << "B - " << counter;
    }
     if (letter == 'C' && counter > 0)
    {
        counter++;
        outFile << endl << "C - " << counter;
    }
     if (letter == 'D' && counter > 0)
    {
        counter++;
        outFile << endl << "D - " << counter;
    }
     if (letter == 'F' && counter > 0)
    {
        counter++;
        outFile << endl << "F - " << counter;
    }
}
//*****************
void writeToFile(fstream& outFile)
{
    int hsize;//header size
    outFile << setw(L_NAME) << left << "Last Name " << " "
            << setw(F_NAME) << left << "First Name " << " "
            << setw(ID) << right << "ID" << "       "
            << setw(17) << "Test Scores"
            << setw(14) << "Average"
            << setw(9)  << "Grade"
            << endl;

    hsize = L_NAME + 1 + F_NAME + 1 + ID + 3 + 17 + 14 + 9;
    for ( int i = 0; i < hsize; i++)
    {
        outFile << "*";
    }
        outFile << endl;
}
//******************
void resultToFile(char lName[], char fName[], char iD[], int scores[], float avg, char grade, fstream& outFile)
{
   outFile << setw(L_NAME) << left << lName << " "
            <<setw(F_NAME) << left << fName << " "
            <<setw(ID) << right << iD << "      ";

    for (int i = 0; i < TEST_SCORES; i++)
    {
        outFile << setw(3)<< scores[i] << " ";

    }
    outFile << fixed << setprecision(1) << setw(7)<<avg<<setw(7)<<grade<< endl;
}
