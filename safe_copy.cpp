#include <iostream>
#include <cstring>

void copyInput(char *dest, const char *src) {
    strcpy(dest, src);   // unsafe
}

int main() {
    char userInput[50] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    char buffer[10];

    copyInput(buffer, userInput);

    std::cout << buffer << std::endl;
    return 0;
}