#include <cstdio>
#include <string.h>



const char* toUpper(const char* input) {
	int i;
	char s[100];
	
	for (i = 0; *input!='\0'; i++) {
			if(*input >= 'a' && s[i] <= 'z') {
				s[i] = *input - 32;     
			}
			else {
				s[i] = *input;
			} 
			input++;
		}
		return 0;	
	}	  
  

int main() {
	const char* input = "Hello, World!";
	puts(toUpper(input)); // should print HELLO, WORLD!
	return 0;
}
	