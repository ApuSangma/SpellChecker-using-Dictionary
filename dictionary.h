

#include <string>
using namespace std;

#define nchar 27

/// class implementing the Trie data structure

class dictentry
{
    bool mark; /// marker to indicate leaf node

    dictentry* pointer[nchar]; /// pointer of a-z char of English Alphabet

   public:
       dictentry()
       {
           mark = false;

           for(int i=0; i<27; i++)
           {
               pointer[i] = NULL;
           }

           /// initialized all pointer as NULL
       }

       void Insert(string str); /// inserts a word to the Trie

       bool Search(string word, int i); /// searches a word in the Trie

       void Delete(); /// deletes a word from the Trie

};

class Dictionary
{
public:
    char* dict; /// contains the file name for text file containing the dictionary words

    dictentry* root; /// a pointer to the Trie

    Dictionary(char* file)
    {
        dict = file;

        root = NULL;
    }


    bool load(); /// used to load the words from the file to memory. returns True if the operation is successful else False.

    /// used to free the memory used by Trie DS.
    void unload();

    ///This checks the given word in the dictionary file
    /// and returns True if present else false.

    bool check(string word);
};
