#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
const int MAX = 80;
class String
{
private:
char * cadena;
public:
String();
// constructor por defecto.
String(char* s);
// constructor com�n
String(const String &);
// constructor de copia
~String();
// destructor
String operator=(const String &);
// sobrecarga de asignaci�n
bool operator==(String);
// compara dos strings por igualdad.
bool operator< (String);
// compara dos strings alfab�ticamente
String operator+ (String);
// concatenaci�n de strings.
void scan();
// lee un string desde la entrada est�ndar.
void print();
// muestra un string en la salida est�ndar
int ConvertStringToInt();
//convierte un string en un entero y lo retorna
};
#endif // STRING_H_INCLUDED
