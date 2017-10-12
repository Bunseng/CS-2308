// File Name: p4_b_s329.cpp
//
// Author: Bunrith Seng
// Date: 08/4/2017
// Assignment Number: 4
// CS 2308 Summer 2017
// Instructor: Dan Tamir
//


#include<iostream>
#include<string>
#include<fstream>
#include "palindrome.h"

using namespace std;


classDef::classDef(){
     start = NULL;
}

bool classDef::isPalindrome(node *list){

     pt = pt1 = pt2 = list;

     if (list == NULL)
        return true;
     while (pt1->next != NULL){
          pt1 = pt1->next;
     }

     while (pt != NULL && pt->next != NULL){

          if (pt1->ch != pt->ch){
            return false;
          }
          else {
             pt2 = pt;
             while(pt2->next != pt1 && pt2->next != NULL)
                  pt2 = pt2->next;
             pt2->next = NULL;
             pt1 = pt2;
         }
         pt = pt->next;
     }
     return true;

}

//check if list is empty
bool classDef::isEmpty()
{
    node *list;
    if(list == NULL)
        return true;
    else
        return false;
}

//if the function is singleton, return true;
//
bool classDef::isSingleton()
{
    node *next;
    if (next == NULL)
        return false;
    else if(next->next == NULL)
        return true;
    else
        return false;
}

void classDef::readData(){


    string myString;
    ifstream in;


    in.open("input.txt");
    if (!in)
        cout << "Error opening file"<< endl;

     else   {
       while (getline(in,myString)) {
           cout << myString << ":   ";
           start = NULL;

           for (int i=0; i<myString.length(); i++){
               if (isalpha(myString[i]) || myString[i] == '\n'){
                  if (start == NULL){
                     temp = new node;
                     temp->ch = myString[i];
                     temp->next = NULL;
                     start = temp;
                  }
                  else {
                     temp = new node;
                     temp->ch = myString[i];
                     temp->next = NULL;
                     pt = start;
                     while (pt->next != NULL)
                        pt = pt->next;
                     pt->next = temp;
                 }
             }
          }
          if (isPalindrome(start))
             cout << "A palindrome" << endl;
          else
            cout << "No a palindrome" << endl;


       }
    }
}

int main(){

   classDef data;
   data.isEmpty();
   data.isSingleton();
   data.readData();
   return 0;
}
