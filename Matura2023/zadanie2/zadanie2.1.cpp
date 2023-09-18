#include <iostream>

using namespace std;

int main(void)
{
	//algorytm na dole
	auto przelicznik_w_locie = [](int dane)
	{
		int first_char = dane % 2; //przypisawanie pierwszego znaku '0/1'
		int counter_blokow = 1; //nie mozliwe zeby bylo 0 wiec zaczynam od 1

		while (dane>0) 
		{
			//cout << dane % 2; //reversed lol
			if (dane % 2 != first_char)
			{
				first_char = dane % 2;
				counter_blokow++;
			}
			dane /= 2;
		}

		return counter_blokow;
	};

	//test algorytmu
	int input_user;
	cin >> input_user;
	cout << przelicznik_w_locie(input_user);

}
