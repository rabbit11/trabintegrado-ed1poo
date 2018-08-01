#ifndef PALAVRA_H_
#define PALAVRA_H_

#include <iostream>
#include <string>

using namespace std;

class Palavra {

public:
	Palavra(string palavra = "") : word(palavra) {};
	bool operator== (Palavra &op2);

private:
	string word;
};

#endif