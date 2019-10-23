#include <cstdio>
#include <string.h>

char s[100];

const char* toUpper(const char* input) {
	int i;
	
	for (i = 0; *input!='\0'; i++) {
	   if(*input >= 'a' && s[i] <= 'z') {
       s[i] = *input - 32;     
     }
     else {
       s[i] = *input;
     } 
     input++;
  }
  return s;
}

int main() {
	const char* input = "Hello, World!";
	puts(toUpper(input)); // should print HELLO, WORLD!
}