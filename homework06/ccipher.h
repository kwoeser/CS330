#ifndef CCIPHER_H_
#define CCIPHER_H_
#include "cipher.h"

using namespace std;

/* A class that implements a
   Caesar cipher class. It 
   inherits the Cipher class */
// TODO: Implement this class


class CCipher : public Cipher {
	public: 
		CCipher();
		CCipher(int rot);
		~CCipher();	


		string encrypt(string raw);
		string decrypt(string enc);

	private:
		struct CCipherCheshire;
		CCipherCheshire* CaesarSmile;

		//virtual encrypt(string raw);
		//virtual decrypt(string enc);		
};


/* Helper function headers 
 */
void rotate_string(string& in_str, int rot);
#endif

