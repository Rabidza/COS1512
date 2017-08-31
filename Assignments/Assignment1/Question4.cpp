//A simple encryption program
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

string getFileName();
//Gets the file name

void encrypt(istream& fin, ostream& fout);
//Takes a file as input and encryptes the content

void decrypt(istream& fin, ostream& fout);
//Takes a file as input and decrypts the content

void displayFile(istream& fileName);

int main()
{
    ifstream fin;
    ofstream fout;
    ifstream readFile;
    string source;
    string target;
    char option;

    cout << "#############################################" << endl
         << "## This is a Decryption/Encryption Program ##" << endl
         << "#############################################" << endl << endl;

    cout << "Do you want to encrypt or decrypt the source file? (e/d): ";
    cin >> option;

    cout << "Please enter the source filename: ";
    cin >> source;
    fin.open(source.c_str());
    if (fin.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    cout << "Please enter the target filename: ";
    cin >> target;
    fout.open(target.c_str());
    if (fout.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    if (option == 'E' || option == 'e')
        encrypt(fin, fout);
    else
        decrypt(fin, fout);

    fin.close();
    fout.close();

    //Display source and target file
    cout << "Source file: " << endl;
    readFile.open(source.c_str());
    displayFile(readFile);
    readFile.close();

    cout << "Target file: " << endl;
    readFile.open(target.c_str());
    displayFile(readFile);
    readFile.close();

    return 0;
}

string getFileName()
{
    string fileName;
    cin >> fileName;
    return fileName;
}

void encrypt(istream& fin, ostream& fout)
{
    char next;
    fin.get(next);
    while (! fin.eof( ))
    {
        if (isalpha(next))
            if (next == 'Z')
                fout << 'A';
            else if (next == 'z')
                fout << 'a';
            else
                fout << static_cast<char>(next + 1);
        else
            fout << next;
        fin.get(next);
    }
    cout << endl << "File Encrypted" << endl;
}

void decrypt(istream& fin, ostream& fout)
{
    char next;
    fin.get(next);
    while (! fin.eof( ))
    {
        if (isalpha(next))
            if (next == 'A')
                fout << 'Z';
            else if (next == 'a')
                fout << 'z';
            else
                fout << static_cast<char>(next - 1);
        else
            fout << next;
        fin.get(next);
    }

    cout << endl << "File Decrypted" << endl;
}

void displayFile(istream& fileName)
{
    char next;
    fileName.get(next);
    while (! fileName.eof( ))
    {
        cout << next;
        fileName.get(next);
    }

    cout << endl << endl;
}
