#include "Samochody.h"

Samochody::Samochody(string id, string m, string k, string r, string p)
{
	id_samochodu = id;
	marka = m;
	kolor = k;
	rocznik = r;
	przebieg = p;
}

void Samochody::inicjalizacja(string id, string m, string k, string r, string p)
{
	id_samochodu = id;
	marka = m;
	kolor = k;
	rocznik = r;
	przebieg = p;
}

string Samochody::get_id_samochodu()
{
	return id_samochodu;
}

string Samochody::get_marka()
{
	return marka;
}

string Samochody::get_kolor()
{
	return kolor;
}

string Samochody::get_rocznik()
{
	return rocznik;
}

string Samochody::get_przebieg()
{
	return przebieg;
}

ostream & operator<<(ostream & wyjscie, const Samochody & ob)
{
	wyjscie << "Numer identyfikacyjny samochodu: " << ob.id_samochodu << endl;
	wyjscie << "Marka samochodu:	 	 " << ob.marka << endl;
	wyjscie << "Kolor samochodu:	 	 " << ob.kolor << endl;
	wyjscie << "Rocznik samochodu:	 	 " << ob.rocznik << endl;
	wyjscie << "Przebieg samochodu:		 " << ob.przebieg << " km" << endl << endl;
	return wyjscie;
}

Samochody::~Samochody()
{
}
