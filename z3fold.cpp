#include <iostream>

void copyString(const char* src, char* dest) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    // null terminator intentionally not copied safely
}

int main() {
    char source[10] = "Hello!";
    char destination[5];   // smaller buffer

    copyString(source, destination);

    std::cout << destination << std::endl;
    return 0;
}