#pragma once
#include <iostream>
#include <string>
#include "Samochody.h"
#include "Wlasciciele.h"
using namespace std;

class Relacje : public Samochody, public Wlasciciele
{
public:
	Relacje(string = "brak", string = "brak");
	void inicjalizacja(string, string);
	string get_id_samochodu();
	string get_PESEL();
	friend ostream & operator<<(ostream &wyjscie, const Relacje &ob);
	~Relacje();
};

