#include <iostream> // for stdl
#include <fstream>  //for fstream
#include <vector>   //for vector
#include <cstring>  //for string
#include <cmath> //pow, log, log2, log10, et al
#include <algorithm> //min, max, et al
#include <sstream>  //for isstringstream

using namespace std;

vector <char> alphabet;
char vowel[] = {'a', 'e', 'i', 'o', 'u'};
char consonant[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
char punctuation[] = {',', '\'', '-',  '.', '!', '?'};  //couldn't read ... as char
char specificPunctuation[] = {',', '.', '!', '?'};

/////////////////////////////////////////////////Miscellaneous Functions//////////////////////////////////////////////
void createAlphabet ()
{
    for (int i =0; i< sizeof(vowel); i++)
        alphabet.push_back(vowel[i]);
    for (int i = 0; i< sizeof(consonant); i++)
        alphabet.push_back(consonant[i]);

}   //createAlphabet
void convertStringtoChar (string sentence)
{
    char words[sentence.length()];
    for (int i = 0; i < sizeof(words); i++)
    {
        words[i] = sentence[i];
        cout << words[i] << "";
    }
}   //convertStringtoChar

void sentenceBreakdown (string sentence, vector <string> &wordsBreakdown)
{
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        for (int j = 0; j < sizeof(specificPunctuation); j++)
        {
            if (sentence[i] == specificPunctuation[j])
                sentence.erase(remove(sentence.begin(), sentence.end(), specificPunctuation[j]));
        }
    }
    istringstream ss(sentence);
    do
    {
        string word;
        ss >> word;
        wordsBreakdown.push_back(word);
    }
    while (ss);
}   //sentenceBreakdown
/////////////////////////////////////////////////Miscellaneous Functions//////////////////////////////////////////////

/////////////////////////////////////////////////Display Sentence Functions////////////////////////////////////////////
void characterCount (string sentence)
{
    int characterCounter = 0;
    for (int i = 0; i < sentence.length(); i++)
    {
        characterCounter++;
    }
    cout << endl;
    cout << "Number of characters: " << characterCounter << endl;
}   //characterCount

void wordCount (string sentence)
{
    int wordCounter = 1;
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == ' ')
            wordCounter++;
    }
    cout << "Number of words: " << wordCounter << endl;
}   //wordCount

void letterCount (string sentence)
{
    int letterCounter = 0;
    for (int i =0; i < sentence.length(); i++)
    {
        for (int j = 0; j < alphabet.size(); j++)
        {
            if (alphabet[j] == sentence[i] || toupper(alphabet[j]) == sentence[i])
            {
                letterCounter++;
                //cout << "This is a letter: " << sentence[i] << endl;
                break;
            }
        }
    }
    cout << "Number of letters: " << letterCounter << endl;
}   //letterCount

void consonantCount (string sentence)
{
    int consonantCounter = 0;
    for (int i =0; i < sentence.length(); i++)
    {
        for (int j = 0; j < sizeof(consonant); j++)
        {
            if (consonant[j] == sentence[i] || toupper(consonant[j]) == sentence[i])
            {
                consonantCounter++;
                //cout << "This is a consonant: " << sentence[i] << endl;
            }
        }
    }
    cout << "Number of consonants: " << consonantCounter << endl;
}   //consonantCount

void vowelCount (string sentence)
{
    int vowelCounter = 0;
    for (int i =0; i < sentence.length(); i++)
    {
        for (int j = 0; j < sizeof(vowel); j++)
        {
            if (vowel[j] == sentence[i] || toupper(vowel[j]) == sentence[i])
            {
                vowelCounter++;
                //cout << "This is a vowel: " << sentence[i] << endl;
            }
        }
    }
    cout << "Number of vowels: " << vowelCounter << endl;
}   //vowelCount

void punctuationCount(string sentence)
{
    int punctuationCounter = 0;
    for (int i =0; i < sentence.length(); i++)
    {
        for (int j = 0; j < sizeof(punctuation); j++)
        {
            if (punctuation[j] == sentence[i] || toupper(punctuation[j]) == sentence[i])
            {
                punctuationCounter++;
                //cout << "This is a punctuation: " << sentence[i] << endl;
            }
        }
    }
    cout << "Number of punctuations: " << punctuationCounter << endl;
}   //punctuationCount

void spaceCount (string sentence)
{
    int spaceCounter = 0;
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == ' ')
            spaceCounter++;
    }
    cout << "Number of spaces: " << spaceCounter << endl;
}   //spaceCount

void displayTitleCase( string sentence)
{
    for (int i =0; i < sentence.length(); i++)
    {
        if (sentence[i] == ' ')
            sentence[i+1] = toupper(sentence[i+1]);
    }

    cout << "Title Case: ";
    for (int i =0; i < sentence.length(); i++)
    {
        cout << sentence[i] << "";
    }
    cout << endl;
}   //displayTitleCase

void displaySentenceCase(string sentence)
{
    sentence[0] = toupper(sentence[0]);

    cout << "Sentence Case: " << sentence[0];

    for (int i = 1; i < sentence.length(); i++)
    {
        sentence[i] = tolower(sentence[i]);
        cout << sentence[i] << "";
    }
    cout << endl;
}   //displaySentenceCase

