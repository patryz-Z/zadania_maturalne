#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	fstream base_file;
	base_file.open("bin.txt", ios::in);

	auto ile_blokow = [](string ciag)
	{
		int counter_blokow = 1;

		for(int i = 0; i < ciag.length()-1; i++)
		{
			if (ciag[i] != ciag[i + 1])
			{
				counter_blokow++;
			}
		}

		return counter_blokow;
	};

	string temporary_line;

	int ile_zwarunkiem = 0;

	while (!base_file.eof())
	{
		base_file >> temporary_line;
		//cout << temporary_line << endl;
		if (ile_blokow(temporary_line) <= 2)
		{
			ile_zwarunkiem++;
		}
	}
	cout << ile_zwarunkiem;
}
