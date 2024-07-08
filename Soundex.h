#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

#define SOUNDEX_CODE_LENGTH 4

char getSoundexCode(char c) {
    static const char* soundexTable = "01230120022455012623010202";
    if (isalpha(c)) {
        return soundexTable[toupper(c) - 'A'];
    }
    return '0';
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

void generateSoundex(const char* name, char* soundex) {
    if (name == NULL || soundex == NULL || strlen(name) == 0) {
        return;
    }

    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; name[i] != '\0' && sIndex < SOUNDEX_CODE_LENGTH; i++) {
        char code = getSoundexCode(name[i]);
        appendCode(soundex, code, &sIndex);
    }

    padWithZeros(soundex, sIndex);
}

#endif // SOUNDEX_H
