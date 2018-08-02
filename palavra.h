#ifndef PALAVRA_H_
#define PALAVRA_H_

#include <iostream>
#include <string>

using namespace std;

class Palavra {

public:
	Palavra(string palavra = "") : word(palavra) {};
	bool operator== (Palavra &);
	int compara(Palavra &);
	string getWord();
	void setWord(string &);

private:
	string word;
};

#endif
