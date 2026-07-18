#include <iostream>
#include <cstring>
using namespace std;

// Function to reverse the string
void reverseString(char str[]) {
    int length = strlen(str);

    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to count vowels
int countVowels(char str[]) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' ||
            ch == 'O' || ch == 'U') {
            count++;
        }
    }

    return count;
}

// Function to check palindrome
bool isPalindrome(char str[]) {
    int length = strlen(str);

    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    char str[100];
    char original[100];

    cout << "Enter a string: ";
    cin.getline(str, 100);

    // Store original string
    strcpy(original, str);

    cout << "\nNumber of vowels: " << countVowels(str) << endl;

    if (isPalindrome(str)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    reverseString(str);
    cout << "Reversed string: " << str << endl;

    return 0;
}