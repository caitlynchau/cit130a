//
//  main.cpp
//  FinalExam
//
//  Created by Caitlyn Chau on 7/22/19.
//  Copyright © 2019 Caitlyn Chau. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;


// Employee abstract class
class Employee {
private:
    string firstName;
    string lastName;
    string address;
public:
    //accessor functions
    string getFirstName(){
        return firstName;
    }
    
    string getLastName(){
        return lastName;
    }
    
    string getAddress(){
        return address;
    }
    
    //mutator functions
    void setFirstName(string first){
        firstName = first;
    }
    
    void setLastName(string last){
        lastName = last;
    }
    
    void setAddress(string ad){
        address = ad;
    }
    
    virtual double getNetIncome() = 0;
};

//Manager class
class Manager : public Employee{
private:
    double annualSalary;
    int yearsOfExperience;
public:
    //default constructor
    Manager(){
        annualSalary = 0.0;
        yearsOfExperience = 0;
    }
    
    //non-default constructor
    Manager(double salary, int years, string first, string last, string address){
        annualSalary = salary;
        yearsOfExperience = years;
        Employee::setFirstName(first);
        Employee::setLastName(last);
        Employee::setAddress(address);
    }
    
    //accessor functions
    double getAnnualSalary(){
        return annualSalary;
    }
    
    int getYearsOfExperience(){
        return yearsOfExperience;
    }
    
    //mutator functions
    void setAnnualSalary(double salary){
        annualSalary = salary;
    }
    
    void setYearsOfExperience(int years){
        yearsOfExperience = years;
    }
    
    // getNetIncome calculates a manager's net income based on annual salary, years of experience
    // and tax rate
    double getNetIncome(){
        double grossIncome = annualSalary + (yearsOfExperience * 0.03 * annualSalary);
        const double TAX_RATE = 0.32;
        double incomeTax = grossIncome * TAX_RATE;
        double netIncome = grossIncome - incomeTax;
        return netIncome;
    }
    
    //prints out manager's appropriate information
    void printInfo(){
        cout << "Manager: " << Employee::getFirstName() << " " << Employee::getLastName();
        cout << ", " << Employee::getAddress() << ", $" << getNetIncome() << endl;
    }
};


class ProductionWorker : public Employee{
private:
    int weeklyHours;
    double payRate;
public:
    //default constructor
    ProductionWorker(){
        weeklyHours = 0;
        payRate = 0.0;
    }
    
    //non-default constructor
    ProductionWorker(int hours, double rate, string first, string last, string address){
        weeklyHours = hours;
        payRate = rate;
        Employee::setFirstName(first);
        Employee::setLastName(last);
        Employee::setAddress(address);
    }
    
    //accessor functions
    int getWeeklyHours(){
        return weeklyHours;
    }
    
    double getPayRate(){
        return payRate;
    }
    
    //mutator methods
    void setWeeklyHours(int hours){
        weeklyHours = hours;
    }
    
    void setPayRate(double rate){
        payRate = rate;
    }
    
    //getNetIncome function calculate's a production worker's net income based on
    //their pay rate, weekly hours, weeks per year, and tax rate
    double getNetIncome(){
        int weeksPerYear = 52;
        double grossIncome = payRate * weeklyHours * weeksPerYear;
        const double TAX_RATE = 0.2;
        double incomeTax = grossIncome * TAX_RATE;
        double netIncome = grossIncome - incomeTax;
        return netIncome;
    }
    
    //prints out production worker's appropriate information
    void printInfo(){
        cout << "Production Worker: " << Employee::getFirstName() << " " << Employee::getLastName();
        cout << ", " << Employee::getAddress() << ", $" << getNetIncome() << endl;
    }

};



int main() {
    char choice;
    cout << fixed << showpoint << setprecision(2);
    cout << "Menu\n";
    cout << "M: Manager\nP: Production Worker\n" << endl;
    do{
        // Start menu, select type of employee (M or P)
        char employeeType;
        cout << "Enter your selection: ";
        cin >> employeeType;
        while (toupper(employeeType) != 'M' && toupper(employeeType) != 'P'){
            cout << "ERROR: Enter M or P.\nEnter your selection: ";
            cin >> employeeType;
        }
        
        //Enter manager information
        if (toupper(employeeType) == 'M'){
            string firstName, lastName, address;
            double annaulSalary;
            int yearsOfExperience;
            cout << "\nEnter Manager Info" << endl;
            cout << "First Name: ";
            cin >> firstName;
            cout << "Last Name: ";
            cin >> lastName;
            cin.get(); //get the \n left in the buffer
            cout << "Address: ";
            getline(cin, address);
            cout << "Annual Salary: ";
            cin >> annaulSalary;
            cout << "Years of Experience: ";
            cin >> yearsOfExperience;
            
            //instantiate manager object
            Manager manager(annaulSalary, yearsOfExperience, firstName, lastName, address);
            manager.printInfo();
        }
        else if (toupper(employeeType) == 'P'){
            string firstName, lastName, address;
            double weeklyHours;
            int payRate;
            cout << "\nEnter Production Worker Info" << endl;
            cout << "First Name: ";
            cin >> firstName;
            cout << "Last Name: ";
            cin >> lastName;
            cin.get(); //get the \n left in the buffer
            cout << "Address: ";
            getline(cin, address);
            cout << "Weekly Hours: ";
            cin >> weeklyHours;
            cout << "Pay Rate: ";
            cin >> payRate;
            
            //instantiate production worker object
            ProductionWorker productionWkr(weeklyHours, payRate, firstName, lastName, address);
            productionWkr.printInfo();
        }
        
        cout << "Continue? (Y/N) ";
        cin >> choice;
        choice = toupper(choice);
        
        while (toupper(choice) != 'Y' && toupper(choice) != 'N'){
            cout << "Continue? (Y/N) ";
            cin >> choice;
            choice = toupper(choice);
        }
        
    }while(choice == 'Y');
    
    cout << "Bye!";
    
    return 0;
}

