#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

class Calculator {
public:
    static void pauseAndClear() 
    {
        cout << "Press enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        system("cls");
    }

    static void menu(double a, double b, double result) 
    {

        cout << fixed << setprecision(2);
        cout << setw(40) << right << "*** Calculator Menu ***" << endl;
        cout << "----------------------" << endl;
        cout << setw(5) << left << "CURRENT RESULT: " << setw(5) << right << result << endl;
        cout << "----------------------" << endl;
        cout << "CURRENT OPERANDS:" << endl;
        cout << "FIRST OPERAND: " << a << endl;
        cout << "SECOND OPERAND: " << b << endl;
        cout << "----------------------" << endl;
        cout << " | OPERATIONS |" << endl;
        cout << " [1] Add\n [2] Subtract\n [3] Multiply\n [4] Divide\n";
        cout << "----------------------" << endl;
        cout << " | OPTIONS |" << endl;
        cout << " [5] Input New Operands\n [6] Instructions\n [7] Quit\n";
        execute(a, b, result);
    }

    inline static void add(double a, double b, double& result) 
    {
        if (a != 0 && b == 0)
        {
            cout << a << " + ";
            cin >> b;
        }
        result = a + b;
        cout << "\n" << a << " + " << b << " = " << result << "\n\n";

        pauseAndClear();
        menu(result, 0, result);
    }

    inline static void subtract(double a, double b, double& result) 
    {
        if (a != 0 && b == 0)
        {
            cout << a << " - ";
            cin >> b;
        }
        result = a - b;
        cout << "\n" << a << " - " << b << " = " << result << "\n\n";

        pauseAndClear();
        menu(result, 0, result);
    }

    inline static void multiply(double a, double b, double& result) 
    {
        if (a != 0 && b == 0)
        {
            cout << a << " * ";
            cin >> b;
        }
        result = a * b;
        cout << "\n" << a << " * " << b << " = " << result << "\n\n";

        pauseAndClear();
        menu(result, 0, result);
    }

    inline static void divide(double a, double b, double& result) 
    {

        if (a == 0 && b == 0)
        {
            result = 0;
            cout << "\n" << a << " / " << b << " = " << result << "\n\n";
            pauseAndClear();
            menu(result, 0, result);
        }
        else if (a != 0 && b == 0)
        {
            cout << a << " / ";
            cin >> b;
            while (b == 0)
            { 
                cout << "Enter a non-zero divisor: ";
                cin >> b;
            }
        }

        result = a / b;

        cout << "\n" << a << " / " << b << " = " << result << "\n\n";

        pauseAndClear();
        menu(result, 0, result);
    }

    static void execute(double a, double b, double result) 
    {
        int userInput;

        if (cin.fail()) 
        {
            cin.clear(); 
            cin.ignore();
            cout << "Invalid option. Try again." << endl;
            pauseAndClear();
            menu(a, b, result);
            return;
        }

        cout << endl;
        cout << "Choose an option: ";
        cin >> userInput;

        switch (userInput) 
        {
            case 1: add(a, b, result); return;
            case 2: subtract(a, b, result); return;
            case 3: multiply(a, b, result); return;
            case 4: divide(a, b, result); return;
            case 5:
                cout << "Enter first number: "; cin >> a;
                cout << "Enter second number: "; cin >> b;
                pauseAndClear();
                menu(a, b, 0);
                return;
            case 6:
                system("cls");
                cout << "********** INSTRUCTIONS **********\n"
                << "1. Enter two numbers using option [5] before performing calculations.\n"
                << "2. Choose an operation:\n"
                << "   - [1] Add      → Adds the two numbers.\n"
                << "   - [2] Subtract → Subtracts the second number from the first.\n"
                << "   - [3] Multiply → Multiplies the two numbers.\n"
                << "   - [4] Divide   → Divides the first number by the second.\n"
                << "3. Division by zero is not allowed. You will be prompted to enter a valid number if necessary.\n"
                << "4. The result of each operation is stored as the first operand for further calculations.\n"
                << "5. After performing an operation, press Enter to return to the menu.\n"
                << "6. Use [5] to enter new numbers at any time.\n"
                << "7. Use [6] to view these instructions again.\n"
                << "8. Use [7] to exit the program.\n"
                << "***********************************\n";
                pauseAndClear();
                menu(a, b, result);
                return;
            case 7:
                cout << "Exiting program..." << endl;
                exit(0);
            default:
                cout << "Invalid option. Try again." << endl;
                pauseAndClear();
                menu(a, b, result);
        }
    }
};

int main() 
{
    Calculator::menu(0, 0, 0);
    return 0;
}
