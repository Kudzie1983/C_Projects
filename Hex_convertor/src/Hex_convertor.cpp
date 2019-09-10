//
//  main.cpp
//  Binary_Hex
//
//  Created by Kudzayi Mwashita on 9/5/19.
//  Copyright © 2019 Kudzayi Mwashita. All rights reserved.
//
//=========================================================================

#include <iostream>
#include "function.hpp"
using namespace std;

int main() {

	while (true) {
		char choice;

		cout << "==================================" << endl;
		cout << "Welcome to the conversion program" << endl;
		cout << "==================================" << endl;

		cout << "1. Decimal to binary" << endl;
		cout << "2. Binary to Decimal" << endl;
		cout << "3. Decimal to hexadecimal" << endl;
		cout << "4. Hexadecimal to Decimal" << endl;
		cout << "x Exit program " << endl;

		cout << "=================================" << endl;
		cout << "Please enter a choice from the above" << endl;
		cin >> choice;
		clearCin();

		switch (choice) {

		/*** Case 1 ***/

		case '1': {
			unsigned decnum = 0;

			cout << "Please enter a positive number" << endl;
			cin >> decnum;
			clearCin();

			if (decnum < 0) {
				cout << "Entering negative numbers is not allowed!" << endl;
				break;
			} else {
				decimalToBinary(decnum);
			}
			break;
		}

			/***  section 2 ***/

		case '2': {
			string binNum;
			cout << "Please enter a max of 8 binary Number" << endl;
			getline(cin, binNum);

			if (binNum.length() > 8) {
				cout << "Please enter 8 digits for the binary number" << endl;
				break;

			} else {
				int Bin = 0;
				int convertedBinNum = 0;
				for (unsigned long i = 0; i < (binNum.length() - 1); i++) {
					if (binNum[i] == '0' || binNum[i] == '1') {

						Bin = 1;
					} else {

						Bin = 0;
					}
				}

				if (Bin) {
					convertedBinNum = std::stoi(binNum);
					int myDec = binaryToDecimal(convertedBinNum);
					cout << "you binary converted to decimal: " << myDec
							<< endl;
				} else {
					cout << "the string contains non 1s and 0s items!" << endl;
					break;
				}
			}
			break;
		}

			/*** Section 3 ***/

		case '3': {
			unsigned int decValue;
			cout << "Please enter a DecimalValue to convert to Hex!" << endl;
			cin >> decValue;
			clearCin();

			if (decValue < 0) {
				cout << "Value cannot be negative!" << endl;
				break;
			} else {
				cout << "The hexadecimal value of " << decValue << " is: ";
				decimalToHex(decValue);
				cout << endl;
			}

			break;
		}

			/*** Section 4 ***/

		case '4': {
			char hexaValue[10];
			cout << "Please enter a hexDecimal to convert to Decimal!" << endl;
			cin >> hexaValue;
			clearCin();
			hexToDecimal(hexaValue);
			break;
		}

			/*** Case X ***/

		case 'x': {
			cout << "!!!Utility ending,  thank you a have a good day !!!"
					<< endl; // prints !!!Utility ending,
			exit(1);
			break;
		}

			/*** Case Default ***/
		default:
			cout << "Invalid Choice, Enter a valid choice from the list below!"
					<< endl;
		}
	}
	return 0;

}
