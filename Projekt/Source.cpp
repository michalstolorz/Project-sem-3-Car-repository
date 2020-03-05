#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "Samochody.h"
#include "Wlasciciele.h"
#include "Relacje.h"
#include "filtr.h"
#include "filtr_marka.h"
#include "filtr_kolor.h"
#include "filtr_wiek.h"
#include "inicjalizacja_relacji.h"
#include "inicjalizacja_samochodow.h"
#include "inicjalizacja_wlascicieli.h"
#include "wielkosci_tablic.h"
#include "menu.h"
#include <vld.h>

using namespace std;

int main(int argc, char* argv[])
{
	Wlasciciele *tablica_wlasciciele = nullptr;
	Samochody *tablica_samochody = nullptr;
	Relacje *tablica_relacje = nullptr;
	string nazwa_wlasciciele, nazwa_samochody, nazwa_relacje, nazwa_wyjscie;
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "inper.txt"))
			nazwa_wlasciciele = argv[i];
		if (!strcmp(argv[i], "incar.txt"))
			nazwa_samochody = argv[i];
		if (!strcmp(argv[i], "inrel.txt"))
			nazwa_relacje = argv[i];
		if (!strcmp(argv[i], "out.txt"))
			nazwa_wyjscie = argv[i];
	}
	tablica_wlasciciele = inicjalizacja_wlascicieli(nazwa_wlasciciele);
	tablica_samochody = inicjalizacja_samochodow(nazwa_samochody);
	tablica_relacje = inicjalizacja_relacji(nazwa_relacje);
	menu(tablica_wlasciciele, tablica_samochody, tablica_relacje, nazwa_wyjscie);
	delete[]tablica_samochody;
	delete[]tablica_wlasciciele;
	delete[]tablica_relacje;
	system("pause");
	return 0;
}