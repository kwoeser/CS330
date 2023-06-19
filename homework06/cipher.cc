#include "cipher.h"

/* Cheshire smile implementation.
   It only contains the cipher alphabet
*/

using namespace std;

struct Cipher::CipherCheshire {
    	
	// Changed to cipherText because cipher_alpha is used again
	string cipherText;
};

/* This function checks the cipher alphabet
   to make sure it's valid
*/
bool is_valid_alpha(string alpha);


// -------------------------------------------------------
// Cipher implementation
/* Default constructor
   This will actually not encrypt the input text
   because it's using the unscrambled alphabet
 */
Cipher::Cipher()
{
    // TODO: Implement this default constructor 
    
    smile = new CipherCheshire;
    smile->cipherText = "abcdefghijklmnopqrstuvwxyz";
     	  	      // abcdefghijklmnopqrstuvwxyz

}


/* This constructor initiates the object with a
   input cipher key
 */
Cipher::Cipher(string cipher_alpha)
{
    // TODO: Implement this constructor
       
    if (is_valid_alpha(cipher_alpha)) { 
 	   smile = new CipherCheshire;
   	   smile->cipherText = cipher_alpha;
    } else {
	    cerr << "Invalid cipher alphabet/key: " << cipher_alpha << endl;
	    exit(EXIT_FAILURE);
    }

}


/* Destructor
 */
Cipher::~Cipher()
{
    // TODO: Implement this constructor
    
    // Deletes destructor from the cipher
    delete smile;    

}

/* This member function encrypts the input text 
   using the intialized cipher key
 */
string Cipher::encrypt(string raw)
{
    cout << "Encrypting...";
    string retStr;
    // TODO: Finish this function    
   

    for (unsigned int i = 0 ; i < raw.size(); i++) {
	unsigned int pos;

	// Spaces
	if (raw[i] == ' ') {
		retStr += ' ';
	}

	// lowercase cases
	else if (islower(raw[i])) {
		pos = raw[i] - 97;	
		retStr += smile->cipherText[pos];
	} 

	// Upper case case
	else {
		pos = raw[i] - 65;
		retStr += UPPER_CASE(smile->cipherText[pos]);
	}


    }
	     
    cout << "Done: " << retStr << endl;
   
    return retStr;

}


/* This member function decrypts the input text 
   using the intialized cipher key
*/
string Cipher::decrypt(string enc)
{
    string retStr;
    cout << "Decrypting...";
    // TODO: Finish this function
    
    for (unsigned int i = 0; i < enc.length(); i++) {
    	    
	   // Checks for spaces
	   if (enc[i] == ' ' ) {
		retStr += ' ';
	
	   // Handles uppercase letters
	   } else if (isupper(enc[i]) != 0) {
		   
		   unsigned int idx = find_pos(smile->cipherText, LOWER_CASE(enc[i]));
		   
		   if (idx != string::npos) {
   		   	retStr += idx + 65;

		   } else {
	           	retStr += enc[i];
		   }

	   // Handles lowercase letters
	   } else if (islower(enc[i]) != 0) {
		  
		   unsigned int idx = find_pos(smile->cipherText, enc[i]);
		   
		   if (idx != string::npos) {
		   	retStr += idx + 97;
		   } else {
			retStr += enc[i];
	           }  
		 

	   } else {
		retStr += enc[i];
	   }
	
    }
	  
    cout << "Done " << retStr << endl;
    
    return retStr;

}
// -------------------------------------------------------


//  Helper functions 
/* Find the character c's position in the cipher alphabet/key
 */

unsigned int find_pos(string alpha, char c)
{
   
    // TODO: You will likely need this function. Finish it.
 
    unsigned int pos = 0;
    
 
    bool found = false;
    unsigned int index = 0;  
   
    while ((!found) && (index < alpha.size())) {
	if (alpha[index] == c) {
		found = true;
		pos = index;
	} else {
		index++;
	}
    } 
	
    return pos;
	
    /*pos = alpha.find(c);
    return pos;*/
    
}



/* Make sure the cipher alphabet is valid - 
   a) it must contain every letter in the alphabet 
   b) it must contain only one of each letter 
   c) it must be all lower case letters 
   ALL of the above conditions must be met for the text to be a valid
   cipher alphabet.
 */
bool is_valid_alpha(string alpha)
{
    bool is_valid = true;

    if(alpha.size() != ALPHABET_SIZE) {
        is_valid = false; 
    } else {
        
	unsigned int letter_exists[ALPHABET_SIZE];
        for(unsigned int i = 0; i < ALPHABET_SIZE; i++) {
            letter_exists[i] = 0;
        }
        
	for(unsigned int i = 0; i < alpha.size(); i++) {
            char c = alpha[i];
            if(!((c >= 'a') && (c <= 'z'))) {
                is_valid = false;
            } else {
                letter_exists[(c - 'a')]++;
            }
        }
        
	for(unsigned int i = 0; i < ALPHABET_SIZE; i++) {
            if(letter_exists[i] != 1) {
                is_valid = false;
            }
        }
    }

    return is_valid;
}
