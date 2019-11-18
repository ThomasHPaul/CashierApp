#include <iostream>
#include <string>
#include <cmath>


std::string getChange(double cashierInput);

int main() {

    std::cout << "$10.75\n";
    std::cout << getChange(10.75);

    std::cout << "$20.14\n";
    std::cout << getChange(20.14);

    std::cout << "$0.49\n";
    std::cout << getChange(0.49);

    std::cout << "$1.15\n";
    std::cout << getChange(1.15);

    std::cout << "$90.06\n";
    std::cout << getChange(90.06);

    std::cout << "$10.02\n";
    std::cout << getChange(10.02);


    return 0;
}

std::string getChange(double cashierInput)
{
    const int QUARTER = 25;
    const int DIME = 10;
    const int NICKEL = 5;
    const int PENNY = 1;

    int numOfDollars = 0;
    int numOfQuarters = 0;
    int numOfDimes = 0;
    int numOfNickels = 0;
    int numOfPennies = 0;
    int amountToReturn = 0;

    std::string changeMessage = "";

    numOfDollars = cashierInput; // Implicit cast from double to int captures the dollars to return
    amountToReturn = std::round((cashierInput - numOfDollars) * 100.0); // Initial round before storing as int prevents
                                                                        //  floating-point rounding errors

    numOfQuarters = amountToReturn / QUARTER;
    amountToReturn -= (numOfQuarters * QUARTER);

    numOfDimes = amountToReturn / DIME;
    amountToReturn -= (numOfDimes * DIME);

    numOfNickels = amountToReturn / NICKEL;
    amountToReturn -= (numOfNickels * NICKEL);

    numOfPennies = amountToReturn / PENNY;
    amountToReturn -= (amountToReturn * PENNY);

    changeMessage = "Please return:\n"
                  + std::to_string(numOfDollars)  + " dollars\n"
                  + std::to_string(numOfQuarters) + " quarters\n"
                  + std::to_string(numOfDimes)    + " dimes\n"
                  + std::to_string(numOfNickels)  + " nickels\n"
                  + std::to_string(numOfPennies)  + " pennies\n\n";

    return changeMessage;
}
