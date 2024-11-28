#include <stdio.h>
#include <string.h>

#define MIN_ASCII 32
#define MAX_ASCII 126
#define RANGE (MAX_ASCII - MIN_ASCII + 1)

// Function to decrypt the message
void decrypt(char *message, char *key) {
    int keyLength = strlen(key);
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = MIN_ASCII + ((message[i] - MIN_ASCII - (key[i % keyLength] - MIN_ASCII) + RANGE) % RANGE);
    }
}

int main() {
    char message[] = "0?13j#s^kd!ncji0"; // Message to encrypt
    char key[] = "temporary_key";              // Encryption key

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}
