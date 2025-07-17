#pragma once
#include "clsScreen.h"
# include <iostream>
# include "clsCurrency.h"
# include <iomanip>
# include "clsCurrenciesListScreen.h"
# include "clsFindCurrencyScreen.h"
# include "clsUpdateCurrencyRateScreen.h"
# include "clsCurrencyCalculatorScreen.h"

using namespace std;
class clsCurrencyExchangeScreen : protected clsScreen
{
private:

    enum enCurrencyExchangeMenueOption { eListCurrencies = 1 , eFindCurrency = 2 , eUpdateRate = 3 ,
    eCurrencyCalculator = 4 , eMainMenue = 5};

    static short _ReadCurrencyExchangeMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToCurrencyExchangeMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Exchange Menue...\n";

        system("pause>0");
        ShowCurrencyExchangeMenue();
    }

    static void _ShowListCurrenciesScreen()
    {
        clsCurrenciesListScreen::ShowListCurrenciesScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _MainMenue()
    {
        // Do nothing and main screen will handle it
    }

    static void _PerformCurrencyExchangeOption(enCurrencyExchangeMenueOption Option)
    {
        switch (Option)
        {
            case enCurrencyExchangeMenueOption::eListCurrencies:
            {
                system("cls");
                _ShowListCurrenciesScreen();
                _GoBackToCurrencyExchangeMenue();
                break;
            }
            case enCurrencyExchangeMenueOption::eFindCurrency:
            {
                system("cls");
                _ShowFindCurrencyScreen();
                _GoBackToCurrencyExchangeMenue();
                break;
            }
            case enCurrencyExchangeMenueOption::eUpdateRate:
            {
                system("cls");
                _ShowUpdateRateScreen();
                _GoBackToCurrencyExchangeMenue();
                break;
            }
            case enCurrencyExchangeMenueOption::eCurrencyCalculator:
            {
                system("cls");
                _ShowCurrencyCalculatorScreen();
                _GoBackToCurrencyExchangeMenue();
                break;
            }
            case enCurrencyExchangeMenueOption::eMainMenue:
            {
                //system("cls");
                _MainMenue();
                break;
            }
        }
    }

public:
	static void ShowCurrencyExchangeMenue()
	{
		system("cls");

		_DrawScreenHeader("Currency Exchange Main Screen");

        cout << setw(37) << left << "" << clsScreen::GreenFont << "===========================================\n";
        cout << setw(37) << left << "" << clsScreen::WhiteFont << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << clsScreen::GreenFont << "===========================================\n" << clsScreen::WhiteFont;
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
;
        cout << setw(37) << left << "" << clsScreen::GreenFont << "===========================================\n" << clsScreen::WhiteFont;

        _PerformCurrencyExchangeOption((enCurrencyExchangeMenueOption)_ReadCurrencyExchangeMenueOption());
	}
};

