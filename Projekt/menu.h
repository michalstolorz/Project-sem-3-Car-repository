#pragma once
#ifndef _MENU_H_
#define _MENU_H_
#include <stdlib.h>
#include "filtr.h"
#include "Samochody.h"
#include "Wlasciciele.h"
#include "Relacje.h"
#include "filtr_marka.h"
#include "filtr_kolor.h"
#include "filtr_wiek.h"
void menu(Wlasciciele *tablica_wlasciciele, Samochody *tablica_samochody, Relacje *tablica_relacje, string nazwa_wyjscie);
#endif#