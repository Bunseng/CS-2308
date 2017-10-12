// File Name: p3_b_s329.cpp
//
// Author: Bunrith Seng
// Date: 07/31/2017
// Assignment Number: 3
// CS 2308 Summer 2017
// Instructor: Dan Tamir
//
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;


//function prototypes
void encryptString(string, string);
bool verifyKey();
void changeKey(fstream &ioFile, string);
void validateKey(fstream &ioFile, string);

char option;
int main()
{

    //char option;
    string packet, currentKey;
    fstream ioFile;
    ioFile.open("key.txt", ios::in);
    ioFile.open("encrypt.txt", ios::out);

    do {
        cout <<"\n Select your option";
        cout << "\n =========";
        cout << "\nA: Encrypt String";
        cout << "\nB: Change Key";
        cout << "\nC: Validate key";
        cout << "\nD: Quit\n";
        cout << "\nEnter your selection: ";

        cin >> option;
        cin.ignore();

        if ((option !='d') && (option != 'D'))
        {
            switch(option)
            {
                case 'a':
                case 'A':
                    encryptString(packet, currentKey);
                    break;
                case 'b':
                case 'B':
                    changeKey(ioFile, currentKey);
                    break;
                case 'c':
                case 'C':
                    validateKey(ioFile, currentKey);
                    break;
                default:
                    cout << "\nInvalid character input.\n";

            }
        }



    }while((option != 'd') && (option != 'D'));


    ioFile.close();

    return 0;

}

void encryptString(string packet, string currentKey)
{

  fstream ioFile;
  ioFile.open("encrypt.txt", ios::out);
  //char option;
  bool flag = false;

  if((option == 'A') || (option == 'a'))
    {
        cout << "Enter a string you wanna be encrypted: ";
        getline(cin, packet);
        string encrypKey = packet;

        for (int i = 0; i < packet.size(); i++)
        {
            encrypKey[i] = packet[i] ^ currentKey[i];

        }
        //cout << encrypKey;
        ioFile << "Encrypted string: " << encrypKey;
        ioFile.close();

        packet.clear();
        cin.sync();

    }
    else
    {
        cout << "\nInvalid character input.\n";
        flag = true;
    }

    if (!flag)
    {
        int m = packet.length();
        int n = currentKey.length();
        for (int k = 0; k < m; k++)
         {
             packet[k] ^= currentKey[k%n];
             cout << packet;

         }

         //change unprintable chars to blank
         string toPrint(packet);
         for (int j = 0; j < m; j++)
         {
             if(!isprint(toPrint[j]))
             {
                 toPrint[j] = ' ';
             }
         }
         cout << toPrint;

          ioFile.close();

    }

}
bool verifyKey()
{
    string currentKey;
    bool test = true;
    int length = currentKey.length();
    char check;

    //check length
    if(length < 8)
    {
        test = false;
        return test;
    }
    //check for uppercase
    test = false;
    for (int count = 0; count < length; count++)
    {
        check = currentKey.at(count);
        if(isupper(check))
        {
            test = true;
            break;
        }
    }
    if(!test)
        return test;
    //check digit
    test = false;
    for (int count = 0; count < length; count++)
    {
        check = currentKey.at(count);
        if(isdigit(check))
        {
            test = true;
            break;
        }
    }
    if(!test)
        return test;
    //check special chars
    test = false;
    for (int count = 0; count < length; count++)
    {
        check = currentKey.at(count);
        if((check == '!') || (check == '@') || (check == '#') || (check == '$'))
        {
            test = true;
            break;
        }
    }
    if(!test)
        return test;
}

void changeKey(fstream &ioFile,string currentKey)
{

    //string currentKey;
    //fstream ioFile;
    //ioFile.open("key.txt", ios::in | ios::out);

    currentKey.clear();
    cout << "\nNEW KEY\n";
    cout << "Please enter a key meeting the following requirements:\n";
    cout << "- At least 8 characters long\n";
    cout << "- Contains at least one uppercase letter\n";
    cout << "- Contains at least one digit\n";
    cout << "- Contains at least one of these four characters: !@#$\n";
    cin.sync();
    getline(cin, currentKey);

    if(!verifyKey())
    {
        currentKey.clear();
        ioFile.open("key.txt", ios::in);
        ioFile >> currentKey;

        ioFile.clear();
        ioFile.close();

        //indicate key change
        cout << endl << "\nBad key\n";
        cout << "The key has not changed.\n";
    }
    else
    {
        ioFile.open("encrypt.txt", ios::out);
        ioFile<<currentKey;
        ioFile.close();

        cout << "\nBad key\n";
        cout << "The key has not changed.\n";
    }
}
void validateKey(fstream &ioFile,string currentKey)
{
    //string currentKey;
    //fstream ioFile;
    //ioFile.open("key.txt", ios::in | ios::out);

    // Check for existing key or ask for a new one
    if (ioFile.fail())
    {
        // File does not exist, prompt for new key and verify
        cout << "\nNO KEY EXISTS\n";
        cout << "Please enter a key meeting the following requirements:\n";
        cout << "- At least 8 characters long\n";
        cout << "- Contains at least one uppercase letter\n";
        cout << "- Contains at least one digit\n";
        cout << "- Contains at least one of these four characters: !@#$\n";
        cin.sync();
        getline(cin, currentKey);

        while (!verifyKey())
        {
            currentKey.clear();
            cout << "\nBAD KEY\n";
            cout << "Please enter a key meeting the requirements:\n";
            cout << "- At least 8 characters long\n";
            cout << "- Contains at least one uppercase letter\n";
            cout << "- Contains at least one digit\n";
            cout << "- Contains at least one of these four characters: !@#$\n";
            cin.sync();
            getline(cin, currentKey);
        }
        // Write new verified key to file
        ioFile.clear();
        ioFile.open("encrypt.txt", ios::out);
        ioFile << currentKey;
        ioFile.close();
    }
    else if (ioFile)
    {
        // File exists, read and verify key
        ioFile >> currentKey;
        ioFile.clear();
        ioFile.close();

        if (!verifyKey())
        {
            // Loop until user inputs a GOOD key
            while (!verifyKey())
            {
                currentKey.clear();
                cout << "\nBAD KEY\n";
                cout << "Please enter a key meeting the requirements:\n";
                cout << "- At least 8 characters long\n";
                cout << "- Contains at least one uppercase letter\n";
                cout << "- Contains at least one digit\n";
                cout << "- Contains at least one of these four characters: !@#$\n";
                cin.sync();
                getline(cin, currentKey);
            }
            // Write GOOD key to a file
            ioFile.open("encrypt.txt", ios::out);
            ioFile << currentKey;
            ioFile.close();
            cout << "\nGOOD KEY\n";
            cout << "Key has been updated!\n";
        }
        else if (verifyKey())
        {
            // Indicates exisiting key is good and will be used
            cout << "\nGOOD KEY\n";
            cout << "Using the existing good key!\n";
        }
        else
        {
            // Something is wrong!
            cout << "ERROR(2)!\n";
        }
    }
    else
    {
        // Something is wrong!
        cout << "ERROR(1)!\n";
    }

}
