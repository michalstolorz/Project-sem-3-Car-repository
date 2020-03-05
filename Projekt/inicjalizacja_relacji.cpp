#include "inicjalizacja_relacji.h"

void wpisywanie_relacji_do_tablicy(Relacje &wsk, string bufor)
{
	if (!bufor.empty())
	{
		string bufor_pomocniczy0, bufor_pomocniczy1;
		bufor_pomocniczy0 = bufor.substr(0, 11);
		bufor_pomocniczy1 = bufor.substr(12, 1);
		wsk.inicjalizacja(bufor_pomocniczy0, bufor_pomocniczy1);
		//cout << wsk; linijka s³u¿¹ca do testowania czy wszystko dobrze siê wypisuje 
	}
}

Relacje *inicjalizacja_relacji(string argv)
{
	fstream plik_relacje;
	plik_relacje.open(argv, ios::in);
	string bufor;
	int rozmiar_tablicy = wielkosc_tablicy_relacji();
	Relacje *tablica = new Relacje[rozmiar_tablicy];
	for (int i = 0; i < rozmiar_tablicy; i++)
	{
		getline(plik_relacje, bufor);
		wpisywanie_relacji_do_tablicy(tablica[i], bufor);
	}
	plik_relacje.close();
	return tablica;
}