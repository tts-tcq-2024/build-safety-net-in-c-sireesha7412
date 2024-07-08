#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

#define SOUNDEX_CODE_LENGTH 4

char getSoundexCode(char c) {
    static const char* soundexTable = "01230120022455012623010202";
    return isalpha(c) ? soundexTable[toupper(c) - 'A'] : '0';
}

void appendCode(char* soundex, char code, int* sIndex) {
    if (code != '0' && code != soundex[*sIndex - 1]) {
        soundex[(*sIndex)++] = code;
    }
}

void padWithZeros(char* soundex, int sIndex) {
    while (sIndex < SOUNDEX_CODE_LENGTH) {
        soundex[sIndex++] = '0';
    }
    soundex[SOUNDEX_CODE_LENGTH] = '\0';
}

void processName(const char* name, char* soundex, int* sIndex) {
    for (int i = 1; name[i] != '\0' && *sIndex < SOUNDEX_CODE_LENGTH; i++) {
        char code = getSoundexCode(name[i]);
        appendCode(soundex, code, sIndex);
    }
}

int isValidName(const char* name) {
    return name != NULL && name[0] != '\0';
}

void initializeSoundex(char* soundex, char firstChar) {
    soundex[0] = toupper(firstChar);
}

void generateSoundex(const char* name, char* soundex) {
    if (!isValidName(name)) {
        return;
    }

    int sIndex = 1;
    initializeSoundex(soundex, name[0]);
    processName(name, soundex, &sIndex);
    padWithZeros(soundex, sIndex);
}

#endif // SOUNDEX_H
