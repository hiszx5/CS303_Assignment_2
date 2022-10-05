#include <iostream>
#include <string>
#include <cmath>
#include "Employee.h"
#include "Professional.h"


    int Professional::weekly_pay() {
      return std::ceil((yearly_salary / 52) * 100) / 100;
    }
    int Professional::vacation_days() {
      return 7 + floor((yearly_salary / 2000));
    }
    double Professional::healthcare_contribution() {
      return std::ceil((yearly_salary * 0.05) * 100) / 100;
    }
    void Professional::set_yearly_salary(int salary) {
      yearly_salary = salary;
    }
    int Professional::get_early_salary() {
      return yearly_salary;
    }
    void Professional::set_name(std::string new_name) {
      name = new_name;
    }
    std::string Professional::get_name() {
      return name;
    }
    void Professional::set_years_worked(int number) {
      years_worked = number;
    }
    int Professional::get_years_worked() {
      return years_worked;
    }
    void Professional::print_info() {
      std::cout << "Employee information for " << name << "" << std::endl;
      std::cout << "Years Worked: " << years_worked << std::endl;
      std::cout << "Weekly pay: $" << this->weekly_pay() << std::endl;
      std::cout << "Vacation days: " << this->vacation_days() << std::endl;
      std::cout << "Healthcare Contribution: $" << this->healthcare_contribution() << std::endl;
    }
