//
// Created by Kasperi Kaivola on 19.10.2022.
//

#ifndef _MORSE_H_
#define _MORSE_H_
#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <signal.h>
#include <string.h>

struct MorseDecoder {
    char queue[9]; // stores morse chars
    int ind; // index
    int ofd; //output file descriptor
};

char* morseEncode(char x);
void signalMorse(char *buf, pid_t ppid);
void readMorse(int ifd, pid_t parentPid);
char morseDecode(char* s);
void processMorse(struct MorseDecoder *decoder, char signal);
struct MorseDecoder initDecoder(int ofd);

#endif //_MORSE_H_
