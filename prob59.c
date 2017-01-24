//Solves Project Euler problem 59

#include <stdio.h>
#include <sys/types.h>


int decrypt(u_char*, u_int, u_char*, u_char*, u_int*);
void print_bytes(void *p, size_t len);
void print_letters(u_int*);
void print_decrypted(u_char*, int);

int main(int argc, char* argv[]) {
	
	u_char input[10000];
	int c1, c2;

	u_char str[26] = "abcdefghijklmnopqrstuvwxyz";

	FILE* fp = fopen("cipher.txt", "r");

	int count = 0;

	for(;;) {

		if (feof(fp)) {
			break;
		}

		c1 = fgetc(fp);
		if (c1 > 47) {		
			c2 = fgetc(fp);
			if (c2 > 47) {
				input[count] = (u_char)((c1 - 48) *10 + (c2 - 48));
			}
			else {
				input[count] = (u_char)(c1 - 48);
			}
			count = count + 1;
		}
	}

	fclose(fp);
	u_char key[3];
	int i, j, l, k;
	u_char output[count];
	u_int count_letter[26];
	int counter = 0;
	//	decrypt(input, count, "god", output, count_letter);
	//print_decrypted(output, count);	

	for (i = 0; i < 26; i++) {
		for (j = 0; j < 26; j++) {
			for (l = 0; l < 26; l++) {
				key[0] = str[i];
				key[1] = str[j];
				key[2] = str[l];

				decrypt(input, count, key, output, count_letter);

				/*
				if (key[0] == 'g' && key[1] == 'o' && key[2] == 'd') {
					print_decrypted(output, count);			
				}
				*/

				if ((count / 15 < count_letter[4]) && (count / 25 < count_letter[0]) && (count / 25 < count_letter[14])) {
					printf("Key: %c%c%c\n", key[0], key[1], key[2]);
					print_decrypted(output, count);
					print_letters(count_letter);					
				}

				for (k = 0; k < 26; k++) {
					count_letter[k] = 0;
				}
			}
		}
	}

	return 0;
}

int decrypt(u_char* input, u_int length, u_char* key, u_char* output, u_int* count_letter) {

	int count;

	for (count = 0; count < length; count++) {
		output[count] = key[count % 3] ^ input[count];
		if (97 <= output[count] && output[count] <= 122) {
			count_letter[output[count] - 97]++;
		}
	}

	return 0;
}

void print_bytes(void *p, size_t len) {
    size_t i;
    printf("(");
    for (i = 0; i < len; ++i)
        printf("%02X", ((unsigned char*)p)[i]);
    printf(")");
}

void print_letters(u_int* count_letter) {
	u_char str[26] = "abcdefghijklmnopqrstuvwxyz";
	int i;

	for (i = 0; i < 26; i++) {
		printf("%c: %d\n", str[i], count_letter[i]);
	}
}

void print_decrypted(u_char* output, int count) {
	int i;
	for (i = 0; i < count; i++) {
		//if ((64 < output[i] && output[i] < 91) || (96 < output[i] && output[i] < 123)) {
			printf("%c", output[i]);
		//}
		//else {
		//	printf(".");
		//}
	}
	printf("\n");
}