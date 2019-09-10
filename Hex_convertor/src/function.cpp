//
//  function.cpp
//  Binary_Hex
//
//  Created by Kudzayi Mwashita on 9/5/19.
//  Copyright © 2019 Kudzayi Mwashita. All rights reserved.
//

#include "function.hpp"
void clearCin() {
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}//clearCin()


//function takes in input value from user
void decimalToBinary(int enteredVal) {
	int reminder  = 0;

	while (enteredVal > 0) {
		reminder  = enteredVal % 2;
		std::cout << reminder;
		enteredVal /= 2;
	}//while
	std::cout << std::endl;
}//decimalToBinary


//function takes in binary value entered by user and returns a int decimal number
int binaryToDecimal(int binNum) {
	int decNum = 0;
	int pow = 1;
	int rem = 0;
	while (binNum > 0) {
		rem = binNum % 10;
		binNum /= 10;
		decNum += rem * pow;
		pow *= 2;
	}
	return decNum;
} //binaryToDecimal


//function takes in decimal number and prints out hexadecimal value
void decimalToHex(int decNum) {
	const int ARRAY_MAX = 6; //defines char of char array
	char hexNum[ARRAY_MAX] = { 32, 32, 32, 32, 32, '\0' }; //32 is space in the ASCII
	int rem = 0;
	int index = (5 - 1);

	while (decNum != 0) {
		rem = decNum % 16;
		if (rem < 10) {
			hexNum[index] = rem + 48; //ASCII value
			decNum /= 16;
		} else {
			hexNum[index] = rem + 55; //ASCII values
			decNum /= 16;
		}//if - else
		index--;
	}//while

	for (int i = 0; i < ARRAY_MAX; i++){
		std::cout << hexNum[i];
	}//for

}//decimalToHex


//function takes in hexadecimal value
void hexToDecimal(char hexValue[6]) {
	int index = 0;
	int rem = 0;
	unsigned long length = 0;
	int hexVal = 0;
	length = strlen(hexValue);
	for (index = 0; hexValue[index] != '\0'; index++) {
		length--;
		if (hexValue[index] >= '0' && hexValue[index] <= '9') {
			rem = hexValue[index] - 48;
		} else if (hexValue[index] >= 'a' && hexValue[index] <= 'f') {
			rem = hexValue[index] - 87;

		} else if (hexValue[index] >= 'A' && hexValue[index] <= 'F') {
			rem = hexValue[index] - 55;

		} else if (hexValue[index] > 'g' && hexValue[index] <= 'z') {
			std::cout << "Please stick to 0-9, a-f: " << std::endl;
			return;

		} else if (hexValue[index] > 'G' && hexValue[index] <= 'Z') {
			std::cout << "Please stick to 0-9, A-F: " << std::endl;
			return;

		}//if-else-if
		hexVal += rem * pow(16, length);
	}//for loop
	std::cout << "\nDecimal Value " << hexValue << " is : " << hexVal
			<< std::endl;

}//hexToDecimal()

