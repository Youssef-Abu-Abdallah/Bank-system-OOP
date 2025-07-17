#pragma once
# include <iostream>
# include "clsCurrency.h"
# include "clsScreen.h"
# include "clsInputValidate.h"

using namespace std;
class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

	static float _ReadRate()
	{
		cout << "\nEnter NewRate : ";
		return (clsInputValidate::ReadFloatNumber());
	}

public:

	static void ShowUpdateRateScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen");
		cout << "\nPlease enter Currency Code : ";
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is NOT found , choose another Currency Code : ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);

	
		cout << "\nAre you sure you want to update the rate of this currency [y/n]? ";
		char Answer;
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			cout << "\nUpdate Currency Rate : " << endl;
			cout << "_________________________" << endl;
			
			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency rate updated successfully :-)\n";
			_PrintCurrency(Currency);

		}
			
		

	}


};