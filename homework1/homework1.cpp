#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//const std::string PATH = "C:\\Users\\natet\\source\\repos\\homework1\\homework1\\"; // not needed
const int ARRAY_SIZE = 26;

struct book {
    std::string title;
    std::string author;
    int wordCount;
    double letterFrequency[ARRAY_SIZE] = { 0 };
    int lineCount;
};

int main()
{
    // Input file name to be read
    std::string fileName;
    std::cout << "Enter name of file to be processed: ";
    std::cin >> fileName;

    // Attempt to open file, if fail then retry
    std::fstream bookData;
    bookData.open(fileName + ".txt", std::ios::in); 
    while (bookData.fail()) {                                                                              
        std::cout << "Invalid file name, input another file name." << std::endl;
        std::cin >> fileName;
        bookData.open(fileName + ".txt", std::ios::in);
    }
    
    book newBook;
    
    if (bookData.is_open()) {
        std::string line;
        char ch;
        int numberCharacters = 0;
        int numberWords = 0;
        int numberLines = 0;

        getline(bookData, line); //Grabs first line, sets title
        newBook.title = line;
        getline(bookData, line); //Grabs second line, sets author
        newBook.author = line;

        while (getline(bookData, line)) {  //Runs through each line, incrementing numberLines by one
            numberLines++;
            std::stringstream ss(line);        //Stringstream object allows us to extract the line that was just read, then find how many words were in that line using space delimiter
            while (getline(ss, line, ' ')) {
                numberWords++;                           
                for (int i = 0; i < line.length(); i++) {   //Runs through the word and increments the letter frequency by one in letterFrequency.
                    char chUpper = toupper(line[i]);
                    if (chUpper >= 'A' && chUpper <= 'Z') {
                        newBook.letterFrequency[chUpper - 'A']++;
                        numberCharacters++;
                    }
                }
            }
        }

        //Loop through letterFrequency and divide each entry by totalCharacters to provide percentage.
        for (int i = 0; i < ARRAY_SIZE; i++) {
           newBook.letterFrequency[i] /= numberCharacters;
        }
       
        newBook.wordCount = numberWords;
        newBook.lineCount = numberLines;

    }

    std::cout << newBook.title << std::endl << newBook.author << std::endl << newBook.wordCount << std::endl << newBook.lineCount << std::endl; //remove if u want

    
    /*
    
    Example of how to loop through letterFrequency with ASCII elements, i.e. "A: 0.06654%"

    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << char(i + 65) << ": " << newBook.letterFrequency[i] << std::endl;
    }
    
    */
    
    


}
