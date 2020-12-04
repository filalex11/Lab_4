#include <stdio.h>
#include <stdlib.h>
/*
	Ввести строку. Вывести слова, в которых каждая буква входит не менее двух раз.
	Реализовать с помощью двумерного массива.
*/
void check (char *word) {
	int i = 0, j = 0, count = 0;
	for (i = 0; word[i] != 0; i++) {
		for (j = i + 1; word[j] != 0; j++) {
			if (word[i] == word[j]) {
				count++;
			}
		}
	}
	if (count > 0) {
		for (i = 0; word[i] != 0; i++) {
			printf("%c", word[i]);
		}
		printf("%c\n", '\0');
	}
}

int is_letter (char str) {
	if (((str >= 'A') && (str <= 'Z')) || ((str >= 'a') && (str <= 'z'))) {
		return 1;
	} else {
		return 0;
	}
}

int word_count (char *string) {
	int i = 0, in_word = 0, count = 0;
	while (string[i] != 0) {
		if (is_letter(string[i]) == 1) {
			in_word = 1;
		} else {
			if (in_word == 1) {
				count++;
				in_word = 0;
			}
		}
		i++;
	}
	if (in_word == 1) {
		count++;
	}
	return count;
}

int main () {
	int a = 0, length = 0, i = 0, j = 0, k = 0;
	printf("Input length of string [1;1000]:");
	scanf("%d\n", &length);
	if ((length < 1) || (length > 1000)) {
		printf("ERROR\n");
		return -1;
	}
	char *string = malloc (length * sizeof(char));
	printf("Words:\n");
	while (((a = getchar()) != '\n') && (i < length)) {
		string[i] = a;
		i++;
	}
	int count = word_count(string);
	i = 0;
	char **words;
	words = (char**)malloc(count * sizeof(char*));
	for (i = 0; i < count; i++) {
		words[i] = (char*)malloc(length * sizeof(char));
	}
	i = 0;
	int symbols = 0;
	while (string[k] != 0) {
		if (is_letter(string[k]) == 1) {
			words[i][j] = string[k];
			j++;
			symbols = 0;
		} else {
			symbols++;
			if (symbols == 1) {
				i++;
				j = 0;
			}
		}
		k++;
	}
	i = 0;
	j = 0;
	while (i != count) {
		check(words[i]);
		free(words[i]);
		i++;
	}
	free(words);

	return 0;
}
