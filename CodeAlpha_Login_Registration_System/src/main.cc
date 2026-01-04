#include <iostream>
#include <fstream>

// UTILITY FUNCTIONS
int getInt(std::string message)
{
    while (true)
    {
        std::cout << message;
        std::string option;
        getline(std::cin, option);

        try
        {
            return stoi(option);
        }
        catch (...)
        {
            std::cout << "\nInvalid Input! Try again.";
        }
    }
}

bool validateUsername(std::string username) {
    bool userEsists = false;
}

// MAIN FUNCTONS
std::string registerUser (std::string username, std::string password) {

}

int main()
{
    while (true)
    {
        std::cout << "Welcome to this Login & Registration System" << std::endl;
        std::cout << "What can we do for you? "
                  << "\n1. Register"
                  << "\n2. Login"
                  << "\n3. Exit" << std::endl;
        int choice = getInt("\nYour option(1-3): ");
        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }

        std::cout << "\nDo you wish to perform another operation? (y/n): ";
        std::string choiceStr;
        getline(std::cin, choiceStr);

        if (choiceStr == "y")
        {
            std::cout << "" << std::endl;
            continue;
        }
        else if (choiceStr == "n")
        {
            std::cout << "\nThank you for using this console app. Exiting..." << std::endl;
            break;
        }
        else
        {
            std::cout << "\nInvalid option" << std::endl;
        }
    }

    return 0;
}
