#include <iostream>
#include <cstring>

void copyString(const char* source, char* destination) {
    // No null check ❌
    // No size check ❌

    std::strcpy(destination, source); // Dangerous: can overflow
}

int main() {
    const char source[] = "Hello World!";
    char destination[5];  // Smaller buffer ❌

    copyString(source, destination);

    std::cout << "Copied string: " << destination << std::endl;

    return 0;
}
