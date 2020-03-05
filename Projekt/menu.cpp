#include "menu.h"

void menu(Wlasciciele *tablica_wlasciciele, Samochody *tablica_samochody, Relacje *tablica_relacje, string nazwa_wyjscie)
{
	int wielkosc_tab_wlasciciele = wielkosc_tablicy_wlascicieli(), wielkosc_tab_samochody = wielkosc_tablicy_samochodow(), wielkosc_tab_relacje = wielkosc_tablicy_relacji();
	int wybor;
	bool forward_condition = true;
	filtr *wsk = nullptr;
	filtr_marka ob_marka;
	filtr_kolor ob_kolor;
	filtr_wiek ob_wiek;
	while (forward_condition)
	{
		cout << "Co chcesz zrobic?" << endl;
		cout << "1. Wyswietl wszystkich wlascicieli" << endl;
		cout << "2. Wyswietl wszystkie samochody" << endl;
		cout << "3. Wypisz wlascicieli posiadajacych taka sama marke samochodu" << endl;
		cout << "4. Wypisz wlascicieli posiadajacych taki sam kolor samochodu" << endl;
		cout << "5. Wypisz wlascicieli posiadajacych samochod wedlug wieku" << endl;
		cout << "6. Wyjscie z programu" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case(1):
			for (int i = 0; i < wielkosc_tab_wlasciciele; i++)
				cout << tablica_wlasciciele[i];
			break;
		case (2):
			for (int i = 0; i < wielkosc_tab_samochody; i++)
				cout << tablica_samochody[i];
			break;
		case (3):
			wsk = &ob_marka;
			wsk->filtrowanie(tablica_wlasciciele, tablica_samochody, tablica_relacje, nazwa_wyjscie);
			break;
		case (4):
			wsk = &ob_kolor;
			wsk->filtrowanie(tablica_wlasciciele, tablica_samochody, tablica_relacje, nazwa_wyjscie);
			break;
		case(5):
			wsk = &ob_wiek;
			wsk->filtrowanie(tablica_wlasciciele, tablica_samochody, tablica_relacje, nazwa_wyjscie);
			break;
		case(6):
			cout << "Dziekuje za skorzystanie z programu" << endl;
			return;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
	delete wsk;
	return;
}