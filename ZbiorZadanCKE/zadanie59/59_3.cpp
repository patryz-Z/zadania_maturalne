#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{

	auto algorithm = [](int number)
	{
		int division = 1;
		int macht = 0;

		while (number > 0)
		{
			if (number < 10){	break;}
			while (number > 0)
			{
				division *= number % 10; 
				number /= 10; //skracanie cyfry
			}	
			//cout << division << endl; //testowo
			number = division; //trick zeby nie robic next petli
			division = 1; //mnoznik zerowany by nie byl zawyzany przy kolejnym 
			macht++; //licznik moc
		}

		return macht;

	};

	fstream base_file;
	base_file.open("liczby.txt", ios::in);
	int temp_numb;

	int max = INT_MIN;
	int min = INT_MAX;

	int counter_table[10] = {};
	
	while (!base_file.eof())
	{
		base_file >> temp_numb;
		if (algorithm(temp_numb) <= 8 and algorithm(temp_numb) >= 1)
		{
			counter_table[algorithm(temp_numb)-1]++;
		}

		if (algorithm(temp_numb) == 1)
		{
			if (temp_numb > max)
			{
				max = temp_numb;
			}
			if (temp_numb < min)
			{
				min = temp_numb;
			}
		}

	}
	for (int i = 0; i < 8; i++)
	{
		cout << i + 1 << " | " << counter_table[i] << endl;
	}
	cout << "MIN: " << min << "\nMAX: " << max;

}
