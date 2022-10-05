#include <iostream>
#include <string>
#include <cmath>

//EMPLOYEE CLASS
class Employee {
  public:
  virtual int weekly_pay() = 0;
  virtual int vacation_days() = 0;
  virtual double healthcare_contribution() = 0;
  virtual void print_info() = 0;
  protected:
    std::string name;
    int years_worked;
};

//PROFESSIONAL CLASS
class Professional : Employee {
  public:
    int weekly_pay() { //gets weekly pay
      return std::ceil((yearly_salary / 52) * 100) / 100;
    }
    int vacation_days() { //calculates available vacation days
      return 7 + floor((yearly_salary / 2000));
    }
    double healthcare_contribution() { //calculates how much money has been matched
      return std::ceil((yearly_salary * 0.05) * 100) / 100;
    }
    //yearly salary G&S
    void set_yearly_salary(int salary) {
      yearly_salary = salary;
    }
    int get_early_salary() {
      return yearly_salary;
    }
    //name G&S
    void set_name(std::string new_name) {
      name = new_name;
    }
    std::string get_name() {
      return name;
    }
    //years worked G&S
    void set_years_worked(int number) {
      years_worked = number;
    }
    int get_years_worked() {
      return years_worked;
    }
    void print_info() {
      std::cout << "Employee information for " << name << "" << std::endl;
      std::cout << "Years Worked: " << years_worked << std::endl;
      std::cout << "Weekly pay: $" << this->weekly_pay() << std::endl;
      std::cout << "Vacation days: " << this->vacation_days() << std::endl;
      std::cout << "Healthcare Contribution: $" << this->healthcare_contribution() << std::endl;
    }
  private:
    int yearly_salary;
};

//NONPROFESSIONAL CLASS
class Nonprofessional : Employee {
  public:
    int weekly_pay() { //gets weekly pay
      return std::ceil((hourly_wage * hours_worked) * 100) / 100;
    }
    int vacation_days() { //calculates available vacation days
      return floor(hours_worked / 80);
    }
    double healthcare_contribution() { //calculates how much money has been matched
      return std::ceil(((hours_worked * hourly_wage) * 0.05) * 100) / 100;
    }
    //hourly wage G&S
    void set_hourly_wage(double wage) {
      hourly_wage = wage;
    }
    double get_hourly_wage() {
      return hourly_wage;
    }
    //hours worked G&S
    void set_hours_worked(double hours) {
      hours_worked = hours;
    }
    double get_hours_worked() {
      return hours_worked;
    }
    //name G&S
    void set_name(std::string new_name) {
      name = new_name;
    }
    std::string get_name() {
      return name;
    }
    //years worked G&S
    void set_years_worked(int number) {
      years_worked = number;
    }
    int get_years_worked() {
      return years_worked;
    }
    void print_info() {
      std::cout << "Employee information for " << name << "" << std::endl;
      std::cout << "Years Worked: " << years_worked << std::endl;
      std::cout << "Weekly pay: $" << this->weekly_pay() << std::endl;
      std::cout << "Vacation days: " << this->vacation_days() << std::endl;
      std::cout << "Healthcare Contribution: $" << this->healthcare_contribution() << std::endl;
    }
  private:
    double hourly_wage;
    double hours_worked;
};



int main() {
  Professional adam;
  Nonprofessional eve;

  adam.set_name("Adam");
  adam.set_yearly_salary(52000);
  adam.set_years_worked(18);

  eve.set_name("Eve");
  eve.set_hourly_wage(15.50);
  eve.set_hours_worked(88.2);

  adam.print_info();
  std::cout << std::endl;
  eve.print_info();
}