// Author: Noor Eyad Eissa
// Faculty of Computers and Artificial Intelligence, Cairo University, Structured Programming


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// thses variables/arrays are globalized in the whole program for they are going to be used in all of it
int string_length, key = 3; // key is a constant variable,
// and it represents the number of rows that are going to be used in the ,atrix
char matrix[100][100], encrypted[100], decrypted[100];
// 2D array, matrix, for rows and columns

// function to initialize the matrix
void initializing_matrix() {
    for (int i = 0; i < key; i++) { // loops on rows
        for (int j = 0; j < string_length; j++) { // loops on columns
            matrix[i][j] = '*';
        }
    }
}

// function to display matrix to have spaces between its characters
void printing_matrix() {
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < string_length; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// function to fill the matrix with characters in the string
void preparing_matrix_encryption(string text) {
    int column_position = 0, row_position = 0, count = 0;
    for (int i = 0; i < string_length; i++) { // loops on column
        if (i == 0) {
            row_position = 0; // the first character in text is always in the first row
        }
        else {
            if ((row_position == 0 && i > key) || row_position == key - 1) { // if i > key then we have to go up and increase column by 1
                // if we are in the last row we will go up and increase column by 1
                count += 1;
            }
            if (count % 2 == 0) { // hence 0 is even
                row_position += 1;
                column_position += 1;
            }
            else {
                row_position -= 1;
                column_position += 1;
            }
        }
        matrix[row_position][column_position] = text.at(i);
    }
    cout << endl;
}

void encryption() {
    encrypted[string_length];
    int fill = 0;
    for (int i = 0; i < key; i++) { // loops on row
        for (int j = 0; j < string_length; j++) { // loops on column
            if (matrix[i][j] != '*') {
                encrypted[fill] = matrix[i][j];
                fill += 1;
            }
        }
    }
    for (int i = 0; i < string_length; i++) { // prit the encrypted text
        cout << encrypted[i];
    }
}

// function to fill the matrix used for decryption
void preparing_matrix_decryption() {
    int column_position = 0, row_position = 0, count = 0, fill = 0;
    for (int i = 0; i < string_length; i++) {
        if (i == 0) {
            row_position = 0;
        }
        else {
            if ((row_position == 0 && i > key) || row_position == key - 1) {
                count += 1;
            }
            // check the direction
            if (count % 2 == 0) {
                row_position += 1;
                column_position += 1;
            }
            else {
                row_position -= 1;
                column_position += 1;
            }
        }
        matrix[row_position][column_position] = '.';
    }
    cout << endl;
}

void cipher_matrix(string cipher_text) {
    int fill = 0;
    for (int i = 0; i < key; i++) { // loops on row
        for (int j = 0; j < string_length; j++) { // loops o column
            if (matrix[i][j] == '.') {
                matrix[i][j] = cipher_text.at(fill);
                fill += 1;
            }
        }
    }
}

// function to decrypt the text
void decryption() {
    decrypted[string_length];
    int column_position = 0 , row_position = 0, count = 0, fill = 0;
    for (int i = 0; i < string_length; i++) {
        if (i == 0) {
            row_position = 0;
        }
        else {
            if ((row_position == 0 && i > key) || row_position == key - 1) {
                count += 1;
            }
            // check direction
            if (count % 2 == 0) {
                row_position += 1;
                column_position += 1;
            }
            else {
                row_position -= 1;
                column_position += 1;
            }
        }
        if (matrix[row_position][column_position] != '.') {
            decrypted[fill] = matrix[row_position][column_position];
            fill += 1;
        }
    }
    cout << endl;
    for (int i = 0; i < string_length; i++)
    {
        cout << decrypted[i];
    }
}

int main() {
    int choice;
    int choices[3] = { 1, 2, 3 };
    cout << "Hello and welcome to Rail-Fence Cipher program\n";
    cout << "Choose one of 3 options:\n";
    cout << "1. Encryption\n2. Decryption\n3. End\n";
    cout << "Choice: ";
    cin >> choice;
    while (choice != 3) {
        while (choice == 1) {
            string text;
            cout << "Enter the text to be encrypted:  ";
            cin.ignore();
            getline(cin, text);
            auto removing_spaces = remove(text.begin(), text.end(), ' '); // remove spaces
            text.erase(removing_spaces, text.end());
            string_length = text.length();
            initializing_matrix();
            preparing_matrix_encryption (text);
            cout << "Matrix after preparation:\n";
            printing_matrix();
            cout << "\nText after encryption:\n";
            encryption();
            cout << endl;
            break;
        }
        while (choice == 2) {
            string cipher_text;
            cout << "Enter the text to be decrypted:  ";
            cin.ignore();
            getline(cin, cipher_text);
            string_length = cipher_text.length();
            initializing_matrix();
            preparing_matrix_decryption ();
            cout << "Matrix after preparation:\n";
            printing_matrix();
            cout << "\nText after decryption:\n";
            cipher_matrix(cipher_text);
            decryption();
            cout << endl;
            break;
        }
        cout << "Chose another option:  ";
        cin >> choice;
        if (choice == 3) {
            cout << "Thank you for using the program!" << endl;
            cout << "Goodbye!\n";
        }
    }



}
