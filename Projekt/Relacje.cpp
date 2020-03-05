#include "Relacje.h"

Relacje::Relacje(string P, string id)
{
	Wlasciciele::PESEL = P;
	Samochody::id_samochodu = id;
}

void Relacje::inicjalizacja(string P, string id)
{
	Wlasciciele::PESEL = P;
	Samochody::id_samochodu = id;
}

string Relacje::get_id_samochodu()
{
	return Samochody::id_samochodu;
}

string Relacje::get_PESEL()
{
	return Wlasciciele::PESEL;
}

ostream & operator<<(ostream & wyjscie, const Relacje & ob)
{
	wyjscie << ob.PESEL << endl;
	wyjscie << ob.id_samochodu << endl;
	return wyjscie;
}

Relacje::~Relacje()
{
}
