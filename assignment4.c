#include <stdio.h> //printf
#include <stdlib.h> //dynamic memory allocations, EXIT_SUCCESS/FAILURE
#include <string.h> //strcat, strcopy, strlen, strtok

#define MAX_CHAR 200 //max chars per line
#define MAX_LINE 10000 //max # lines for text
#define MAX_CHAR_FOR_SENTENCE 1000
//struct of instructions
struct instruction_s{
	int step;
	int index;
};
/* edit sentence gets the sentence and returns the edited output
 * remove punctuations, all letters -> lowercase
 */
void edit_sentence(char * sentence)
{
	int i = 0; //edited output wont be longer than before
	char * edited_sentence = malloc(strlen(sentence));
	//copy sentence char by char to edited output sentence
	for (int k = 0; k < strlen(sentence); k++) //fill all chars with '\0' to be safe
		edited_sentence[k] = '\0';
	while ((i < strlen(sentence)) && sentence[i] != '\0')
	{	//it will edit the sentence but spaces are allowed as i fill them before.
		if ((sentence[i] < 97 || sentence[i] > 122) && sentence[i] != ' ') { //chars that are not lowercase letters
			if (sentence[i] >= 65 && sentence[i] <= 90) {
				sentence[i] = sentence[i] + 32; //chars that are uppercase letters and can be lowercase format
				strncat(edited_sentence, sentence + i, 1);
			}
			else
				;
		}
		else
			strncat(edited_sentence, sentence + i, 1);
		i++;
	}
	edited_sentence[i] = '\0'; //put '\0' at the end to be safe
	printf("\n%s\n", edited_sentence); //print the output
	free(edited_sentence); //free the edited output
}
/* get word function takes the nth line and the index it has
 * get word function returns the selected word.
 */
char * get_word(char *line, int index) {
	char *token;
	int count = 0; //divide sentence to tokens respect to " "
	token = strtok(line, " ");
	while (token != NULL) {
		if (count == index - 1) //substract 1 because of the word-whitespace relation
			break;
		token = strtok(NULL, " ");
		count++;//get next token
	}
	return token;
}
/* get sentence function takes the array of lines, array of struct instructions, number of instructions, the empty sentence.
 * get word function is called in get sentence function.
 */
void get_sentence(char **lines, struct instruction_s *instructions, int n_instructions, char * sentence)
{//at point A, i fix the 0 based to 1 based, it effects all the step chains ofc. at point B, i fix subsequent steps relation
	for (int k = 0; k < n_instructions; k++)
	{
		if (k == 0) {
			instructions[k].step = instructions[k].step - 1; //point A
			strcat(sentence, get_word(lines[instructions[k].step], instructions[k].index));
			strcat(sentence, " "); //i add " " after all the words
		}
		else {
			instructions[k].step = instructions[k].step + instructions[k-1].step; //point B
			strcat(sentence, get_word(lines[instructions[k].step], instructions[k].index));
			if (k != n_instructions-1) //last word wont be added with " "
				strcat(sentence, " ");
		}
	}//i use strcat to add the words to the empty sentence
}
int main(int argc, char * argv[])
{
	FILE *text_f; //declare files
	FILE *inst_f;
	int number_of_lines_i = 0; //i stands for instructions
	int number_of_lines_t = 0; //t stands for text
	int n = 0, k = 0, c = 0, p = 0;
	//check if they can be open
	if ((text_f = fopen(argv[1], "r")) == NULL || (inst_f = fopen(argv[2], "r")) == NULL)
	{
		printf("Cannot open.\n"); //there wasnt any 
		return EXIT_FAILURE;
	}
	else {
	//store the book in array of strings
		char **linesOfBook;
		linesOfBook = malloc(number_of_lines_t * sizeof(char *));
		char buf[MAX_CHAR]; //read the line from file to buf
		for (number_of_lines_t = 0; fgets(buf, MAX_CHAR, text_f) != NULL; number_of_lines_t++) {
			linesOfBook = realloc(linesOfBook, (number_of_lines_t + 1) * sizeof(char *)); //hope there is no mistake :/(
			linesOfBook[number_of_lines_t] = malloc(MAX_CHAR * sizeof(char));
			k = strlen(buf);
			if ((k <= 0 || buf[k-1] != '\n') && c != 0) //c stands for checking the last line.(there wont be '\n' at the end of the last line.)
				return fprintf(stderr, "%s", "Error occured.\n");
			if (number_of_lines_t >= MAX_LINE)
				return fprintf(stderr, "%s", "Error occured.\n");
			strcpy(linesOfBook[number_of_lines_t], buf);
			c++;
		}
		fclose(text_f); //close the text file.
		//instruction text file operations
		struct instruction_s *instStr = malloc((number_of_lines_i) * sizeof(struct instruction_s));
		char buffer[MAX_CHAR];
		for(number_of_lines_i = 0; fgets(buffer, MAX_CHAR, inst_f) != NULL; number_of_lines_i++) {
			instStr = realloc(instStr, (number_of_lines_i+1) * sizeof(struct instruction_s));
			n = strlen(buffer);
			if ((n <= 0 || buffer[n-1] != '\n') && p != 0)//in given texts there is an empty line but i couldnt be sure and thats why im checking
				return fprintf(stderr, "%s", "Error occured.\n");
			if (number_of_lines_i >= MAX_LINE)
				return fprintf(stderr, "%s", "Error occured.\n");
			sscanf(buffer, "%d %d",
					&instStr[number_of_lines_i].step, &instStr[number_of_lines_i].index); //read 2 integers from buffer to struct's step and index
			p++;
		}
		fclose(inst_f); //close the instructions file
		char sentence[MAX_CHAR_FOR_SENTENCE] = ""; //sentence with full of '\0'
		get_sentence(linesOfBook, instStr, number_of_lines_i, sentence); //get sentence function
		edit_sentence(sentence); //edit sentence function
		
		free(instStr); //free the struct *
		free(linesOfBook); //free the array of lines
	}
	return EXIT_SUCCESS;
}