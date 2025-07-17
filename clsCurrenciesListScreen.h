#pragma once
# include <iostream>
#include "clsScreen.h"
# include <iomanip>
# include <vector>
# include <fstream>
# include "clsCurrency.h"

using namespace std;
class clsCurrenciesListScreen : protected clsScreen
{
private:

	static void _PrintCurrencyRecord(clsCurrency Currency)
	{
		cout << setw(8) << "" << "| " << setw(40) << left << Currency.Country();
		cout << "| " << setw(5) << left << Currency.CurrencyCode();
		cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
	}

public:

	static void ShowListCurrenciesScreen()
	{
		system("cls");
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
		string Title = "\tCurrencies List Screen";
		string SubTitle = "\t(" + to_string(vCurrencies.size()) + ") currency";

		_DrawScreenHeader(Title, SubTitle);


		cout << setw(8)<<""<< "\n----------------------------------------------------------------------------------------------------------------------\n";
		cout << setw(8) << "" << "| " << setw(40) << left << "Country";
		cout << "| " << setw(5) << left << "Code";
		cout << "| " << setw(40) << left << "Name";
		cout << "| " << setw(10) << left << "Rate / (1$)";
		cout << setw(8) << "" << "\n----------------------------------------------------------------------------------------------------------------------\n";

		if (vCurrencies.size() == 0)
		{
			cout << "\n\t\t\t\tNo avaliable currencies in the system\n";
		}
		else
		{
			for (clsCurrency Currency : vCurrencies)
			{
				_PrintCurrencyRecord(Currency);
				cout << endl;
			}
		}
		
		cout << setw(8) << "" << "\n----------------------------------------------------------------------------------------------------------------------\n";


	}

};

