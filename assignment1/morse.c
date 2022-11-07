//
// Created by Kasperi Kaivola on 19.10.2022.
//
// C library to


#include <stdlib.h>
#include <time.h>
#include "morse.h"

// function to encode a alphabet as
// Morse code
char *morseEncode(char x) {
    // refer to the Morse table
    // image attached in the article
    switch (x) {
        case 'A':return ".-";
        case 'B':return "-...";
        case 'C':return "-.-.";
        case 'D':return "-..";
        case 'E':return ".";
        case 'F':return "..-.";
        case 'G':return "--.";
        case 'H':return "....";
        case 'I':return "..";
        case 'J':return ".---";
        case 'K':return "-.-";
        case 'L':return ".-..";
        case 'M':return "--";
        case 'N':return "-.";
        case 'O':return "---";
        case 'P':return ".--.";
        case 'Q':return "--.-";
        case 'R':return ".-.";
        case 'S':return "...";
        case 'T':return "-";
        case 'U':return "..-";
        case 'V':return "...-";
        case 'W':return ".--";
        case 'X':return "-..-";
        case 'Y':return "-.--";
        case 'Z':return "--..";
        case '1':return ".----";
        case '2':return "..---";
        case '3':return "...--";
        case '4':return "....-";
        case '5':return ".....";
        case '6':return "-....";
        case '7':return "--...";
        case '8':return "---..";
        case '9':return "----.";
        case '0':return "-----";
        case '&':return ".-...";
        case '\'':return ".----.";
        case '@':return ".--.-";
        case ')':return "-.--.-";
        case '(':return "-.--.";
        case ':':return "---...";
        case ',':return "--..--";
        case '=':return "-...-";
        case '!':return "-.-.--";
        case '.':return ".-.-.-";
        case '-':return "-.....-";
        case '+':return ".-.-.";
        case '"':return ".-..-.";
        case '?':return "..--..";
        case '/':return "-..-.";
        case '\0':return ".-.-.";
        case EOF:return ".-.-.";
        case '\n':return ".-.-";
        default: return "......."; //return error morse
    }
}

char morseDecode(char *s) {
    //printf("%s\n",s);
    if (strcmp(s, ".-") == 0) return 'A';
    else if (strcmp(s, "-...") == 0)    return 'B';
    else if (strcmp(s, "-.-.") == 0)    return 'C';
    else if (strcmp(s, "-..") == 0)     return 'D';
    else if (strcmp(s, ".") == 0)       return 'E';
    else if (strcmp(s, "..-.") == 0)    return 'F';
    else if (strcmp(s, "--.") == 0)     return 'G';
    else if (strcmp(s, "....") == 0)    return 'H';
    else if (strcmp(s, "..") == 0)      return 'I';
    else if (strcmp(s, ".---") == 0)    return 'J';
    else if (strcmp(s, "-.-") == 0)     return 'K';
    else if (strcmp(s, ".-..") == 0)    return 'L';
    else if (strcmp(s, "--") == 0)      return 'M';
    else if (strcmp(s, "-.") == 0)      return 'N';
    else if (strcmp(s, "---") == 0)     return 'O';
    else if (strcmp(s, ".--.") == 0)    return 'P';
    else if (strcmp(s, "--.-") == 0)    return 'Q';
    else if (strcmp(s, ".-.") == 0)     return 'R';
    else if (strcmp(s, "...") == 0)     return 'S';
    else if (strcmp(s, "-") == 0)       return 'T';
    else if (strcmp(s, "..-") == 0)     return 'U';
    else if (strcmp(s, "...-") == 0)    return 'V';
    else if (strcmp(s, ".--") == 0)     return 'W';
    else if (strcmp(s, "-..-") == 0)    return 'X';
    else if (strcmp(s, "-.--") == 0)    return 'Y';
    else if (strcmp(s, "--..") == 0)    return 'Z';
    else if (strcmp(s, ".----") == 0)   return '1';
    else if (strcmp(s, "..---") == 0)   return '2';
    else if (strcmp(s, "...--") == 0)   return '3';
    else if (strcmp(s, "....-") == 0)   return '4';
    else if (strcmp(s, ".....") == 0)   return '5';
    else if (strcmp(s, "-....") == 0)   return '6';
    else if (strcmp(s, "--...") == 0)   return '7';
    else if (strcmp(s, "---..") == 0)   return '8';
    else if (strcmp(s, "----.") == 0)   return '9';
    else if (strcmp(s, "-----") == 0)   return '0';
    else if (strcmp(s, ".-...") == 0)   return '&';
    else if (strcmp(s, ".----.") == 0)  return '\'';
    else if (strcmp(s, ".--.-") == 0)   return '@';
    else if (strcmp(s, "-.--.-") == 0)  return ')';
    else if (strcmp(s, "-.--.") == 0)   return '(';
    else if (strcmp(s, "---...") == 0)  return ':';
    else if (strcmp(s, "--..--") == 0)  return ',';
    else if (strcmp(s, "-...-") == 0)   return '=';
    else if (strcmp(s, "-.-.--") == 0)  return '!';
    else if (strcmp(s, ".-.-.-") == 0)  return '.';
    else if (strcmp(s, "-.....-") == 0) return '-';
    else if (strcmp(s, ".-.-.") == 0)   return '+';
    else if (strcmp(s, ".-..-.") == 0)  return '"';
    else if (strcmp(s, "..--..") == 0)  return '?';
    else if (strcmp(s, "-..-.") == 0)   return '/';
    else if(strcmp(s,".-.-")==0)        return '\n';
    else                                return '*'; //if no match for morse letter return this
}
//a simple struct to keep track of where we are in a morse character, initializer, max morse char length=8
struct MorseDecoder initDecoder(int ofd) {
    struct MorseDecoder ret = {.ind = 0, .ofd = ofd, .queue[8]='\0'};
    return ret;
}

