//
//  anagram.cpp
//  Project#2
//
//  Created by Daren Sivam on 10/27/22.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>
#include <algorithm>
#include <csignal>
using namespace std;
const int MAXRESULTS   = 20;    // Max matches that can be found
const int MAXDICTWORDS = 10; //30000; // Max words that can be read in

int loadDictionary(istream &dictfile, vector<string>& dict)
{
    /*
    string word;
    if (dictfile >> word && (loadDictionary(dictfile, dict) < MAXDICTWORDS))
    {
      dict.push_back(word);
      return loadDictionary(dictfile, dict) + 1;
    }
    return 0; //recursive method fails test cases
    */
    
    int wordsLoaded = 0;
    std::string currentWord;
    for (dictfile >> currentWord; !dictfile.eof() && wordsLoaded < MAXDICTWORDS; ++wordsLoaded, dictfile >> currentWord) {
        //dict[wordsLoaded] = currentWord;
        dict.push_back(currentWord);
    }
    return wordsLoaded; 
}

string letters(string word)
{
    sort(word.begin() , word.end());
    return word;
}
int permute(string word, vector<string>& dict, vector<string>& results)
{
   // vector<string>::iterator rIt = results.begin();
    int count = 0; //initialize
    string permute = letters(word); //get letters and base search off of permutation letters
    for(vector<string>::iterator dIt = dict.begin(); dIt != dict.end(); dIt++) //traverse dict
    {

        if(permute.compare(letters(*dIt)) == 0) //compare letters within dict to match words and check for duplicates
        {
            if(count >= MAXRESULTS)
            {
                return MAXRESULTS;
            }
            //results[count++] = *dIt;
            results.push_back(*dIt); //insert into result at match
            count++; //increment count
        }
    }
    return count;
}

void display(vector<string>& results) //output results
{
    for(auto it = results.rbegin(); it != results.rend() && *it != ""; it++)
    {
        cout << "Matiching Word " << *it << endl;
    }
}

/*
int main()
{
    vector<string> results(MAXRESULTS);
    vector<string> dict(MAXDICTWORDS);
    ifstream dictfile;         // file containing the list of words
    int nwords;                // number of words read from dictionary
    string word;
    dictfile.open("/Users/darensivam/Desktop/ECC/2nd Year/Fall 22'/CS30/Project#2/Project#2/words.txt");
    if (!dictfile) {
        cout << "File not found!" << endl;
        return (1);
    }
    nwords = loadDictionary(dictfile, dict);
    //cout << dict[3];
    dictfile.close();
    cout << "Please enter a string for an anagram: ";
    cin >> word;
    int numMatches = permute(word, dict, results);
    if (!numMatches)
        cout << "No matches found" << endl;
    else
        display(results);
return 0;
}*/

void testtwo(int n)
{
    vector<string> dictionary;
    vector<string> results;
     
    switch (n)
    {
        default: {
            cout << "Bad argument" << endl;
        } break; case  1: {
            istringstream
iss("dog\ncat\nrat\neel\ntar\nart\nlee\nact\ngod\n");
            int numResults = loadDictionary(iss, dictionary);
            sort(dictionary.begin(), dictionary.end());
            assert(numResults == 9 && dictionary[0] == "act" && dictionary[1] == "art" && dictionary[numResults-1] == "tar");
        } break; case  2: {
// File is empty, Checks that file is empty and loadDictionary returns 0.
istringstream iss("");
int numResults = loadDictionary(iss, dictionary);
assert(numResults == 0);
} break; case  3: {
// Input file is larger than the dictionary size
istringstream
iss("dog\ncat\nrat\neel\ntar\nart\nlee\nact\ngod\ntoo\nmany\nwords\n");
int numResults = loadDictionary(iss, dictionary);
sort(dictionary.begin(), dictionary.end());
assert(numResults == 10 && dictionary[MAXDICTWORDS-
1] == "too");
} break; case  4: {
// If a certain word with repeated letter is shown in results more than once - still accept.
vector<string> dictionary { "one", "oone", "ne",
"e", "too" };
int numResults = permute("oto", dictionary, results);
assert(numResults == 1 && results[0] == "too");
} break; case  5: {
// No fraction of a permutation is being searched in dictionary
vector<string> dictionary { "one", "oone", "ne", "e", "neoo", "oneo" };
int numResults = permute("neo", dictionary,
results);
assert(numResults == 1 && results[0] == "one");
} break; case  6: {
    //cout << MAXRESULTS << endl;
// Checking that no error occurs if more than MAXRESULTS are found.
vector<string> dictionary { "true",  "treu", "teru", "teur", "ture", "tuer", "rtue", "rteu", "retu","reut", "ruet", "rute", "utre", "uter", "uetr", "uert", "urte", "uret", "etru", "etur", "ertu", "erut", "eurt", "eutr" };
// All 24 permutations
int numResults = permute("true", dictionary, results);
assert(numResults == MAXRESULTS);
} break; case  7: {
// Checking one word was found, no duplicates.
vector<string> dictionary { "ppp" };
int numResults = permute("ppp", dictionary, results);
assert(numResults == 1 && results[0] == "ppp");
} break; case  8: {
    streambuf* oldCoutStreamBuf = cout.rdbuf();
    ostringstream strCout;
    cout.rdbuf(strCout.rdbuf());
    vector<string> results { "cat", "act" };
    display(results);
    cout.rdbuf(oldCoutStreamBuf);
    string temp = strCout.str();
    bool match1 = temp.find("act") != string::npos;
    bool match2 = temp.find("cat") != string::npos;
    assert(match1 && match2);
} break; case  9: {
    istringstream iss ("tier\nrite\nbate\ntire\nttir\n");
    int numWords = loadDictionary(iss, dictionary);
    sort(dictionary.begin(), dictionary.end());
    assert(numWords == 5 && dictionary[0] == "bate");
    int numResults = permute("tier", dictionary, results);
    assert(numResults == 3 && (results[2] == "tire" || results[2] == "tier" || results[2] == "rite"));
} break; case  10: {
    vector<string> example { "kool", "moe", "dee" };
    int numResults = permute("look", example, results);
    assert(numResults == 1 && results[0] == "kool");
} break;
}
}

