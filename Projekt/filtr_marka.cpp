#include "filtr_marka.h"

filtr_marka::filtr_marka()
{
}

void filtr_marka::filtrowanie(Wlasciciele *wlasciciel, Samochody *samochod, Relacje *relacja, string nazwa_pliku)
{
	string marka;
	cout << "Po jakiej marce samochodu szukac wlascicieli: " << endl;
	cin >> marka;
	toupper(marka[0]);
	int licznik_szukanych_samochodow = 0, ile_samochodow = wielkosc_tablicy_samochodow();
	for (int i = 0; i < ile_samochodow; i++)
	{
		if (marka == samochod[i].get_marka())
			licznik_szukanych_samochodow++;
	}
	string *tablica_id_samochodow = new string[licznik_szukanych_samochodow]; 
	licznik_szukanych_samochodow = 0;
	for (int i = 0; i < ile_samochodow; i++)
	{
		if (marka == samochod[i].get_marka())
		{
			tablica_id_samochodow[licznik_szukanych_samochodow] = samochod[i].get_id_samochodu();
			licznik_szukanych_samochodow++;
		}
	}
	int licznik_pomocniczy_do_tablicy = 0, licznik_szukanych_wlascicieli = 0, ile_relacji = wielkosc_tablicy_relacji();
	for (int j = 0; j < licznik_szukanych_samochodow; j++)
	{
		for (int i = 0; i < ile_relacji; i++)
		{
			if (tablica_id_samochodow[licznik_pomocniczy_do_tablicy] == relacja[i].get_id_samochodu())
			{
				licznik_szukanych_wlascicieli++;
			}
		}
		licznik_pomocniczy_do_tablicy++;
	}
	string *tablica_PESEL_wlascicieli = new string[licznik_szukanych_wlascicieli]; 
	int licznik_szukanych_PESEL = 0, licznik_znalezionych_PESEL=0;
	for (int j = 0; j < licznik_szukanych_wlascicieli; j++)
	{
		for (int i = 0; i < ile_relacji; i++)
		{
			if (relacja[i].get_id_samochodu() == tablica_id_samochodow[licznik_szukanych_PESEL])
			{
				tablica_PESEL_wlascicieli[licznik_znalezionych_PESEL] = relacja[i].get_PESEL();
				licznik_znalezionych_PESEL++;
			}
		}
		licznik_szukanych_PESEL++;
	}
	int ile_wlascicieli = wielkosc_tablicy_wlascicieli();
	string *tablica_PESEL_wlascicieli_kopia = new string[licznik_szukanych_wlascicieli];
	for (int i = 0; i < licznik_szukanych_wlascicieli; i++)
		tablica_PESEL_wlascicieli_kopia[i] = tablica_PESEL_wlascicieli[i];
	int licznik_powtorzen = 0;
	for (int i = 0; i < licznik_szukanych_wlascicieli; i++)
	{
		for (int j = 0; j < licznik_szukanych_wlascicieli; j++)
		{ 
			if (tablica_PESEL_wlascicieli[j] == tablica_PESEL_wlascicieli_kopia[i])
			{
				if (licznik_powtorzen == 0)
					licznik_powtorzen++;
				else if (licznik_powtorzen != 0)
					tablica_PESEL_wlascicieli[i] = "brak";
			}
		}
		licznik_powtorzen = 0;
	}
	fstream plik_wyjsciowy;
	plik_wyjsciowy.open(nazwa_pliku, ios::out);
	for (int i = 0; i < licznik_znalezionych_PESEL; i++) 
	{
		for (int j = 0; j < ile_wlascicieli; j++)
		{
			if (wlasciciel[j].get_PESEL() == tablica_PESEL_wlascicieli[i])
				plik_wyjsciowy << wlasciciel[j].get_imie()<<" "<<wlasciciel[j].get_nazwisko()<<endl;
		}
	}
	plik_wyjsciowy.close();
	delete[]tablica_id_samochodow;
	delete[]tablica_PESEL_wlascicieli;
	delete[]tablica_PESEL_wlascicieli_kopia;
}

filtr_marka::~filtr_marka()
{
}
