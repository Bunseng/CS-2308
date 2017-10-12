// File Name: p4_b_s329.cpp
//
// Author: Bunrith Seng
// Date: 08/4/2017
// Assignment Number: 4
// CS 2308 Summer 2017
// Instructor: Dan Tamir
//

#ifndef PALINDROME_H_INCLUDED
#define PALINDROME_H_INCLUDED


class classDef{
   private:
       struct node
       {
           char ch;
           node *next;
       }*pt, *temp;

      node *start, *pt1, *pt2;

   public:
      classDef();
      bool isEmpty();
      bool isSingleton();
      void readData();
      bool isPalindrome(node *list);
};


#endif // PALINDROME_H_INCLUDED
