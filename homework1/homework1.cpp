#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct book {
    string title;
    string author;
    int wordCount;
    int letterFrequency;
    int lineCount;
};

int main()
{
    // Input file name to be read
    string fileName;
    cout << "Enter name of file to be processed: ";
    cin >> fileName;

    // Attempt to open file, if fail then retry
    fstream bookData;
    bookData.open("C:\\Users\\natet\\source\\repos\\homework1\\homework1\\" + fileName + ".txt", ios::in); //change natet to whatever your username is on your laptop
    while (bookData.fail()) {                                                                              //unless you changed your directory, if so good luck
        cout << "Invalid file name, input another file name." << endl;
        cin >> fileName;
        bookData.open(fileName + ".txt", ios::in);
    }
    
    book newBook;
    
    if (bookData.is_open()) {
        string text;
   
        int numberWords = 0;
        int numberLines = 0;

        getline(bookData, text); //Grabs first line, sets title
        newBook.title = text;
        getline(bookData, text); //Grabs second line, sets author
        newBook.author = text;

        while (getline(bookData, text)) {                //Runs through each line, then runs through each word in that line with space delimiter
            while (getline(bookData, text, ' ')) {
                numberWords++;
            }
            numberLines++; //this is fucked up
        }


        newBook.wordCount = numberWords;
        newBook.lineCount = numberLines;
    }

    cout << newBook.title << endl << newBook.author << endl << newBook.wordCount << endl << newBook.lineCount; //removing this later


}
