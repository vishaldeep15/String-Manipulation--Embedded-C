#include <reg51.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char input[]);
void alphabetic_sort(char *input);

void main()
{
  
  char input[30]; // input string
  
  SCON = 0x52; 
  TMOD = 0x20;
  TCON = 0x40;
  TH1 = 0xf3; 
  
  puts("Enter a String: ");
  gets (input, sizeof(input));	// reading input string
  puts(input);		// print the entered string

  reverse(input);  // Reversing the words in a String
  alphabetic_sort(input);  // Alphabetical sorting of the String
}  
 

void reverse(char input[]) {
	int n,i,j,k=0,p;	// loop counter variables

	n=strlen(input);    // finding length of string

    // Reversing the words in a String
    for(i = n; i >= 0; i--)     // outer loop starting from end of the string
    {
	   k++;
       if(input[i-1] == ' ' || i == 0)	// checking for a whitespace or start of string
       {
	       for( j = i, p = 1; p <= k ; j++, p++)
           {
               putchar(input[j]);	// Printing character in a word
           }
		   k=0;
	   }  
	}
}

void alphabetic_sort(char *input) {
// Alphabetical sorting of the String
  char *temp = input,*end; 
  char *word_begin = input; //pointer to keep track of beginning of a word
  char t; 
  char *next;		// to keep track of next character in the string
  
  while( *temp )   
  {
    temp++;

    if (*temp == '\0' || *temp == ' ')   // checking if a whitespace or end of string occured
    {         
	    end = temp - 1;		// variable to keep track of end of word

		while(word_begin <= end) // word_begin holds current character
		{
		   next = word_begin + 1;	//"next" keep track of next character  
 
		   while(next <= end)
		    {
		       if(tolower(*word_begin) > tolower(*next)) 
			   // Checking if the ASCII value of current character is greater than 
			   // the ASCII value of next character
			   {
		            t = *word_begin;
		            *word_begin = *next;   // swaping the values
					*next = t; 
				}
		       next++;
		    }					
		   word_begin++;
		}   	  
	  	word_begin = temp+1;	  	
    }	
  }

  puts("");	
  puts(input); // Printing the sorted string
}
