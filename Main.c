#include <reg51.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void main()
{
  char input[30]; // input string
  char *word_begin = input; //pointer to keep track of beginning of a word
  char *temp = input, *end; //
  char t; 
  char *next;		// to keep track of next character in the string
  int n,i,j,k=0,p;	// loop counter variables
  

  SCON = 0x52; 
  TMOD = 0x20;
  TCON = 0x40;
  TH1 = 0xf3; 
  
  //printf("Enter String: ");
  gets (input, sizeof(input));	// reading input string
  printf("%s\n", input);		// print the entered string
  
  n=strlen(input);    // finding length of string

  // Reversing the words in a String
  for(i = n; i >= 0; i--)     // outer loop starting from end of the string
    {
	   k++;
       if(input[i-1] == ' ' || i == 0)	// checking for a whitespace or start of string
       {
	       for( j = i, p = 1; p <= k ; j++, p++)
           {
               printf("%c",input[j]);	// Printing character in a word
           }
		   k=0;
	    }
		
    }
 
  // Alphabetical sorting of the String
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

  *temp = '\n';
	
  printf("\n%s",input); // Printing the sorted string
}

