#include <stdio.h>
#include <stdlib.h>
/*
	Ввести строку. Вывести слова, в которых каждая буква входит не менее двух раз.
*/
void check (char* string, int start_word, int end_word) {
	int i = 0, j = 0, count = 0;
	for (i = start_word; i < end_word; i++) {
		for (j = i + 1; j <= end_word; j++) {
			if (string[i] == string[j]) {
				count++;
			}
		}
	}
	if (count > 0) {
		for (i = start_word; i <= end_word; i++) {
			printf("%c", string[i]);
		}
		printf("%c\n", '\0');
	}
}

char is_symbol (char* string, int i) {
	char symbols[17] = {' ', ',', '.', ':', ';', '-', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int j = 0, count = 0;
	for (j = 0; j < 17; j++) {
		if (symbols[j] == string[i]) {
			count++;
		}
	}
	if (count != 0) {
		return 'Y';
	} else {
		return 'N';
	}
}

int main () {
	int a = 0, i = 0, length = 0;
	printf("Input length of string:");
	scanf("%d\n", &length);
	char* string = malloc (length * sizeof(char));
	printf("Words:\n");
	while ((a = getchar()) != '\n') {
		string[i] = a;
		i++;
	}
	i = 0;
	int start_word = 0, end_word = 0;
	char first_word = 'Y';
	while (string[i] != 0) {
		if (is_symbol(string, i) == 'N') {	
			
			if (first_word == 'Y') {
				start_word = i;
				first_word = 'N';
			}
			if (string[i + 1] == 0) {
				end_word = i;
				check (string, start_word, end_word);
			}
			i++;
		} else {
			if (is_symbol(string, i) == 'Y') {
				end_word = i - 1;
				first_word = 'Y';
				check (string, start_word, end_word);
				start_word = i + 1;
				i++;
			}
		}
	}		
	return 0;
}
