/* Author: Evelyn Pan
 * Assignment Title: Project 10
 * Assignment Description: Caesar Cipher
 *
 * Due Date: 2/17/22
 * Date Created: 2/18/22
 * Date Last Modified: 2/18/22
*/

/* Data Abstraction: Output file stream is opened.
 * Program sets the input file, file name, message, command,
 * letter counts, and shifts.
 *
 // Input: The program reads input as the precursor.
 * The program uses loop function to try and match
 * whether or not the user's number matches the right guess.
 * Prompts the user for the file name and
 * encrypt or decrypt.
 *
 // Process:
 * Program checks if the encrypt or decrypt matches with
 * the command and sees if the file will open or not.
 * Program has a while statement for the letter counts.
 *
 //Output:
 * Outputs the letter frequencies.
 * Cloes the message and inputFile.
 *
 // Assumptions:
 * It is assumed that:
 * If the user puts in a suitable inputFile, name,
 * encrypt or decrypt, the code will open and run
 * the letter counts and shifts accordingly.
 *
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

int main() {
    //data abstraction
    
    ifstream inputFile;
    string fileName;
    ofstream message;
    string command;
    char n;
    int aCount = 0, eCount = 0, iCount = 0,
    oCount = 0, uCount = 0, yCount = 0;
    int shift = 3;
    bool goodCommand = true;
    
    
    
    //input
    
    cout << "Enter File Name: ";
    cin >> fileName;
    cout << fileName << endl;
    inputFile.open(fileName);
    cout << "Enter encrypt or decrypt: ";
    cin >> command;
    cout << command << endl;
    
    //process
    
    if (command != "encrypt" && command != "decrypt") {
        goodCommand = false;
        cout << "Error: Bad Command. " << endl;
    }
    if (!inputFile) {
        goodCommand = false;
        cout << "Error: File did NOT open." << endl;
    }
    
    if (goodCommand) {
        cout << endl;
        if (command == "decrypt") {
            shift = -3;
        }
        
        message.open("message");
        while(inputFile.get(n)) {
            if (n == 'A' || n == 'a') {
                aCount++;
            }
            if (n == 'E' || n == 'e') {
                eCount++;
            }
            if (n == 'I' || n == 'i') {
                iCount++;
            }
            if (n == 'O' || n == 'o') {
                oCount++;
            }
            if (n == 'U' || n == 'u') {
                uCount++;
            }
            if (n == 'Y' || n == 'y') {
                yCount++;
            }
            if (n == '\n') {
                cout << endl;
                message << n;
            }
            else {
                n += shift;
                cout << n;
                message << n;
            }
        }
   
    
    //output
    
        cout << endl << endl;
        cout << "Letter Frequency" << endl;
        cout << setw(4) << "A" << setw(7) << aCount << endl;
        cout << setw(4) << "E" << setw(7) << eCount << endl;
        cout << setw(4) << "I" << setw(7) << iCount << endl;
        cout << setw(4) << "O" << setw(7) << oCount << endl;
        cout << setw(4) << "U" << setw(7) << uCount << endl;
        cout << setw(4) << "Y" << setw(7) << yCount << endl;
        
        message.close();
        inputFile.close();
        
    }
    return 0;
}
