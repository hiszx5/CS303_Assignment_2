#ifndef EMPLOYEE_H
#define EMPLOYEE_H

//No .cpp file needed for Employee class as all functions are pure virtual
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

#endif
