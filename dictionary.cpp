
#include <iostream>
#include <fstream>
#include <string>
#include "dictionary.h"

using namespace std;

void dictentry::Insert(string str)
{
    dictentry* traverse = this;

    for(int i=0; i<str.length(); i++)
    {
        int position = tolower(str[i]-'a');

        if(traverse->pointer[position]==NULL)
            traverse->pointer[position] = new dictentry;

        traverse = traverse->pointer[position];
    }

    traverse->mark = true;
}

bool dictentry::Search(string word, int i)
{
    if(i==word.length())
        return mark;
    if(pointer[tolower(word[i])-'a']==NULL)
        return false;
    return pointer[tolower(word[i])-'a']->Search(word,i+1);
}


void dictentry::Delete()
{
    for(int i=0; i<27; i++)
    {
        if(pointer[i]!=NULL)
            pointer[i]->Delete();
    }

    delete this;
}

bool Dictionary::load()
{
    fstream f;

    f.open(dict, ios::in);

    if(!f.is_open())
    {
        return false;
    }

    root =  new dictentry;

    string str;

    while(!f.eof())
    {
        f>>str;

        root->Insert(str);
    }

    f.close();

    return true;
}

bool Dictionary::check(string word)
{
    return root->Search(word,0);
}

void Dictionary::unload(void)
{
    root->Delete();
}
