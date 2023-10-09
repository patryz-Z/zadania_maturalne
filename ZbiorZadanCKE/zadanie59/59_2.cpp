#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{

	auto reverse_number = [](int number)
	{
		int done = 0;
		int temporary;

		while (number != 0)
		{
			temporary = number % 10;
			done = done * 10 + temporary;
			number /= 10;
		}

		return done;
	};

	auto palindrom = [](string number_string)
	{
		for (int i = 0; i < number_string.length() / 2; i++)
		{
			if (number_string[i] != number_string[number_string.length() - i - 1])
			{
				return false;
			}
		}
		return true;
	};

	fstream base_file;
	base_file.open("liczby.txt", ios::in);
	int temp_numb;
	int counter = 0;

	while (!base_file.eof())
	{
		base_file >> temp_numb;

		//cout << temp_numb << " | " << reverse_number(temp_numb) << " | Suma: " << temp_numb + reverse_number(temp_numb);
		if (palindrom(to_string(temp_numb + reverse_number(temp_numb))))
		{
			cout << "Palindrom: TAK" << endl;
			counter++;
		}
		else
		{
			cout << "Palindrom: NIE" << endl;
		}
	}

	cout << counter;
}
