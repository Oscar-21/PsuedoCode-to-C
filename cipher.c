/*
 * =====================================================================================
 *
 *       Filename:  cipher.c
 *
 *    Description:  Caeser cipher
 *
 *        Version:  1.0
 *        Created:  02/19/2017 08:24:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Austin Conder (), austin.conder@outlook.com
 *   Organization:  Mr. Solo Dolo
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Function that can be called by main() to print unencoded 
// message.
void GetMessage(char c); 

// Function that can be called by main to print
// encrypted message.
void Encode( int messageCharacter, int key );

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description: Gets user input that can be passed to Encode() and GetMessage() 
 * =====================================================================================
 */
int main ( void )

{   	 
        //create an array of size 10
        // to store the encrypted message.
	int message[10];

        // The message has a max of ten characters
        // but the user may decide to encode a
        // message with fewer than 10 characters
        // this variable keeps track of the number
        // characters in the unencoded message. 
	int size = 0;	

	// Prompt user for input
        printf ( "\n" );
	printf ( "Give me a message to encrypt:\n\n" );
        printf ( "1. use a maximum of 10 characters\n" );
        printf ( "2. only use uppercase letters.\n" );
        printf ( "3. terminate the message with the '&' character\n: " );

        // Use a for loop to get characters of message.
        // the do/while loop gets each character in the
        // message array so long as the character is an
        // uppercase letter and not the special character
        // '&'.   
	for ( int i = 0; i < 10; i += 1 ) 
	{
	
           do
	   {
              message[i] = GetChar(); // GetChar(); gets a single character
                                      // and prompts again if non character
                                      // or more than one character inputs
                                      // are given.
	      size++; // increment size to keep track of the message length.

              if ( islower(message[i]) )

	   	   printf ( "Only uppercase letters are accepted!\n: " );   
           }
           while( islower(message[i])); // islower() is a function that will return
                                        // true if its input is a lowercase letter.

	   if( message[i] == '&') // If the user inputs the '&' character, 
		   i = 10;        // we set i = 10 to close out the loop.     
	}     
	
     	printf ( "Unencrypted message\n\n: " ); // Show user their message 
                                                // to confirm proper data has
                                                // been stored.
	
	char print; // Declare a variable to store
                    // each element that we care about 
                    // in the message array.
   
	for ( int i = 0; i < (size - 1); i += 1 ) // this  loop closes out  when i = ( size - 1 )
	{                                        // because we are not interested in last element of array.      
              print = message[i];      
	      GetMessage(print); // Function called by main() that takes each member
	}                        // in message[] array and prints it to the screen.
                                 // the for loop is used because accessing mulitple elements
                                 // of an array in C requires a much greater degree of understanding about 
                                 //  the memory architechure of a computer than this coder actually has.
                                 // but, he can access elements one at a time! so, a for loop it is.
	printf ( "\n" );

        // No we prompt user for the cipher key. 
        // This will be a positive integer value.
	printf ( "What is the cipher key?\n: " );  
     
        int key; // This is our key value
                 // it is declared outside of the loop
                 // so that it has suffiecient enough
                 // scope to be used in the conditional
                 // statement of a do while loop.

        // This loop will evaluate until a positive integer
        // value is given by the user.
        do
        {
   	   key = GetInt(); // will prompt user for integer
                               // until one is given.

           if ( key <= 0) // Let user know that only positive values are accepted.
              printf (" Please give a positive integer\n: "); 
        }
        while ( key <= 0);  


	printf ( " Your encrypted message is:\n");
        
        // We use a for loop that will evaluate for the
        // members of the message array that we care about.
   	for ( int i = 0; i < (size - 1); i += 1 ) 
	{
            
	      Encode(message[i], key); // Encode is a function that will
                                       // be called by main. It will
	                               // print the encrypted characters, 
                                       // one character at a time to the screen.
        }	
	printf ("\n");

	return 0;
}				/* ----------  end of function main  ---------- */
void GetMessage(char c) // This function simply takes
                        // character values as input
                        // and prints them to the screen.
{
	printf ( "%c", c );
}

void Encode( int messageCharacter, int key ) // This function will encrypt our message. 
					    // It takes two arguments. First, the integer 
				            // value  of some element in an array that we 
					   // want to encrypt, and second, the key value
				           // that we will use to encrypt the character.
{   
   // first we create an array
   // that stores the ASCII values
   // of all of the capital letters	
   char capital[26];
  
   for ( int i = 0; i < 26; i++)
{
	capital[i] = ('A' + i);
}
 
   // now we create a one element array
   // to store the encrypted character
   int encrypt[1];

   // we use a nested for loop
   // to check the value of the 
   // function input messageCaracter
   // against every value in the capital[] array 
   for (int i = 0; i < 1 ; i++) 
   {
      for (int j = 0; j < 26; j++)
         if ( messageCharacter == capital[j] ) // if function input matches
                                               // a value from the capital[] array
                                               // we encrypt the message.

      encrypt[i] = capital[((( j + key )%26))]; // Since we mapped the 26 capital letters
   }                                            // in an array of 26 elements, we can use
                                                // the caeser cipher formula which is
                                                // ((unencoded characters index in alphabet) + (k movements)) % 26   
                                                // and use it to store the encrypted character in encrypt[] array 
   // now we just simply print the
   // new character value to the screen.
   // again we use the for loop
   // because I don't understand 
   // all that memory and pointer stuff in C.    
   for ( int i = 0; i < 1; i++)
   {
      printf ("%c", (char)encrypt[i]);
   }	
}

