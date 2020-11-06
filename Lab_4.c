#include <stdio.h>
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
		printf("%c\n", '|');
	}
}

int main () {
	int a = 0, i = 0;
	printf("Input string:");
	char string[100];
	while ((a = getchar()) != '\n') {
		string[i] = a;
		i++;
	}
	i = 0;
	int start_word = 0, end_word = 0, first_word = 1;

	while (string[i] != 0) {
		if (string[i] != ' ') {
			if (first_word == 1) {
				start_word = i;
				first_word = 0;
			}
			if (string[i + 1] == 0) {
				end_word = i;
				check (string, start_word, end_word);
			}
			i++;
		} else {
			if (string[i] == ' ') {
				end_word = i - 1;
				first_word = 1;
				check (string, start_word, end_word);
				start_word = i + 1;
				i++;
			}
		}
	}		
	return 0;
}
