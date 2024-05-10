#include <iostream>
//  #include <cctype>

char getNextLetter(char letter) {
    if (letter == 'z') {
        return 'a';
    } else if (letter == 'Z') {
        return 'A';
    } else if (std::isalpha(letter)) {
        return letter + 1;
    } else {
        return letter; // If the input is not a letter, return the same character
    }
}

int main() {
    char userLetter;
    char response;

    std::cout << "Hi! I'm a clever computer program that knows the alphabet." << std::endl;

    do {
        std::cout << "Please enter a letter:" << std::endl;
        std::cin >> userLetter;

        char nextLetter = getNextLetter(userLetter);

        std::cout << "The next letter is " << nextLetter << "." << std::endl;

        std::cout << "Do you want to enter another letter (y = yes)? ";
        std::cin >> response;

    } while (response == 'y' || response == 'Y');

    std::cout << "Goodbye!" << std::endl;

    return 0;
}
