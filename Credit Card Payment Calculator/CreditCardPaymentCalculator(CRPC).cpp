/*Hello.I am Thanish A/L Natarajan from class D2.I had been assigned to create a Credit Card Payment Calculator(CRPC).
  The problem is that many credit card holders does not know the number of months they have to pay and they also don't 
  know the amount they pay will make them financially balance or not.This program will help them to find number of months
  they have to pay according to the basic interest and outstanding balance and tell them their financial status based on 
  how much they pay over their monthly income.*/  
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int months=0;   // number of months user will have to pay
	double monthlyIncome, // monthly salary of user. 
			outBalance,  // outstanding balance.
			payLimit,    // minimum amount can pay by user
			monthlyPay, //monthly user willing to pay.
			interestAmount,  //amount of interest before 12 months
			remain,  //remaining of outstanding balance after every months.
			extraInterAmount, //amount of interest after 12 months, 3% added.
			totalInter,       //total interest before 12 months
			totalInter1,      //total interest after 12 months
			financeState,     //financial status of user
			annualInterest,   //interest per year in percentage
			basicInterest,    //interest before 12 months
			extraInterest,    //interest after 12 months
			interest;         //total amount of interest,before and after 12 months
	
	cout << "Enter your outstanding balance:RM ";
	cin >> outBalance;
	
	cout << "Enter annual interest in percentage(%): ";
	cin >> annualInterest;
	
	cout << "Enter your monthly income: ";
	cin >> monthlyIncome;
	
	cout << "Enter monthly payment you are willing to pay :RM ";
	cin >> monthlyPay;
	
	basicInterest = (annualInterest / 12) / 100;  //to calculate basic interest per month.
	extraInterest = ((annualInterest + 3)/12)/100; //to claculate basic interest after 12 months
	payLimit = outBalance * 0.05;
	
	cout << "Payment limit:RM " << payLimit << endl;
	cout << fixed << showpoint << setprecision(2) << endl;
	
	while (monthlyPay < payLimit)  // to make sure the monthly pay of user is not below 5% of oustanding balance.
		{
			cout << "The payment is below 5% of outstanding balance.\n";
			cout << "Enter monthly payment you are willing to pay:RM ";
			cin >> monthlyPay;
		}
			cout << "No.of.months"<< "\t" << "Remaining outstanding\n";
			
			
			while (outBalance>0)
			{
				months = months + 1;
				if(months<=12)
				{
				interestAmount = outBalance * basicInterest;        //calculate interest
				remain = outBalance - monthlyPay + interestAmount;  //remain of outstanding balance
				totalInter = totalInter + interestAmount;           //calculate total interest
				}
				else if (months > 12)
				{	
					extraInterAmount = outBalance * extraInterest;        //calculate interest
					remain = outBalance - monthlyPay + extraInterAmount;  //remain of outstanding balance
					totalInter1 = totalInter1 + extraInterAmount;         // calculate total interest
					
				}
				
				outBalance = remain;
				
				if(outBalance<0)
				{
					outBalance = (outBalance * -1) + outBalance;         //make outstanding balance zero
					cout << months << "\t\t\tRM " << outBalance << endl;    //display months and outstanding balance
					break;                                               //exit the while loop
				}
				
				cout << months << "\t\t\tRM " << outBalance << endl;        //display months and outstanding balance
			}
			interest = totalInter + totalInter1;                           //calculate total interest before and after 12 months
			cout << "No of months have to pay: " << months << endl;                 //dis[play number of months have to pay
			cout << "Amount of interest have to pay:RM " << (interest) << endl;     //display total interest have to pay
			
			//calculate the percentage of monthly payment of user over monthly income of user.
			financeState = (monthlyPay/monthlyIncome)*100; 
	
			if (financeState >= 30 && months > 24)
			{
				cout << "Your Financial Status: Very Bad.";
			}
	
			if (financeState >= 30 && months <= 24 )
			{
				cout << "Your Financial Status: Bad.";
			}
	
			if (financeState >20 && financeState <30)
			{
				cout << "Your Financial Status: Bad.";
			}
	
			if (financeState >10 && financeState <=20)
			{
				cout << " Your Financial Status: Moderate.";
			}
	
			if (financeState <= 10)
			{
				cout << "Your Financial Status: Good.";
			}
			cout << '\n';
	system("PAUSE");
	return 0;
}
