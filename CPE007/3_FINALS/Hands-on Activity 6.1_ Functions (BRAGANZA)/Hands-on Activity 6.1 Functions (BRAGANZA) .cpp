#include <iostream>

double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    if (num2 == 0.0) {
        std::cout << "Denominator cannot be 0." << std::endl;
        return 0.0;
    }
    return num1 / num2;
}

const double CURRENT_RATE = 58.18;

double fahrToCels(double fahrenheit) {
    return (fahrenheit - 32.0) * (5.0 / 9.0);
}

double celsToFahr(double celsius) {
    return (celsius * (9.0 / 5.0)) + 32.0;
}

double dollarsToPesos(double amountUSD) {
    return amountUSD * CURRENT_RATE;
}

double pesosToDollars(double amountPHP) {
    return amountPHP / CURRENT_RATE;
}

void calculator_menu() {
    double num1, num2;
    int operation;

    std::cout << "\n------ Calculator ------" << std::endl;

    while (true) {
        std::cout << "Enter the first number: ";
        std::cin >> num1;
        if (!std::cin.fail()) {
            break;
        }
        std::cout << "Invalid input. Please enter a number." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    while (true) {
        std::cout << "Enter the second number: ";
        std::cin >> num2;
        if (!std::cin.fail()) {
            break;
        }
        std::cout << "Invalid input. Please enter a number." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    while (true) {
        std::cout << "Choose operation:" << std::endl;
        std::cout << "1. +" << std::endl;
        std::cout << "2. -" << std::endl;
        std::cout << "3. *" << std::endl;
        std::cout << "4. /" << std::endl;
        std::cout << "Enter choice (1-4): ";

        std::cin >> operation;
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (operation) {
            case 1:
                std::cout << "Result: " << num1 << " + " << num2 << " = " << add(num1, num2) << std::endl;
                return;
            case 2:
                std::cout << "Result: " << num1 << " - " << num2 << " = " << subtract(num1, num2) << std::endl;
                return;
            case 3:
                std::cout << "Result: " << num1 << " * " << num2 << " = " << multiply(num1, num2) << std::endl;
                return;
            case 4:
            {
                double result = divide(num1, num2);
                if (num2 != 0.0) {
                    std::cout << "Result: " << num1 << " / " << num2 << " = " << result << std::endl;
                }
                return;
            }
            default:
                std::cout << "Invalid operation selected. Please enter a number between 1 and 4." << std::endl;
        }
    }
}

void temperature_menu() {
    int choice;
    double temp;

    std::cout << "\n--- Temperature Converter ---" << std::endl;

    while (true) {
        std::cout << "1. Fahrenheit to Celsius" << std::endl;
        std::cout << "2. Celsius to Fahrenheit" << std::endl;
        std::cout << "Enter your choice (1 or 2): ";
		
		std::cin >> choice;
		if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1 || choice == 2) {
            break;
        } else {
            std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
        }
    }
    
    while (true) {
        if (choice == 1) {
            std::cout << "Enter temperature in Fahrenheit: ";
        } else {
            std::cout << "Enter temperature in Celsius: ";
        }

        std::cin >> temp;
        if (!std::cin.fail()) {
            break;
        }
        std::cout << "Invalid input. Please enter a number for the temperature." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    
    if (choice == 1) {
        std::cout << temp << " F is " << fahrToCels(temp) << " C" << std::endl;
    } else {
        std::cout << temp << " C is " << celsToFahr(temp) << " F" << std::endl;
    }
}

void currency_menu() {
    int choice;
    double amount;

    std::cout << "\n--- Currency Converter (Rate: 1 USD = " << CURRENT_RATE << " PHP) ---" << std::endl;

    while (true) {
        std::cout << "1. Dollars (USD) to Pesos (PHP)" << std::endl;
        std::cout << "2. Pesos (PHP) to Dollars (USD)" << std::endl;
        std::cout << "Enter your choice (1 or 2): ";

        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1 || choice == 2) {
            break;
        } else {
            std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
        }
    }

    while (true) {
        std::cout << "Enter the amount: ";
        std::cin >> amount;
        if (!std::cin.fail()) {
            break;
        }
        std::cout << "Invalid input. Please enter a number for the amount." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    switch (choice) {
        case 1:
            std::cout << "$" << amount << " USD is " << dollarsToPesos(amount) << " PHP" << std::endl;
            break;
        case 2:
            std::cout << amount << " PHP is $" << pesosToDollars(amount) << " USD" << std::endl;
            break;
        default:
             break;
    }
}

int main() {
    int choice = 0;

    do {
        std::cout << "\n===========================================" << std::endl;
        std::cout << "          	Main Menu" << std::endl;
        std::cout << "===========================================" << std::endl;
        std::cout << "1. Calculator Operations (ADD, SUB, DIV, MUL)" << std::endl;
        std::cout << "2. Temperature Conversion (F and C)" << std::endl;
        std::cout << "3. Currency Conversion (USD and PHP)" << std::endl;
        std::cout << "4. Exit Program" << std::endl;
        std::cout << "Enter your choice: ";

        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                calculator_menu();
                break;
            case 2:
                temperature_menu();
                break;
            case 3:
                currency_menu();
                break;
            case 4:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
                break;
        }
        
    } while (choice != 4);

    return 0;
}

