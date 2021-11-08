// Program to convert decimal to hexadeciaml, octal, binary and vice versa.
/*
1. Decimal to Hexadecimal, octal, binary
2. Hexadecimal to Decimal, octal, binary
3. octal to Hexadecimal, Decimal, binary
4. binary to Hexadecimal, decimal, octal

*/
#include <iostream>
#include <cctype>
#include <string>
#include <bitset>
#include <bits/stdc++.h>
#include "functions.h"

int main()
{
    char reply{}; // To run the program or not
    do
    {
        int mode_reply{};        // mode selection
        int user_num;            // To take input from user
        std::string user_string; // to take binary inputs

        std::cout << "\nWhich Mode you would like to select(1 to 4): " << std::endl
                  << "1. Decimal to other base systems" << std::endl
                  << "2. Hexadecimal to other base systems" << std::endl
                  << "3. Decimal to other base systems" << std::endl
                  << "4. Binary to other base systems" << std::endl;

        std::cout << "Please enter a mode number: ";
        std::cin >> mode_reply;

        std::cout << std::endl;

        if (mode_reply == 2)
        {
            std::cout << "Enter a hex to be converted: ";
            std::cin >> std::hex >> user_num;
        }
        else if (mode_reply == 3)
        {
            std::cout << "Enter a octal to be converted: ";
            std::cin >> std::oct >> user_num;
        }
        else if (mode_reply == 4)
        {
            std::cout << "Enter a binary number to be converted: ";
            std::cin >> user_string;
        }

        else
        {
            std::cout << "Enter a number to be converted: ";
            std::cin >> user_num;
        }

        int user_num_stored = user_num;
        switch (mode_reply)
        {
        case 1:
            // Decimal to Other base
            {
                std::cout << "In hex it is: " << std::hex << std::showbase << user_num_stored << std::dec << std::endl;
                std::cout << "In binary it is: " << std::noshowbase << std::bitset<8>{user_num_stored} << std::dec << std::endl;
                std::cout << "In octal it is: " << std::oct << user_num << std::endl;
                break;
            }
        case 2:
            // Hex to other base
            {
                std::cout << "In decimal it is: " << std::dec << std::showbase << user_num_stored << std::endl;
                std::cout << "In binary it is: " << std::bitset<8>{user_num_stored} << std::endl;
                std::cout << "In octal it is: " << std::noshowbase << std::oct << user_num << std::endl;
                break;
            }
        case 3:
            // Octal to other base
            {
                std::cout << "In decimal it is: " << std::dec << std::showbase << user_num_stored << std::endl;
                std::cout << "In binary it is: " << std::bitset<8>{user_num_stored} << std::endl;
                std::cout << "In hex it is: " << std::hex << user_num << std::endl;
                break;
            }
        case 4:
            // binary to other base
            {
                std::bitset<8> bin_num(user_string);
                std::cout << "In decimal it is: " << std::stoull(user_string, 0, 2) << std::endl;
                std::cout << "In octal it is: " << convertBinarytoOctal(std::stoi(user_string)) << std::endl;
                std::cout << "In hex it is: " << std::hex << bin_num.to_ulong() << std::endl;
                break;
            }

        default:
            std::cout << "That's a wrong number\nPlease select from 1 to 12.";
            break;
        }
        std::cout << "Do you want to run the program again(y or n):";
        std::cin >> reply;
    } while (tolower(reply) == 'y');

    return 0;
}

// Code from Programiz
// Link to webpage: https://www.programiz.com/cpp-programming/examples/octal-binary-convert

// function to convert binary to octal
int convertBinarytoOctal(long long binaryNumber)
{
    int octalNumber = 0, decimalNumber = 0, i = 0;

    while(binaryNumber != 0)
    {
        decimalNumber += (binaryNumber%10) * pow(2,i);
        ++i;
        binaryNumber/=10;
    }

    i = 1;

    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    return octalNumber;
}