int main()
{
cout << "Enter test number: ";
int n;
cin >> n;
testtwo(n);
cout << "Passed" << endl;
}


/*
//modified test cases to run 1 & 9 properly
void testtwo(int n)
{
    vector<string> dictionary;
    vector<string> results(MAXRESULTS);
     
    switch (n)
    {
        default: {
            cout << "Bad argument" << endl;
        } break; case  1: {
            istringstream
iss("dog\ncat\nrat\neel\ntar\nart\nlee\nact\ngod\n");
            int numResults = loadDictionary(iss, dictionary);
            sort(dictionary.begin(), dictionary.end());
            assert(numResults == 9 && dictionary[0] == "act" &&
dictionary[1] == "art" && dictionary[numResults-1] == "tar");
        } break; case  2: {
            // File is empty, Checks that file is empty and loadDictionary returns 0.
                        istringstream iss("");
                        int numResults = loadDictionary(iss, dictionary);
                        assert(numResults == 0);
                    } break; case  3: {
                        // Input file is larger than the dictionary size
                        istringstream
            iss("dog\ncat\nrat\neel\ntar\nart\nlee\nact\ngod\ntoo\nmany\nwords\n");
                        int numResults = loadDictionary(iss, dictionary);
                        sort(dictionary.begin(), dictionary.end());
                        assert(numResults == 10 && dictionary[MAXDICTWORDS-
            1] == "too");
                    } break; case  4: {
                        // If a certain word with repeated letter is shown in results more than once - still accept.
                        vector<string> dictionary { "one", "oone", "ne", "e", "too" };
                        int numResults = permute("oto", dictionary, results);
                        assert(numResults == 1 && results[0] == "too");
                    } break; case  5: {
                        // No fraction of a permutation is being searched in dictionary
                        vector<string> dictionary { "one", "oone", "ne", "e", "neoo", "oneo" };
                        int numResults = permute("neo", dictionary,
            results);
                        assert(numResults == 1 && results[0] == "one");
                    } break; case  6: {
                        // Checking that no error occurs if more than MAXRESULTS are found.
                        vector<string> dictionary { "true",  "treu", "teru",
            "teur", "ture", "tuer", "rtue", "rteu", "retu","reut", "ruet",
            "rute", "utre", "uter", "uetr", "uert", "urte", "uret", "etru",
            "etur", "ertu", "erut", "eurt", "eutr" };
                        // All 24 permutations
                        int numResults = permute("true", dictionary, results);
                        assert(numResults == MAXRESULTS);
                    } break; case  7: {
                        // Checking one word was found, no duplicates.
                        vector<string> dictionary { "ppp" };
                        int numResults = permute("ppp", dictionary, results);
                        assert(numResults == 1 && results[0] == "ppp");
                    } break; case  8: {
                        streambuf* oldCoutStreamBuf = cout.rdbuf();
                        ostringstream strCout;
                        cout.rdbuf(strCout.rdbuf());
                        vector<string> results { "cat", "act" };
                        display(results);
                        cout.rdbuf(oldCoutStreamBuf);
                        string temp = strCout.str();
                        bool match1 = temp.find("act") != string::npos;
                        bool match2 = temp.find("cat") != string::npos;
                        assert(match1 && match2);
                    } break; case  9: {
                        istringstream iss ("tier\nrite\nbate\ntire\nttir\n");
                        int numWords = loadDictionary(iss, dictionary);
                        sort(dictionary.begin(), dictionary.end());
                        assert(numWords == 5 && dictionary[0] == "bate");
                        int numResults = permute("tier", dictionary, results);
                        assert(numResults == 3 && (results[2] == "tire" || results[2] == "tier" || results[2] == "rite"));
                    } break; case  10: {
                        vector<string> example { "kool", "moe", "dee" };
                        int numResults = permute("look", example, results);
                        assert(numResults == 1 && results[0] == "kool");
                    } break;
                }
            }
             
            int main()
            {
                cout << "Enter test number: ";
                int n;
                cin >> n;
                testtwo(n);
                cout << "Passed" << endl;
            }

*/
