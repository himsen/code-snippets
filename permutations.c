// All permutations of a string (with repetitions)

#include <sys/types.h>
#include <stdio.h>
#include <string.h>

void swap(char*, u_int, u_int);

int main(int argc, char* argv[]) {

	char* string = (char*) argv[1];
	u_int length = (u_int) atoi(argv[2]);

	int counter;
	
	printf("string: ");
	for (counter = 0; counter < length; counter++) {
		printf("%c", string[counter]);	
	}
	printf("\n");
	
	printf("length: %d\n", length);

	swap(string, length, 0);

	return 0;
}

void swap(char* string, u_int length, u_int i) {

	char temp;
	char tempstring[length + 1];
	int counter;

	tempstring[length] = '\0';

	if (i == length - 1) {
		printf("%s\n", string);
	}
	else{
		temp = string[i];
		for (counter = i; counter < length; counter++) {
			memcpy(tempstring, string, length);
			tempstring[i] = string[counter];
			tempstring[counter] = temp;
			swap(tempstring, length, i+1);
		}
	}
}