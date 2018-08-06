#ifndef PALAVRA_H_
#define PALAVRA_H_

#include <iostream>
#include <string>

using namespace std;

class Palavra {

public:
	Palavra(string palavra = "") : word(palavra) {ocorrencias = 0;};
	bool operator== (const Palavra &);
	int compara(Palavra &);
	string getWord() const;
	void setWord(const string&);
	friend ostream & operator << (ostream &out, const Palavra &);
	int getOcorrencias() const;
	void incrementarOcorrencias();

private:
	string word;
	int ocorrencias;
};

#endif
