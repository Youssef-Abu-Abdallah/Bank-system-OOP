#pragma once
# include <iostream>
# include "clsInputValidate.h"
#include "clsScreen.h"
# include "clsCurrency.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{

private:

	enum enFindByOptions { Code = 1, Country = 2 };

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

	static short _ReadFindOption()
	{
		return (clsInputValidate::ReadShortNumberBetween(1, 2));
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency was NOT Found \n";
		}
	}

	static void _FindCurrencyByCode()
	{
		cout << "\nPlease enter Currency Code : ";
		string CurrencyCode = clsInputValidate::ReadString();
		
		////validation to ensure the input is there
		//while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		//{
		//	cout << "\nInvalid code , try again : ";
		//	CurrencyCode = clsInputValidate::ReadString();
		//}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		_ShowResults(Currency);
	}

	static void _FindCurrencyByCounteryName()
	{
		cout << "\nPlease enter Country Name : ";

		string CurrencyName = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCountry(CurrencyName);
		
		////validation to ensure the input is there
		//while (Currency.IsEmpty())
		//{
		//	cout << "\nInvalid code , try Name : ";
		//	CurrencyName = clsInputValidate::ReadString();
		//	Currency = clsCurrency::FindByCountry(CurrencyName);
		//}

		_ShowResults(Currency);
	}

	static void _PerformFindCurrencyOption(enFindByOptions Option)
	{
		switch (Option)
		{
			case enFindByOptions::Code:
			{
				_FindCurrencyByCode();
				break;
			}

			case enFindByOptions::Country:
			{
				_FindCurrencyByCounteryName();
				break;
			}
			
		}
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");

		cout << "\nFind by : [1] Code or [2] Country ? ";
		_PerformFindCurrencyOption((enFindByOptions)_ReadFindOption());

	}
	

};

