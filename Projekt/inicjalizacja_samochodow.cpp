#include "inicjalizacja_samochodow.h"

void wpisywanie_samochodow_do_tablicy(Samochody &wsk, string bufor)
{
	if (!bufor.empty())
	{
		string bufor_pomocniczy0, bufor_pomocniczy1, bufor_pomocniczy2, bufor_pomocniczy3, bufor_pomocniczy4;
		int licznik = 0;
		for (int i = 0; i < 50; i++)
		{
			if (bufor[i] == ',')
			{
				if (licznik == 0)
					fragmentacja_bufora(bufor, bufor_pomocniczy0, i, licznik);
				else if (licznik == 1)
					fragmentacja_bufora(bufor, bufor_pomocniczy1, i, licznik);
				else if (licznik == 2)
					fragmentacja_bufora(bufor, bufor_pomocniczy2, i, licznik);
				else if (licznik == 3)
					fragmentacja_bufora(bufor, bufor_pomocniczy3, i, licznik);
				else if (licznik == 4)
				{
					bufor_pomocniczy4 = bufor.substr(0, i);
					wsk.inicjalizacja(bufor_pomocniczy0, bufor_pomocniczy1, bufor_pomocniczy2, bufor_pomocniczy3, bufor_pomocniczy4);
					//cout << wsk; linijka s³u¿¹ca do testowania czy wszystko dobrze siê wypisuje 
					break;
				}
			}
		}
	}
}

Samochody *inicjalizacja_samochodow(string argv)
{
	fstream plik_samochodow;
	plik_samochodow.open(argv, ios::in);
	string bufor;
	int rozmiar_tablicy = wielkosc_tablicy_samochodow();
	Samochody *tablica = new Samochody[rozmiar_tablicy];
	for (int i = 0; i < rozmiar_tablicy; i++)
	{
		getline(plik_samochodow, bufor);
		wpisywanie_samochodow_do_tablicy(tablica[i], bufor);
	}
	plik_samochodow.close();
	return tablica;
}