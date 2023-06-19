#include <string>
#include <iostream>
#include <algorithm>
#include "ccipher.h"


// -------------------------------------------------------
// Caesar Cipher implementation

using namespace std;

struct Cipher::CipherCheshire {
	string cipherText;
};

struct CCipher::CCipherCheshire {
	// Rotation
	unsigned int rot;
};


// Constructor
CCipher::CCipher() : Cipher() {
	CaesarSmile = new CCipherCheshire;
	CaesarSmile->rot = 0;
}

CCipher::CCipher(int rot) : Cipher() {
	CaesarSmile = new CCipherCheshire;
	CaesarSmile->rot = rot;	

	if (rot < 0) {
		cerr << "Error: Caesar cipher is less then 0" << endl;
		exit(EXIT_FAILURE);
	}
	unsigned int rots = rot % 26;
	rotate_string(smile->cipherText, rots);

}


// Destructor
CCipher::~CCipher() {
	delete CaesarSmile;
}


string CCipher::encrypt(string raw) {

	return Cipher::encrypt(raw);
}

string CCipher::decrypt(string enc) {
		
	return Cipher::decrypt(enc);


}
	


// ---------------------------------------------------------

// Rotates the input string in_str by rot positions
void rotate_string(string& in_str, int rot)
{
    // TODO: You will likely need this function. Implement it.


	reverse(in_str.begin(), in_str.begin() + rot);
	reverse(in_str.begin() + rot, in_str.end());
	reverse(in_str.begin(), in_str.end());
    	
}

