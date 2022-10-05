#ifndef NONPROFESSIONAL_H
#define NONPROFESSIONAL_H

class Nonprofessional : Employee {
  public:
    int weekly_pay();
    int vacation_days();
    double healthcare_contribution();
    //hourly wage G&S
    void set_hourly_wage(double wage);
    double get_hourly_wage();
    //hours worked G&S
    void set_hours_worked(double hours);
    double get_hours_worked();
    //name G&S
    void set_name(std::string new_name);
    std::string get_name();
    //years worked G&S
    void set_years_worked(int number);
    int get_years_worked();
    void print_info();
  private:
    double hourly_wage;
    double hours_worked;
};

#endif
