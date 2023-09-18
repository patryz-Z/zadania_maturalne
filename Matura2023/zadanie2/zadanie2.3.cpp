#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	fstream base_file;
	base_file.open("bin.txt", ios::in);

	//jest najwieksza gdy dlugosc jest dluzsza
	//ale gdy dlugosc jest taka sama to juz kwestia wystepowania '1' od lewej strony
	auto suma = [](string ciag)
	{
		int sum = 0;

		bool zero = false;

		for (int i = 0; i < ciag.length(); i++)
		{
			if (ciag[i] == '0') //gdy juz skoncza sie liczyc jedynki 
			{
				sum += i; //zostaje dodana ich ilosc od lewej strony
				zero = true;
				break; // i koniec liczenia
			}
		}

		if (zero == false) //jesli caly ciag binarny nie zawiera zadnych zer, to zostaje dodana do niego kolejna dlugosc
		{
			sum += ciag.length();
		}

		return sum;
	};

	string temporary_string;

	int najwieksza_suma = 0;
	string najwiekszy_bin = "";

	while (!base_file.eof())
	{
		base_file >> temporary_string;
		//cout << temporary_string << endl;
		
		if (temporary_string.length() > najwiekszy_bin.length())
		{
			najwieksza_suma = suma(temporary_string);
			najwiekszy_bin = temporary_string;
		}
		if (temporary_string.length() == najwiekszy_bin.length())
		{
			if (suma(temporary_string) > suma(najwiekszy_bin))
			{
				najwieksza_suma = suma(temporary_string);
				najwiekszy_bin = temporary_string;
			}
			if (suma(temporary_string) < suma(najwiekszy_bin))
			{
				continue;
			}
		}

	}

	cout << najwiekszy_bin;
}
