#pragma once
# include <iostream>
# include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency , string Message)
	{
		cout << "\n" << Message << endl;
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n_____________________________\n\n";

	}

	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode;
		cout << Message << endl;
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nInvalid Currency Code , Try again : ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		return clsCurrency::FindByCode(CurrencyCode);
	}

	static float _ReadAmount()
	{
		cout << "\nEnter Amount to Exchange: ";
		return (float)clsInputValidate::ReadDoublelNumberBetween(1, INT_MAX);
	}

	static void _PrintCalculationResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1, "Convert From:");
		
		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD To:";
		_PrintCurrencyCard(Currency2, "To:");

		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();

	}


public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'n';
		do
		{
			system("cls");
			_DrawScreenHeader("\tCalculate Currency Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease enter currency1 Code : ");

			clsCurrency CurrencyTo = _GetCurrency("\nPlease enter currency2 Code : ");

			float Amount = _ReadAmount();
			
			_PrintCalculationResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\nDo you want to perform another calculation ?  y/n? ";
			cin >> Continue;

		} while (toupper(Continue)=='Y');
	}

};

