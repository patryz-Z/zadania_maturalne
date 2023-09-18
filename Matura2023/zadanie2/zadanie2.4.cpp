#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{	
	auto BinaryToDecimal = [](int binary)
	{
		int decimal_value = 0;
		int base = 1;

		while (binary)
		{
			int last_digit = binary % 10;

			decimal_value += last_digit * base;

			binary = binary / 10;
			base *= 2;
		}

		return decimal_value;
	};
	
	auto DecimalToBinary = [](int decimal)
	{
		string binary_string = "";
		int binary = 0;
		int base = 1;

		while (decimal > 0)
		{
			char bit = decimal % 2 + 48;

			binary_string = bit + binary_string;
			//binary += bit * base;

			decimal /= 2;
			base *= 10;
		}

		return binary_string;
	};

	auto XOR = [](string a, string b)
	{
		string xor_res = "";
		for (int i = 0; i < a.length(); i++)
		{
			if ((a[i] == '1' and b[i] == '1') or (a[i] == '0' and b[i] == '0'))
			{
				xor_res += '0';
			}
			if ((a[i] == '1' and b[i] == '0') or (a[i] == '0' and b[i] == '1'))
			{
				xor_res += '1';
			}
		}
		return xor_res;
	};

	int a;
	string b;
	cout << "a: "; cin >> a;
	cout << "b: "; cin >> b;

	string binary_of_a = DecimalToBinary(a);
	cout << "a binary: " << binary_of_a << endl;
	cout << "b binary: " << b << endl;

	if (binary_of_a.length() > b.length())
	{
		for (int i = 0; i < binary_of_a.length() - b.length(); i++)
		{
			b = '0' + b;
		}
	}
	if (binary_of_a.length() < b.length())
	{
		for (int i = 0; i < b.length() - binary_of_a.length(); i++)
		{
			binary_of_a = '0' + binary_of_a;
		}
	}

	cout << "a binary: " << binary_of_a << endl;
	cout << "b binary: " << b << endl;

	cout << "XOR of a/b: " << XOR(binary_of_a, b);


}
