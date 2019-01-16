/* CS 153 PROGRAM ASSIGNMENT #10

Program that converts lower case input characters
to uppercase and counts the frequency of each character.

Mark Schuberth 
 
11/27/2018 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> /* toupper() */

int main(int argc, char *argv[])
{
 /* pointer to input file */
 FILE *input, *output;
 int letter, i, file[26], count = 0;
 
 for(i = 0; i <= 26; i++)
  file[i] = 0;
 
 /* opens file for reading */
 input = fopen(argv[1], "r");
 
 /* opens output file for writing */
 output = fopen(argv[2], "w");
 
 /* check for errors like file being null */
 if(input == NULL)
 {
  /* prints error message if file is empty */
  perror(argv[1]);
  exit(EXIT_FAILURE);
 }
 
 if(output == NULL)
 {
  perror(argv[2]);
  exit(EXIT_FAILURE);
 }
 
 /* scan each individual character form input file */
 letter = fgetc(input);
 
 while(letter != EOF)
 {
  /* convert each character to uppercase */
  letter = toupper(letter);
  
  /* check if letters are between A and Z */
  if(letter >= 'A' && letter <= 'Z')
   file[letter - 'A']++;
  
  count++;
  
  letter = fgetc(input);
 }
  
 for(i = 0; i < 26; i++)
 {
  /* prints frequency of characters in input file */
  if(file[i] != 0)
  {
   fprintf(output, "%c: ", i + 'A');
   putc(' ', output);
   fprintf(output, "%f\n", ((double)file[i]/count));
  }
 }
 
 /* closes file after everything is done */
 fclose(input);
 fclose(output);
 
 return 0;
}