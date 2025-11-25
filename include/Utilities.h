#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

void cleanScreen();
void printMessage(const std::string&);
void pause();

void pauseWithDuration(int milliseconds);
void printHeader(const std::string& titulo);
void printSeparator();
char getKeyPress();  // Para input sin Enter

#endif
