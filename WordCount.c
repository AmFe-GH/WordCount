#include<stdio.h>
#include<string.h>

void wordCnt(FILE *fp);
void charCnt(FILE *fp);

int main(int argc, char *argv[]){
	FILE *fp;
	fp = fopen(argv[2], "r"); //open file
	
	if(strcmp(argv[1], "-c") == 0){
		//printf("count c\n");
		charCnt(fp);
	}else if(strcmp(argv[1], "-w") == 0){
		//printf("count w\n");
		wordCnt(fp);
	}else{
		printf("Wrong mod!");
	}
	
	fclose(fp);
	return 0;
}

void wordCnt(FILE *fp){
	int ch;
	int words = 1;
	while((ch = fgetc(fp)) != EOF){
		//printf("%c", ch);
		if(ch == ',' || ch == ' '){
			words++;
		}
	}
	printf("\ntotal words: %d", words);
}

void charCnt(FILE *fp){
	int ch;
	int chars = 0;
	while((ch = fgetc(fp)) != EOF){
		chars++;
		printf("%c", ch);
	}
	printf("\ntotal chars: %d", chars);
}