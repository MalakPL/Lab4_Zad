#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <io.h>
#include <fcntl.h>

using std::cin;
using std::wcout;
using std::cerr;
using std::endl;
using std::exception;
using std::max_element;
using std::map;
using std::setw;

const char* IntCastExceptionMessage = "Podana wartosc nie mogla zostac zrzutowana do typu int.";

auto Zadanie1() -> void
{
	wcout << "[Zadanie 1]" << endl;

	int N;
	wcout << "Podaj rozmiar tablicy: "; cin >> N;

	if (cin.fail()) { throw exception{ IntCastExceptionMessage }; }

	if (N <= 0)
	{
		throw exception{ "Rozmiar tablicy musi byc wiekszy od 0" };
	}

	int* Tablica = new int[N];

	for (int i = 0; i < N; ++i)
	{
		wcout << L"Podaj wartość dla Tablica[" << i << "]: "; cin >> Tablica[i];
		if (cin.fail()) { throw exception{ IntCastExceptionMessage }; }
	}

	wcout << L"Największy element tablicy to: " << *max_element(Tablica, Tablica + N) << endl << endl;

	if (Tablica != nullptr)
	{
		delete[] Tablica;
		Tablica = nullptr;
	}
}

auto Zadanie2() -> void
{
	wcout << "[Zadanie 2]" << endl;

	int N;
	wcout << L"Podaj rozmiar tablicy: "; cin >> N;

	if (cin.fail()) { throw exception{ IntCastExceptionMessage }; }

	if (N <= 0)
	{
		throw exception{ "Rozmiar tablicy musi byc wiekszy od 0" };
	}

	int* Tablica = new int[N];
	map<int, int> FreqMap;

	for (int i = 0; i < N; ++i)
	{
		wcout << L"Podaj wartość dla Tablica[" << i << "]: "; cin >> Tablica[i];
		if (cin.fail()) { throw exception{ IntCastExceptionMessage }; }

		++FreqMap[Tablica[i]];
	}

	int Max = 0;
	int Number = 0;
	for (auto const& i : FreqMap)
	{
		if (i.second > Max)
		{
			Max = i.second;
			Number = i.first;
		}
	}
	wcout << L"Najczęściej występujący element tablicy to: " << Number << L" (" << Max << L" występowań)" << endl << endl;

	if (Tablica != nullptr)
	{
		delete[] Tablica;
		Tablica = nullptr;
	}
}

auto Zadanie3() -> void
{
	wcout << "[Zadanie 3]" << endl;

	int Tablica[10][10]{};

	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			switch (y)
			{
			case 0:
				Tablica[y][x] = x;
				break;

			case 1:
				Tablica[y][x] = (x << 1);
				break;

			case 2:
				Tablica[y][x] = x * x;
				break;

			case 3:
				Tablica[y][x] = (x + 1) + (y + 1);
				break;

			case 4:
				Tablica[y][x] = (x + 1) - (y + 1);
				break;

			default:
				Tablica[y][x] = 0;
				break;
			}

			wcout << setw(5) << Tablica[y][x];
		}

		wcout << endl;
	}
}

auto main() -> int
{
	/* Obsługa wyjątków */
	try
	{
		if (_setmode(_fileno(stdout), _O_U8TEXT) == -1)
		{
			throw exception{ "Nie mozna ustawic kodowania UTF-8" };
		}

		Zadanie1();
		Zadanie2();
		Zadanie3();
	}
	catch (exception ex)
	{
		cerr << "Wyjatek: " << ex.what() << endl;

		return 1; /* Zwracamy błąd */
	}

	return 0;
}