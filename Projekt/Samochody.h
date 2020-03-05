#pragma once
#include <iostream>
#include <string>
using namespace std;

class Samochody
{
	string marka, kolor, rocznik, przebieg;
protected:
	string id_samochodu;
public:
	Samochody(string = "brak", string = "brak", string = "brak", string = "brak", string = "brak");
	void inicjalizacja(string, string, string, string, string); 
	friend ostream & operator<<(ostream &wyjscie, const Samochody &ob);
	string get_id_samochodu();
	string get_marka();
	string get_kolor();
	string get_rocznik();
	string get_przebieg();
	~Samochody();
};