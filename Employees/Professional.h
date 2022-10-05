#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H

class Professional : Employee {
  public:
    int weekly_pay();
    int vacation_days();
    double healthcare_contribution();
    //yearly salary G&S
    void set_yearly_salary(int salary);
    int get_early_salary();
    //name G&S
    void set_name(std::string new_name);
    std::string get_name();
    //years worked G&S
    void set_years_worked(int number);
    int get_years_worked();
    void print_info();
  private:
    int yearly_salary;
};

#endif

