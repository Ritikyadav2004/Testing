#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void copyUsername(char *dest, const char *src) {
    strcpy(dest, src);   // unsafe copy
}

void logMessage(char *msg) {
    printf(msg);         // format string vulnerability
    printf("\n");
}

int main() {
    char username[100];
    char password[100];
    char smallBuffer[16];

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    copyUsername(smallBuffer, username);   // possible buffer overflow

    if (strcmp(password, "admin123") == 0) {
        cout << "Login successful" << endl;
    } else {
        cout << "Login failed" << endl;
    }

    logMessage(username);   // dangerous logging

    char *session = (char*)malloc(8);
    strcpy(session, "ACTIVE_SESSION_TOKEN");  // heap overflow
    free(session);
    free(session);   // double free

    return 0;
}
