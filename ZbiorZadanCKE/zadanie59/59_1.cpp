#include <iostream>
#include <fstream>

using namespace std;

bool is_it_even(int number)
{
	if (number == 1 or number == 0)
	{
		return false;
	}

	for (int i = 2; i * i <= number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main(void)
{

	auto good = [](int number)
	{
		int times = 3;
		int local = 1;
		int counter = 0;

		while (number % 2 == 0)
		{
			return false;
		}

		while (number > 1)
		{
			if (number % times == 0 and is_it_even(times))
			{
				number /= times;

				if (times != local)
				{
					counter++;
					local = times;
				}
			}
			else
			{
				times++;
			}
		}
		if (counter == 3)
		{
			return true;
		}
		return false;
	};


	fstream base_file;
	base_file.open("liczby.txt", ios::in);
	int temp_numb;
	int counter = 0;

	while (!base_file.eof())
	{
		base_file >> temp_numb;
		if (good(temp_numb) and !is_it_even(temp_numb))
		{
			counter++;
		}
	}

	cout << counter;
}
