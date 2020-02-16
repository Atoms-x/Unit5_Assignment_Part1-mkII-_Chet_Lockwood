/*
	Teacher: Dr. Tyson McMillan, Ph.D. COSC 1436 
  STUDENT (McMillanite): Chet Lockwood
  Purpose: Functions and work
  IDE: Repl.it
*/

#include <iostream>  // Provides cout, cin, endl
#include <string> //for string manipulation
#include <iomanip>

using namespace std;

double weeklyPay (double, double, string, int); //Function Prototype

//Main function *********************************************************************************************
int main() 
{
  string lower = "TCC-TR IS COOL";
  string upper = "i will succeed at c++";
  string cReset = "\x1b[0m";
  locale loc;

  cout << fixed << setprecision(2);

  cout << weeklyPay(505.75, 47, "Chet", 1);
  cout << weeklyPay(55.25, 45, "Melivin", 1);
  cout << weeklyPay(65.25, 15, "Susan", 0);
  cout << weeklyPay(14.75, 41, "Mika", 1);
  cout << weeklyPay(15.0, 25, "Eldridge", 0);
  cout << weeklyPay(203.50, 55, "Freedom", 1);
  cout << weeklyPay(100.25, 32.5, "Tyson", 1);

  cout << cReset << "\n" << endl;
  for(int i = 0; i < lower.length(); i++)
    cout << tolower(lower[i],loc);

  cout << "\n" << endl;
  for(int i = 0; i < upper.length(); i++)
    cout << toupper(upper[i],loc);

  return 0;
}

//Function Definition ***************************************************************************************
double weeklyPay (double fHRate, double fHoursWorked, string fName, int fEmpStatus)
{
  
  //Variables for determining pay
  double overTimeHours = 0.0, grossPay = 0.0, fedIncTax = 0.0, taxableIncome = 0.0, netPay = 0.0;
  double hoursLessOT = 40.0, dental = 0.0, retirement = 0.0, medicare = 0.0145, socsecurity = .062;
  const double OVERTIMERATE = 2.0;
  
  locale loc; //convert the char int to the letter

  //COLORS
  string cGreen = "\x1b[1;32m";
  string cBlue = "\x1b[1;34m";
  string cUnderL = "\x1b[4m";
  string cReset = "\x1b[0m";

  //Captilize Name Output *****************************
  cout << cGreen << cUnderL << endl;
  for(int i = 0; i < fName.length(); i++)
  {
    cout << toupper(fName[i],loc);
  }
  cout << cReset << endl;

  // Pay Stuffs ****************************************
  if (fEmpStatus == 1)
    cout << "\tStatus: Fulltime" << endl;
  else
    cout << "\tStatus: Parttime" << endl;

  cout << "\tHours Worked: " << fHoursWorked << "  Rate: $" << fHRate << endl;

  if (fHoursWorked > 40 && fEmpStatus == 1)
    {
      overTimeHours = (fHoursWorked - 40);
      cout << "\tOvertime Hours: " << overTimeHours << endl;
    }
  
  fedIncTax = (fHRate >= 15) ? .15 : .12;
  cout << "\tFIT Rate: " << fedIncTax << endl;

  grossPay = (fHoursWorked <= 40 ) ? (fHoursWorked * fHRate) : 
             ((hoursLessOT * fHRate) + (overTimeHours * (OVERTIMERATE * fHRate)));
  cout << "\tGross Pay: $" << grossPay << endl;

  //Deductions Pre-Tax ************************************
  cout << cBlue << "\tDEDUCTIONS (pre tax):" << cReset << endl;

  dental = (fEmpStatus == 1) ? 17.00 : 0.00;
  cout << "\tDental Deduction: $" << dental << endl;

  retirement = (fEmpStatus == 1) ? 77.00 : 0.00;
  cout << "\tRetirement Deduction: $" << retirement << endl;

  taxableIncome = (grossPay - dental - retirement);
  cout << "\tTaxable Income (for FIT): $" << taxableIncome << endl;
  
  //Deductions *******************************************
  cout << cBlue << "\tDEDUCTIONS:" << cReset << endl;
  
  fedIncTax = (fedIncTax * taxableIncome);
  cout << "\tFIT Tax Amount: $" << fedIncTax << endl;

  medicare = (medicare * grossPay);
  socsecurity = (socsecurity * grossPay);
  cout << "\tSSDED = $" << socsecurity << "  MedDed = $" << medicare << endl;

  netPay = (grossPay - dental - retirement - fedIncTax - medicare - socsecurity);
  cout << "\tNET PAY for " << fName << " " << cGreen << cUnderL << "$";

return netPay;
}