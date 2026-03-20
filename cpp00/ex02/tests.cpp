// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                       //
//                Created on  : Thu Nov 20 19:05:12 1989                     //
//                Last update : Wed Jan 04 14:17:17 1992                     //
//                Made by : Brad "42" Evans                                  //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>
#include "Account.hpp"


int	main( void ) {

	typedef std::vector<Account::t>	accounts;
	typedef accounts::iterator		accounts_iter;

	int	p_failures = 0;

	// test 01
	{
		accounts	a;
		a.push_back( Account( 42 ) );
		a.push_back( Account( 54 ) );
		a.push_back( Account( 957 ) );
		a.push_back( Account( 432 ) );
		a.push_back( Account( 1234 ) );
		a.push_back( Account( 0 ) );
		a.push_back( Account( 754 ) );
		a.push_back( Account( 16 ) );
		a.push_back( Account( 7654 ) );

		Account::displayAccountsInfos();
		for ( accounts_iter b = a.begin(); b != a.end(); ++b )
			( *b ).displayStatus();

		for ( int i = 0; i < 8; i++ )
		{
			a[i].makeDeposit( i * 765 );
		}

		Account::displayAccountsInfos();
		for ( accounts_iter b = a.begin(); b != a.end(); ++b )
			( *b ).displayStatus();

		for ( int i = 0; i < 8; i++ )
		{
			a[i].makeWithdrawal( i * 321 );
		}

		Account::displayAccountsInfos();
		for ( accounts_iter b = a.begin(); b != a.end(); ++b )
			( *b ).displayStatus();
	}

	return ( EXIT_SUCCESS );
}

//
// ************************************************************************* //
// vim: set ts=4 : //
// ************************************************************************* //
