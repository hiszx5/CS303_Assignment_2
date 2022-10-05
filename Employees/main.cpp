//INCLUDES FOR CLASSES
#include <iostream>
#include <string>
#include <cmath>
#include "Employee.h"
#include "Professional.h"
#include "Nonprofessional.h"
//INCLUDES FOR ERROR HANDLING
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <ios>
#include "functions.h"

int main() {

  //THIS PORTION OF THE CODE IS THE TESTING OF THE CLASSES AND INHERATENCE
  
  //creating instances of employees
  Professional adam;
  Nonprofessional eve;

  //setting basic information
  adam.set_name("Adam");
  adam.set_yearly_salary(52000);
  adam.set_years_worked(18);

  eve.set_name("Eve");
  eve.set_hourly_wage(15.50);
  eve.set_hours_worked(88.2);

  //displaying info to console
  adam.print_info();
  std::cout << std::endl;
  eve.print_info();

  //THIS PORTION OF THE CODE IS THE ERROR TESTING FUNCTIONALITY;
  //WILL RUN THROUGH AS NORMAL, BUT VALIDATES USER INPUT BEFORE FUNCTION CALL

  //creating variables to populate initial array
  int outputNumber;
  int userIndex;
  int userNumber;
  char menuOption;
  bool valid = false;
  int size = 100;
  int* array = new int[size];
  unsigned int index = 0;
  int dataPoint;
  std::ifstream file("text.txt");
  std::cin.exceptions(std::ios_base::failbit);

  //loop to populate array
  if (file.is_open()) {
    while (file >> dataPoint) {
      array[index] = dataPoint;
      index += 1;
    }
  }


  while (menuOption != 'Q') {
    printArray(array, size);
    printMenu();
    std::cin >> menuOption;
    switch (menuOption) {
      case 'F':
        std::cout << "Enter number to search for -> ";
        std::cin >> userNumber;
        userIndex = checkIndex(array, userNumber, size);
        if (userIndex == -1) {
          std::cout << "Number does not exsist in array.";
        }
        else {
          std::cout << userNumber << " exsists in index " << userIndex << "." << std::endl << std::endl;
        }
        break;
      case 'M':
      while (valid == false) {
          //try and catch blocks make sure user does not try to modify index that does not exsist in array
          try {
            std::cout << "Enter index to change -> ";
            std::cin >> userIndex;
            if (userIndex < 0 || userIndex >= size) { //making sure input is within bounds of array index
              throw std::runtime_error("Invalid input--please enter a number within limits of array size.");
            }
            valid = true; //if error isnt thrown loop is able to be terminated
            std::cout << "Enter new number for index " << userIndex << " -> ";
            std::cin >> userNumber;
            outputNumber = modifyIndex(array, userIndex, userNumber);
            std::cout << outputNumber << " was replaced by " << userNumber << "." << std::endl;
            }
          catch (std::runtime_error& exception) {
            std::cout << exception.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            continue; //will repeat user input portion until it is verified
          }
        }
        valid = false; //resetting the bool value to use in other error handling loops
        break;
      case 'A':
        //try and catch blocks will verify that user input is a number
        while (valid == false) {
          try {
            std::cout << "Enter a number to add to array -> ";
            std::cin >> userNumber;
            if (std::cin.fail()) {
              throw 1;
            }
            valid = true; //validated user input if error not thrown
            addIndex(array, userNumber, size);
            std::cout << userNumber << " was successfully added to the array." << std::endl << std::endl;
          }
          catch(...) {
            std::cout << "Input must be a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            continue;
          }
        }
        break;
      case 'R':
        std::cout << "Enter index to remove -> ";
        std::cin >> userIndex;
        del_val(array, size, userIndex);
        
        std::cout << std::endl << "Index " << userIndex << " was successfully removed from the array." << std::endl;
        break;
      case 'Q':
        std::cout << "Exiting program.";
      default :
        std::cout << "Hello";
    }
  }
}