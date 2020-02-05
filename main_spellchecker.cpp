

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "dictionary.h"

using namespace std;

void CheckFile()
{
    /// loading the dictionary from file

    Dictionary d("dictionary.txt");

    if(!d.load())
    {
        cout <<"COULD NOT LOAD DICTIONARY !\n";

        return;
    }

    string text; /// stores the name of file to be checked

    cout << "ENTER THE NAME OF FILE: ";

    cin >> text;


    fstream f;

    f.open(text,ios::in);

    if(!f.is_open())
    {
        cout << "COULD NOT OPEN FILE !\n";

        d.unload(); /// free up memory occupied by the dictionary words if the file does not exist.

        return;
    }

    cout << "MISSPELLED WORDS: ";

    string word;

    f >> word;


    while(!f.eof())
    {
        bool misspelled = !d.check(word); /// each word is checked against the set of words stored in dictionary and wrong words

        if(misspelled)
            cout << word << endl;

        f >> word;
    }

    f.close();
}



///A function that saves the file typed by user.
/// User signals the end of file by typing EXITTYPING

void WriteFile()
{
    string filename; /// stores the name of the file to be saved

    fstream f;

    char flag = 'y';

    /// take the name of file from user and
    ///if that file already exists
    ///ask if he/she wants to replace it

    do
    {
        flag = 'y';

        cout << "Save as Filename(No spaces allowed):\t";
        cin >> filename;

        f.open(filename,ios::in);

        if(f.is_open())
        {
            cout << "File already exists\n Do you want to replace it?(y/n)\t";

            cin >> flag;

            f.close();
        }
    }
    while(flag=='n');

    f.open(filename,ios::out);

    if(!f.is_open())
    {
        cout << "COULD NOT OPEN FILE";

        return;
    }

    cout << "ENTER TEXT, Type EXIT and press enter to end file\n";

    /// taking the words from console and printing it in the file

    string word;

    cin >> word;

    while(word.compare("EXIT"))
    {
        f<<word<<" ";
        cin>>word;
    }
    f.close();

    cout << "File saved!";
}


/// A function that adds a word to the dictionary


void AddWord()
{
    cout << "Enter the word you wish to add\n";

    string word;

    cin >> word;

    ofstream f;

    f.open("dictionary.txt",ios::app);

    if(!f.is_open())
        cout << "COULD NOT OPEN" << "dictionary.txt";

    f<<word<<"\n";

    cout << "Added!\n";
}


int main()
{
    // this program gives a menu to user
    // where he or she can choose either to check
    // an existing file,
    // create a new file or
    // to add a word in the dictionary


    cout << "ENTER YOUR CHOICE\n";

    cout << "1. Check a file\n2. Write a file\n3. Add word to Dictionary\n4. Exit\n\n";

    char choice;

    while(true)
    {
        cin >> choice;

        switch(choice)
        {
        case '1':
            CheckFile();
            break;
        case '2':
            WriteFile();
            break;
        case '3':
            AddWord();
            break;
        default:
            return 0;

        }
    }
    return 0;
}
