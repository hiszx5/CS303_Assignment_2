#include <iostream>
#include <string>
#include <cmath>
#include "Employee.h"
#include "Nonprofessional.h"


int Nonprofessional::weekly_pay() { //gets weekly pay
  return std::ceil((hourly_wage * hours_worked) * 100) / 100;
}
int Nonprofessional::vacation_days() { //calculates available vacation days
  return floor(hours_worked / 80);
}
double Nonprofessional::healthcare_contribution() { //calculates how much money has been matched
  return std::ceil(((hours_worked * hourly_wage) * 0.05) * 100) / 100;
}
//hourly wage G&S
void Nonprofessional::set_hourly_wage(double wage) {
  hourly_wage = wage;
}
double Nonprofessional::get_hourly_wage() {
  return hourly_wage;
}
//hours worked G&S
void Nonprofessional::set_hours_worked(double hours) {
  hours_worked = hours;
}
double Nonprofessional::get_hours_worked() {
  return hours_worked;
}
//name G&S
void Nonprofessional::set_name(std::string new_name) {
  name = new_name;
}
std::string Nonprofessional::get_name() {
  return name;
}
//years worked G&S
void Nonprofessional::set_years_worked(int number) {
  years_worked = number;
}
int Nonprofessional::get_years_worked() {
  return years_worked;
}
void Nonprofessional::print_info() {
  std::cout << "Employee information for " << name << "" << std::endl;
  std::cout << "Years Worked: " << years_worked << std::endl;
  std::cout << "Weekly pay: $" << this->weekly_pay() << std::endl;
  std::cout << "Vacation days: " << this->vacation_days() << std::endl;
  std::cout << "Healthcare Contribution: $" << this->healthcare_contribution() << std::endl;
}