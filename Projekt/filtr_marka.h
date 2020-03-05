#pragma once
#include "filtr.h"
#include "Wlasciciele.h"
#include "Samochody.h"
#include "Relacje.h"
#include "wielkosci_tablic.h"
class filtr_marka : public filtr
{
public:
	filtr_marka();
	virtual void filtrowanie(Wlasciciele *wlasciciel, Samochody *samochod, Relacje *relacja, string nazwa_pliku);
	~filtr_marka();
};
