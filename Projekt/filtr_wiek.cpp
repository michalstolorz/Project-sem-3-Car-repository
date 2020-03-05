#include "filtr_wiek.h"

filtr_wiek::filtr_wiek()
{
}

void filtr_wiek::filtrowanie(Wlasciciele *wlasciciel, Samochody *samochod, Relacje *relacja, string nazwa_pliku_wyjsciowego)
{
	const int dozwolony_wiek = 18;
	time_t czas = time(0);
	struct tm * timeinfo;
	timeinfo = localtime(&czas);
	int rok = 1900 + timeinfo->tm_year, miesiac = 1 + timeinfo->tm_mon, dzien = timeinfo->tm_mday, wiek;
	cout << "Ponizej ilu lat szukac osob posiadajacych samochod: " << endl;
	cin >> wiek;
	int licznik_znalezionych_dat = 0;
	if (wiek < dozwolony_wiek)
		cout<<"Osoby ponizej 18 lat nie moga prowadzic samochodow"<<endl;
	else if (wiek)
	{
		string rok_urodzenia, miesiac_urodzenia, dzien_urodzenia;
		int rok_urodzenia_liczba, miesiac_urodzenia_liczba, dzien_urodzenia_liczba;
		for (int i = 0; i < wielkosc_tablicy_wlascicieli(); i++)
		{
			rok_urodzenia = wlasciciel[i].get_data_urodzenia().substr(6, 4);
			rok_urodzenia_liczba = atoi(rok_urodzenia.c_str());
			miesiac_urodzenia = wlasciciel[i].get_data_urodzenia().substr(3, 2);
			miesiac_urodzenia_liczba = atoi(miesiac_urodzenia.c_str());
			dzien_urodzenia = wlasciciel[i].get_data_urodzenia().substr(0, 2);
			dzien_urodzenia_liczba = atoi(dzien_urodzenia.c_str());
			if (!(rok - rok_urodzenia_liczba >= wiek))
			{
				if (miesiac >= miesiac_urodzenia_liczba)
				{
					if(dzien >= dzien_urodzenia_liczba)
						licznik_znalezionych_dat++;
				}
			}
		}
		string *tablica_PESEL_znalezionych_dat = new string[licznik_znalezionych_dat];
		int licznik_tablicy_PESEL = 0;
		for (int i = 0; i < wielkosc_tablicy_wlascicieli(); i++)
		{
			rok_urodzenia = wlasciciel[i].get_data_urodzenia().substr(6, 4);
			rok_urodzenia_liczba = atoi(rok_urodzenia.c_str());
			miesiac_urodzenia = wlasciciel[i].get_data_urodzenia().substr(3, 2);
			miesiac_urodzenia_liczba = atoi(miesiac_urodzenia.c_str());
			dzien_urodzenia = wlasciciel[i].get_data_urodzenia().substr(0, 2);
			dzien_urodzenia_liczba = atoi(dzien_urodzenia.c_str());
			if (!(rok - rok_urodzenia_liczba >= wiek))
			{
				if (miesiac >= miesiac_urodzenia_liczba)
				{
					if (dzien >= dzien_urodzenia_liczba)
					{
						tablica_PESEL_znalezionych_dat[licznik_tablicy_PESEL] = wlasciciel[i].get_PESEL();
						licznik_tablicy_PESEL++;
					}
				}
			}
		}
		fstream plik_wyjsciowy;
		plik_wyjsciowy.open(nazwa_pliku_wyjsciowego, ios::out);
		for (int i = 0; i < licznik_tablicy_PESEL; i++)
		{
			for (int j = 0; j < wielkosc_tablicy_relacji(); j++)
			{
				if (tablica_PESEL_znalezionych_dat[i] == relacja[j].get_PESEL())
				{
					for (int k = 0; k < wielkosc_tablicy_wlascicieli(); k++)
					{
						if (tablica_PESEL_znalezionych_dat[i] == wlasciciel[k].get_PESEL())
						{
							plik_wyjsciowy << wlasciciel[k].get_imie() << " " << wlasciciel[k].get_nazwisko() << endl;
							break;
						}
					}
					break;
				}
			}
		}
		plik_wyjsciowy.close();
		delete[]tablica_PESEL_znalezionych_dat;
	}
}

filtr_wiek::~filtr_wiek()
{
}