void displaySentenceCaseWithExceptions(string sentence)
{
    cout << "Sentence Case with Exceptions: " << sentence[0];
    for (int i = 1; i < sentence.length(); i++)
    {
        cout << sentence[i] << "";
    }
    cout << endl;
}   //displaySentenceCaseWithExceptions

void displayToggleCase(string sentence)
{
    sentence[0] = tolower(sentence[0]);
    for (int i =0; i < sentence.length(); i++)
    {
        if (sentence[i] == ' ')
            sentence[i+1] = tolower(sentence[i+1]);
        else
            sentence[i+1] = toupper(sentence[i+1]);
    }

    cout << "Toggle Case: " << sentence[0];

    for (int i =1; i < sentence.length(); i++)
    {
        cout << sentence[i] << "";
    }
    cout << endl;
}   //displayToggleCase

void displayAlternateCase(string sentence)
{
    for (int i =0; i < sentence.length(); i+=2)
    {
        sentence[i] = toupper(sentence[i]);
        sentence[i+1] = tolower(sentence[i+1]);
    }

    cout << "Alternate Case: " << sentence[0];

    for (int i =1; i < sentence.length(); i++)
    {
        cout << sentence[i] << "";
    }
    cout << endl;
}   //displayAlternateCase

void findLongestWord (string sentence)
{
    vector <string> wordsBreakdown;
    sentenceBreakdown(sentence, wordsBreakdown);
    vector <string> longestWord;
    int longestLength = 0;
    for (int i = 0; i < wordsBreakdown.size(); i++)
    {
        longestWord.push_back(wordsBreakdown[i]);
        if (longestWord[i].length() > longestLength)
            longestLength = longestWord[i].length();
    }
    cout << "longest word length: " << longestLength << endl;
    cout << "The longest word(s): ";

    for (int i = 0; i < wordsBreakdown.size(); i++)
    {
        for (int j = 0; j < wordsBreakdown.size(); j++)
        {
            if (longestWord[i].length() == longestLength && longestWord[i+j].length() == longestLength)
            {
                cout << "|" << longestWord[i] << "| ";
                break;
            }
        }
    }
    cout << endl;
}   //findLongestWord

/////////////////////////////////////////////////Display Sentence Functions////////////////////////////////////////////

/////////////////////////////////////////////////////////Mega Functions////////////////////////////////////////////////
void processString (string sentence)
{
    convertStringtoChar(sentence);
    characterCount(sentence);
    wordCount(sentence);
    createAlphabet();
    letterCount (sentence);
    consonantCount (sentence);
    vowelCount (sentence);
    punctuationCount (sentence);
    spaceCount(sentence);
    displayTitleCase(sentence);
    displaySentenceCase(sentence);
    displaySentenceCaseWithExceptions(sentence);
    displayToggleCase(sentence);
    displayAlternateCase(sentence);
    findLongestWord(sentence);
}   //processString

void addExtraSentence (string extraSentence)
{
    char choice;
    cout << endl;
    cout << "The file has been successfully outputted." << endl;
    cout << "Would you like to add extra sentences? (Y/N)" << endl;
    cin >> choice;
    if (toupper(choice) == 'Y')
    {
        cin.ignore(choice,'\n');
        cout << "Enter the extra sentences. " << endl;
        while (getline(cin, extraSentence))
        {
            cout << "-------------------------------------------------------------------------------------------------" << endl;
            processString(extraSentence);
            cout << endl;
            cout << "Would you like to add extra sentences? (Y/N)" << endl;
            cin >> choice;
            if (toupper(choice) == 'Y')
                {
                    cin.ignore(choice,'\n');
                    cout << "Enter the extra sentences. " << endl;
                    continue;
                }
            else
                {
                    cout << endl;
                    cout << "Exiting Program. " << endl;
                    break;
                }
        }
    }
}   //addExtraSentence
/////////////////////////////////////////////////////////Mega Functions////////////////////////////////////////////////

/////////////////////////////////////////////////////////File Functions////////////////////////////////////////////////
void display (ifstream &infile, string &fileName)
{
    string sentence, extraSentence;
    while (getline(infile, sentence))
    {
        cout << "-------------------------------------------------------------------------------------------------" << endl;
        processString(sentence);
    }
    addExtraSentence(extraSentence);
}   //display

bool validateFile(ifstream &infile, string &fileName)
{
    if ( fileName.length() == 0)
    {
        cout << "Enter input file name" << endl;
        getline(cin, fileName);
        //cin >> fileName;
    }
    infile.open(fileName.c_str());

    if (infile.good())
    {
        cout << "The file: " << fileName << ", has been successfully opened. " << endl;
        return true;
    }
    else
        return false;
}//validateFile

bool readFile(ifstream &infile, string &fileName)
{
    while (true)
    {
        bool result = true;
        result = validateFile(infile, fileName);
        if (result)
            break;
        else
        {
            perror("Can't open the specified input file");
            cout << "The file name used was: " << fileName << endl;
            cout << "Enter another file name to use (or type 'quit'): ";
            //cin >> fileName;
            getline(cin, fileName);
            if (fileName != "quit")
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}   //readFile

void fileReady (ifstream &infile, string &fileName)
{
    bool result;
    result = readFile(infile, fileName);
    if (result)
    {
        display(infile,fileName);
    }
}   //fileReady

/////////////////////////////////////////////////////////Mega Functions////////////////////////////////////////////////
int main()
{
    ifstream infile;
    string fileName;
    fileReady(infile, fileName);
}   //main
