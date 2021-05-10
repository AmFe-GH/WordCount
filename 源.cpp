#include<stdio.h>
#include<string.h>

void wordCount(FILE* fp);
void charCount(FILE* fp);
int main(int argc, char* argv[]) {
	FILE* fp;
	fp = fopen(argv[2], "r"); 

	if (strcmp(argv[1], "-c") == 0) {
		charCount(fp);
	}
	else if (strcmp(argv[1], "-w") == 0) {
		wordCount(fp);
	}
	else {
		printf("Wrong mod!");
	}
	fclose(fp);
	return 0;
}
void wordCount(FILE* fp) {
	int term;
	int words = 0;
	int k = 0;
	while ((term = fgetc(fp))&&term != EOF) {
		//printf("%c", ch);

		if (term == ',' || term == ' ') 
		{
			if (k == 1)
			{
				words++; k = 0;
			}
		}
		else if (term <= 'Z' && term >= 'A' || term <= 'z' && term >= 'a')
			k = 1;
	}
	printf("\nµ¥´ÊÊý: %d", words);
}
void charCount(FILE* fp) {
	int ch;
	int chars = 0;
	while ((ch = fgetc(fp)) &&ch!= EOF) {
		chars++;
	}
	printf("\n×Ö·ûÊý: %d", chars);
}