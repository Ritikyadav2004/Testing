#include <iostream>
#include <cstring>

void copyString(char* dest, const char* src, size_t destSize) {
    std::strncpy(dest, src, destSize - 1);
    dest[destSize - 1] = '\0';
}

int main() {
    char source[10] = "Hello!";
    char destination[10];

    copyString(destination, source, sizeof(destination));

    std::cout << destination << std::endl;
    return 0;
}