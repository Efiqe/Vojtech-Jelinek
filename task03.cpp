	// else if (strcmp(argv[1], "-v") == 0) {
		// int verbose;
		// int argument = 3;
		// fileSum(argv, argument, 1);	
	// }
	// else if (strcmp(argv[3], "-v") == 0) {
		// int verbose;
		// int argument = 2;
		// fileSum(argv, argument, 1);	
	// }
	
	// size_t last_el = sizeof(argv)/sizeof(argv[0])
	
	
	// int i;
	// int sum = 0;
	// printf("argc %d\n", argc);
	
	// for (i = 0; i < argc; i++) {
		// printf("argv[%d] = %s\n", i, argv[i]);
		// sum += atoi(argv[i]);
	// }
	// printf("Sum = %d\n", sum);
	
	// return 0;
	
	// if (strcmp(argv[1], "-f") != 0 && strcmp(argv[1], "-i") != 0) {
		// for (i = 0; i < argc; i++) {
			// sum += atoi(argv[i]);
		// }
	// printf("%d", sum);
	// }

/*
  Write a "task03" program for basic adding. It should handle -f, -i and -v parameters

  ++task03 -f data.txt // outputs sum of numbers in data.txt
  ++task03 -i // interactive mode: sums numbers from standard input until empty input provided
  ++task03 4 7 12 // outputs sum of any number of arguments (23 in this case)
  implement verbose mode -v, which outputs additional info about arguments, i.e.
    ++task03 -f data.txt -v // should print "sum of numbers in data.txt is 13"
    ++task03 -v -f data.txt // same result
	task03 -v -i // should print like "sum of 7 numbers from standard input is 38"
    task03 2 2 13 6 -v // should print "sum of 4 arguments is 23"
    task03 -v 13 4 // should print "sum of 2 arguments is 17"
*/

#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <stdbool.h>

void fileSum (char* argv[], int argument, int verbose) {
	char text[200];
	int i;
	int sum = 0;
	FILE *fp;
	fp = fopen(argv[argument], "rb");
	
	if (verbose == 0) {		
		while (true) {
			if (fscanf(fp, "%s", text) == EOF) {
				break;
			}
			sscanf(text, "%d", &i);
			sum += i;	
		}
		printf("%d", sum);
	}
	
	else {
		while (true) {
			if (fscanf(fp, "%s", text) == EOF) {
				break;
			}
			sscanf(text, "%d", &i);
			sum += i;	
		}
		printf("Sum of numbers is: %d", sum);	
	}	
}

void interactiveSum () {
	char text[200];
	int i;
	int sum = 0;
	while (true) {
		fgets(text, 200, stdin);
		if (strlen(text) == 1) {
			break;
		}
		sscanf(text, "%d", &i);
		sum += i;	
	}	
	printf("%d",sum);
}

int main(int argc, char* argv[]) {
	if (argc > 3) {	
		if (strcmp(argv[1], "-f") == 0 && strcmp(argv[3], "-v") == 0) {
			int verbose;
			int argument = 2;
			fileSum(argv, argument, 1);
		}
		if (strcmp(argv[1], "-v") == 0) {
			int verbose;
			int argument = 3;
			fileSum(argv, argument, 1);
		}
	}
	else if (strcmp(argv[1], "-f") == 0) {
		int verbose;
		int argument = 2;
		fileSum(argv, argument, 0);
	}
	
	if (strcmp(argv[1], "-f") != 0 && strcmp(argv[1], "-i") != 0 && strcmp(argv[1], "-v") != 0) {
		int i;
		int sum = 0;
		for (i = 0; i < argc; i++) {
			sum += atoi(argv[i]);
		}
		printf("%d", sum);	
	}
	
	if (strcmp(argv[1], "-i") == 0) {
		interactiveSum();
	}
}






