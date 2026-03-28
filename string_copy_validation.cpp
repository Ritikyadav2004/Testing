#include <iostream>
#include <cstring>

bool copyString(const char* source, char* destination, size_t destSize) {
    if (source == nullptr || destination == nullptr || destSize == 0) {
        return false;
    }

    size_t sourceLen = std::strlen(source);

    // Prevent buffer overflow
    if (sourceLen >= destSize) {
        return false;
    }

    std::strncpy(destination, source, destSize - 1);
    destination[destSize - 1] = '\0';

    return true;
}

int main() {
    const char source[] = "Hello!";
    char destination[10];

    if (copyString(source, destination, sizeof(destination))) {
        std::cout << "Copied string: " << destination << std::endl;
    } else {
        std::cout << "Copy failed: destination buffer too small or invalid input." << std::endl;
    }

    return 0;
}