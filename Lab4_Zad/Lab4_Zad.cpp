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

/*
Znajdź największy element danej tablicy liczb całkowitych.
Liczbę elementów tablicy i ich wartości pobierz od użytkownika.
*/
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


/*
Napisz program, który wskazuje najczęściej występujący element
w tablicy liczb całkowitych. Liczbę elementów tablicy i ich wartości
pobierz od użytkownika.
*/
auto Zadanie2() -> void
{
	wcout << "[Zadanie 2]" << endl;

#pragma region Liczbę elementów tablicy i ich wartości pobierz od użytkownika.
	int N;
	wcout << L"Podaj rozmiar tablicy: "; cin >> N;

	if (cin.fail()) { throw exception{ IntCastExceptionMessage }; }

	if (N <= 0)
	{
		throw exception{ "Rozmiar tablicy musi byc wiekszy od 0" };
	}

	int* Tablica = new int[N];
	map<int, int> FreqMap; /* Słowniczek posłuży do liczenia występowań elementów w tablicy */

	for (int i = 0; i < N; ++i)
	{
		wcout << L"Podaj wartość dla Tablica[" << i << "]: "; cin >> Tablica[i];
		if (cin.fail()) { throw exception{ IntCastExceptionMessage }; }

		++FreqMap[Tablica[i]]; //Inkrementacja częstotliwośći występowania danego elementu
	}
#pragma endregion

#pragma region Najczęściej występujący element w tablicy liczb całkowitych.
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
#pragma endregion

	if (Tablica != nullptr)
	{
		delete[] Tablica;
		Tablica = nullptr;
	}
}


/*
Napisz program, który w zadeklarowanej tablicy dwuwymiarowej 10x10 umieszcza:
- w pierwszej kolumnie liczby od 0 do 9;
- w drugiej sumę tych liczb (np. 0+0, 1+1 itd..);
(1 p.)
* Część bonusowa:
- w trzeciej – kwadraty tych liczb;
- w czwartej – sumę numeru wiersza i numeru kolumny;
- w piątej – wynik różnicy numeru wiersza i numeru kolumny;
- w pozostałych kolumnach 0 (interpretacja graficzna tablicy poniżej).
(*2 p.)
*/
auto Zadanie3() -> void
{
	wcout << "[Zadanie 3]" << endl;

	const int N = 10;
	int Tablica[N][N]{};

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			switch (y)
			{
			case 0:
				Tablica[y][x] = x; //- w pierwszej kolumnie liczby od 0 do 9;
				break;

			case 1:
				Tablica[y][x] = (x << 1); //- w drugiej sumę tych liczb (np. 0+0, 1+1 itd..); X+X <=> 2X <=> przesuniecie bitowe w lewo (szybsze)
				break;

			case 2: 
				Tablica[y][x] = x * x; //- w trzeciej – kwadraty tych liczb;
				break;

			case 3:
				Tablica[y][x] = (x + 1) + (y + 1); //- w czwartej – sumę numeru wiersza i numeru kolumny; (numer, nie indeks, czyli numeracja od 1...N)
				break;

			case 4:
				Tablica[y][x] = (x + 1) - (y + 1); //- w piątej – wynik różnicy numeru wiersza i numeru kolumny; (numer, nie indeks, czyli numeracja od 1...N)
				break;

			default:
				Tablica[y][x] = 0; //- w pozostałych kolumnach 0
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