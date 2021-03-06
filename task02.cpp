
/*
Decode the task02.dat file and find out the birth dates of John Doe and Sam Sepiol.

format: N records of 6 bytes:
  byte 1-2: birth date yyyyyyyd ddddmmmm (year of birth LSB - 1900)
  byte 3-6: height (float LSB)

separator 0xFF (after N records)
name1|name2|...|nameN|
*/

#define byte unsigned char
#define h_bytes unsigned int
#include <cstdio>
#include <cstring>

byte flipbits(byte number) {
	byte result = 0;
	for (int i = 0; i < 7; i++) {
		bool each_bit = number & (0b1 << i);
		result |= each_bit << (6 - i); 
	}
	return result;
}

float toFloat (h_bytes raw_height) {
	float result;
	memcpy(&result, &raw_height, sizeof(raw_height));
	return result;
}

h_bytes findHeight(byte first_buffer, byte second_buffer, byte third_buffer, byte fourth_buffer) {
	h_bytes fourth = fourth_buffer << 24; //8*3
	h_bytes third = third_buffer << 16;  //8*2	
	h_bytes second = second_buffer << 8;  //8*1
	h_bytes first = first_buffer;		   //8*0
	h_bytes height = fourth | third | second | first;
	return height;	
}

int main() {
	FILE *fp;
	byte buffer[20];
	
	fp = fopen("task02.dat", "rb");
	fread(buffer, sizeof(buffer), 1, fp);
	
	int year = flipbits(buffer[0] >> 1) + 1900;
	int month = buffer[1] & 0b1111;
	int day = ((buffer[0] & 0b1) << 4) | (buffer[1] >> 4); 
	
	//buffer 2,3,4,5 = vyska Johna
	
	h_bytes temp_height = findHeight(buffer[2], buffer[3], buffer[4], buffer[5]);  
	
	printf("day: %d\n", day);
	printf("month: %d\n", month);
	printf("year: %d\n", year);
	printf("height: %f", toFloat(temp_height));
}




