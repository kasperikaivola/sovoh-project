ELEC-C7310 - Sovellusohjelmointi - Assignment 1
-------------------------------------------------------

A pair of C programs that work in the following way:
1.
Assignment1: Manager program made using the as1_mockup template.
-Takes input parameters, uses execl for code replacement (Assignment1-child) after taking parameters and passes them to the actual morse program
2.
Assignment1-child: The actual morse program that uses fork() to create a child process, and after that the 2 processes use SIGUSR1 and SIGUSR2 to communicate morse code.
-The child process open the input stream, and uses the included libray functions (morse.c, morse.h) to send signals to the parent process
