#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class ArithmeticOperationCalculator {
	char numberOne[40], numberTwo[40];
	double operandOne, operandTwo, result;
	char Operator;
	char answer;
	
	public:
		void message();
		void arithmeticOperationCalculator();
		char calculateAgainMessage();
};

void ArithmeticOperationCalculator::message() {
	system("cls");
	cout << "\n************************************************************************************************************************\n\n";
	cout << "\t\t\t\t\t    ARITHMETIC OPERATION CALCULATOR\n";
	cout << "\n************************************************************************************************************************\n\n";
	
	// Request two Numbers from the User.
	
	cout << "To Proceed, Enter Two Numbers\n\n";
}

void ArithmeticOperationCalculator::arithmeticOperationCalculator() {
	try {
		cout << "First Number : ";
		cin >> numberOne;
		cout << "\nOperator : ";
		cin >> Operator;
		cout << "\nSecond Number : ";
		cin >> numberTwo;
		
		// Examine each Character of the First Operand.
		
		// To find out if the User included a non - digit in the Number.
		
		for (int i = 0; i < strlen(numberOne); i++)
		{
			// Allow the Period.
			
			if ( ( !isdigit(numberOne[i])) && (numberOne[i] != '.' ) )
			{
				// Send the Error as a String.
				
				throw numberOne;
			}
			
			else
			{
				operandOne = atof(numberOne);
			}
		}
		
		// Do the same for the Second Number Entered.
		
		for (int j = 0; j < strlen(numberTwo); j++)
		{
			// Allow the Period.
			
			if ( ( !isdigit(numberTwo[j])) && (numberTwo[j] != '.' ) )
			{
				// Send the Error as a String.
				
				throw numberTwo;
			}
			
			else
			{
				operandTwo = atof(numberTwo);
			}
		}
		
		// Make sure the User typed a Valid Operator.
		
		if ( Operator != '+' && Operator != '-' && Operator != '*' && Operator != '/' )
		{
			throw Operator;
		}
		
		// Find out if the Denominator is 0.
		
		if ( Operator == '/' )
		{
			if ( operandTwo == 0 )
			{
				throw 0;
			}
		}
		
		// Perform an Operation based on the User's Choice.
		
		switch (Operator)
		{
			case '+':
				result = operandOne + operandTwo;
				break;
			case '-':
				result = operandOne - operandTwo;
				break;
			case '*':
				result = operandOne * operandTwo;
				break;
			case '/':
				result = operandOne / operandTwo;
				break;
			default:
				printf("Invalid Operator Encountered!\n");
		}
		
		// Display the Result of the Operation.
		
		cout << "\n" << operandOne << " " << Operator << " " << operandTwo << " = " << result << "\n\n";
		
	}
	
	catch (int n)
	{
		cout << "\nBad Operation : Division by " << n << " is not allowed.\n\n";
	}
	
	catch (char n)
	{
		cout << "\nOperation Error : " << n << " is not a valid operator.\n\n";
	}
	
	catch (char *badOperand)
	{
		cout << "\nError : " << badOperand << " is not a valid number.\n\n";
	}
}

char ArithmeticOperationCalculator::calculateAgainMessage() {
	cout << "\nDo you want to use Arithmetic Operation Calculator once again? (Press \"Y/y\" for \"Yes\" or \"N/n\" for \"No\")\n";
	cin >> answer;
	
	return answer;
}

int main()
{
	char answer;
	
	ArithmeticOperationCalculator *calculate = new ArithmeticOperationCalculator();
	
	do
	{
		calculate->message();
		calculate->arithmeticOperationCalculator();
		answer = calculate->calculateAgainMessage();
	} while ( ( answer == 'Y' ) || ( answer == 'y' ) );
	
	return 0;
}