void signalMorse(char *s, pid_t parentPid) {
    //max morse length is 8->8+newline=9
    char morseChar[9];
    sigset_t sigset;
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGUSR1);
    sigaddset(&sigset, SIGUSR2);
    sigprocmask(SIG_BLOCK, &sigset, NULL);
    //go through input char pointer
    for (int i = 0; s[i]; i++) {
        int sig;
        //morseEncode encodes a char as morse, then write that to morseChar variable
        snprintf(morseChar, 8, "%s", morseEncode(s[i]));
        //Go through the dots and lines in morseChar
        for (int j = 0; morseChar[j]; j++) {
            sigwait(&sigset, &sig);
            if (morseChar[j] == '.') { kill(parentPid, SIGUSR1); }
            else if (morseChar[j] == '-') { kill(parentPid, SIGUSR2); }
            else continue;
        }
        sigwait(&sigset, &sig);
        kill(parentPid, SIGALRM); //end of a char marked with SIGALRM
    }
}

void readMorse(int ifd, pid_t parentPid) {
    char buf[129];
    long n;
    while ((n = read(ifd, buf, 128)) > 0) {
        buf[n] = '\0';  //Terminate string, read() doesn't do this automatically
        signalMorse(buf, parentPid);
    }
    nanosleep((const struct timespec[]){{0, 3000000L}}, NULL);
}
//library function for receiving end of the signal transmission
void processMorse(struct MorseDecoder *decoder, char signal) {
    if(signal==SIGUSR1) {
        decoder->queue[decoder->ind] = '.';
        decoder->queue[decoder->ind+1] = '\0'; //close string
        decoder->ind = decoder->ind+1; //next index
    }
    else if(signal==SIGUSR2) {
        decoder->queue[decoder->ind] = '-';
        decoder->queue[decoder->ind+1] = '\0'; //close string
        decoder->ind = decoder->ind+1; //next index
    }
    else if (signal == SIGALRM) { // end of a morse char reached, turn it into a normal char with morseDecode
        decoder->queue[decoder->ind] = '\0';
        char retChar = morseDecode(decoder->queue);
        //printf("%s", decoder->queue);
        decoder->ind = 0;
        write(decoder->ofd, &retChar, 1);
    }
    else if (signal == SIGINT) {
        printf("Process received SIGINT\nClosing...\n");
        exit(1);
    }
}
