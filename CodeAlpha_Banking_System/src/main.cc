#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <vector>
#include <unordered_set>
#include <unordered_map>

// STRUCTS
struct TransactionDetails
{
    int id;
    std::string transactionDate;
    std::string description;
    float amount;
    float balance;
};

struct CustomerDetails
{
    std::string name;
    int age;
    long int NIN;
    int accountNumber;
};

// CLASSES
class Customer
{
private:
    std::vector<int> AccountNumbers;
    std::unordered_set<int> accNumberSet;
    std::string firstname, surname;
    int age;
    long int NIN;

public:
    void setFirstname(std::string firstname)
    {
        this->firstname = firstname;
    }
    void setSurname(std::string surname)
    {
        this->surname = surname;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void setNIN(long int nin)
    {
        this->NIN = nin;
    }
    std::string getName()
    {
        std::string name = this->surname + " " + this->firstname;
        return name;
    }
    int getAge()
    {
        return this->age;
    }
    long int retrieveNIN()
    {
        return this->NIN;
    }
    bool accNumberExists(int accNumber)
    {
        return accNumberSet.find(accNumber) != accNumberSet.end();
    }
    int generateAccountNumber()
    {
        std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<> dis(0, 9);
        std::string accNumber;
        do
        {
            accNumber = "10";
            for (int i = 0; i < 8; i++)
            {
                accNumber += std::to_string(dis(gen));
            }
        } while (accNumberExists(stoi(accNumber)));
        AccountNumbers.push_back(stoi(accNumber));
        accNumberSet.insert(stoi(accNumber));

        return std::stoi(accNumber);
    }
};

class Account
{
private:
    long int account_number;
    float account_balance = 0; // Demo

public:
    void setAccNumber(int accNumber)
    {
        this->account_number = accNumber;
        this->account_balance = 10000; // Demo
    }
    void setAccBalance(float accBalance)
    {
        this->account_balance = accBalance;
    }
    long int getAccNumber()
    {
        return this->account_number;
    }
    float getAccBalance()
    {
        return this->account_balance;
    }
};

class Transaction
{
private:
    int id;
    std::string transactionDate;
    std::string description;
    float amount;
    float balance;

public:
    void setTransaction(int id, std::string transactionDate, std::string description, float amount, float balance)
    {
        this->id = id;
        this->transactionDate = transactionDate;
        this->description = description;
        this->amount = amount;
        this->balance = balance;
    }
    TransactionDetails getTransactionDetails()
    {
        return {id, transactionDate, description, amount, balance};
    };
};

// STRUCT
struct BankAccount
{
    CustomerDetails customerDetails;
    Account account;
    std::vector<Transaction> transactions;
};

// GLOBAL VARIABLES
std::unordered_map<long int, BankAccount> bankDatabase;

// UTILITY FUNCTIONS
bool accountExists(long int accNumber)
{
    return bankDatabase.find(accNumber) != bankDatabase.end();
}

int getInt(const std::string &prompt)
{
    while (true)
    {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);

        try
        {
            return std::stoi(input);
        }
        catch (...)
        {
            std::cout << "Invalid input. Try again.\n";
        }
    }
}

long int getLong(const std::string &prompt)
{
    while (true)
    {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);

        try
        {
            return std::stoll(input);
        }
        catch (...)
        {
            std::cout << "Invalid input. Try again.\n";
        }
    }
}

std::string getCurrentDateTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm localTime{};
    localtime_r(&now_c, &localTime); // Linux / macOS

    std::ostringstream oss;
    oss << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");

    return oss.str();
}

// SWITCH FUNCTIONS
void CreateAccount()
{
    Customer customer;
    Account account;

    std::string surname, firstname;
    int age = 0;
    long int NIN;
    std::cout << "\n\nYou are welcome to this banking system!"
                << "\nKindly provide us with some of your details"
                << "\n\nEnter your last name (surname): ";
    getline(std::cin, surname);
    std::cout << "\nEnter your first name: ";
    getline(std::cin, firstname);
    while (age < 18)
    {
        age = getInt("\nEnter your age: ");
        if (age < 18)
        {
            std::cout << "I'm sorry, you are not allowed to create an account yet." << std::endl;
        }
    }
    NIN = getLong("\nEnter your NIN no: ");

    // Setting customer details
    customer.setSurname(surname);
    customer.setFirstname(firstname);
    customer.setAge(age);
    customer.setNIN(NIN);
    long int accountNumber = customer.generateAccountNumber();
    account.setAccNumber(accountNumber);

    // Saving Customer Details
    CustomerDetails details;
    details.name = customer.getName();
    details.age = customer.getAge();
    details.NIN = customer.retrieveNIN();
    details.accountNumber = accountNumber;
    // details.accountBalance = account.getAccBalance();

    std::vector<Transaction> transactionList;

    bankDatabase[accountNumber] = {details, account, transactionList};

    std::cout << "\nAccount created successfully!";
    std::cout << "\nAccount Number: " << accountNumber << std::endl;
}

void BalanceEnquiry()
{
    std::string accNumber;
    std::cout << "\nEnter account number: ";
    getline(std::cin, accNumber);

    if (!accountExists(std::stoi(accNumber)))
    {
        std::cout << "Invalid account number!" << std::endl;
        return;
    }

    BankAccount &bankAcc = bankDatabase[stoi(accNumber)];
    std::cout << "\nAccount Balance: " << bankAcc.account.getAccBalance() << std::endl;
}

void DepositFund() {
    long int accNumber = getLong("\nEnter account number: ");

    if (!accountExists(accNumber))
    {
        std::cout << "Invalid account number!" << std::endl;
        return;
    }

    float depositAmount = getLong("\nEnter amount to deposit: ");
    
    BankAccount &bankAcc = bankDatabase[accNumber];
    float currentBalance = bankAcc.account.getAccBalance();
    bankAcc.account.setAccBalance(currentBalance + depositAmount);
    
    int newTransactionId = bankAcc.transactions.size() + 1;
    Transaction transaction;
    transaction.setTransaction(newTransactionId, getCurrentDateTime(), "Deposit", depositAmount, currentBalance + depositAmount);
    bankAcc.transactions.push_back(transaction);

    std::cout << "Amount " << depositAmount << " successfully deposited into account!" << std::endl;
}

void Withdrawal()
{
    long accNum = getLong("\nPlease enter your account number: ");

    float accBalance = bankDatabase[accNum].account.getAccBalance();
    std::cout << "Your account balance: " << accBalance;

    long int withdrawalAmount = getInt("\nPlease enter how much you'll like to withdraw: ");

    if (withdrawalAmount > accBalance)
    {
        std::cout << "\nInsufficient funds!" << std::endl;
    }

    bankDatabase[accNum].account.setAccBalance(accBalance - withdrawalAmount);

    int newTransactionId = bankDatabase[accNum].transactions.size() + 1;

    Transaction transaction;
    transaction.setTransaction(newTransactionId, getCurrentDateTime(), "Withdrawal", withdrawalAmount, accBalance - withdrawalAmount);
    bankDatabase[accNum].transactions.push_back(transaction);

    std::cout << "\nYou have successfully withdrawn " << withdrawalAmount << ". \nYour account balance is: " << bankDatabase[accNum].account.getAccBalance();
}

void Transfer()
{
    long int accNumber = getLong("\nEnter account number: ");

    if (!accountExists(accNumber))
    {
        std::cout << "Invalid account number!" << std::endl;
        return;
    }

    BankAccount &bankAcc = bankDatabase[accNumber];
    float senderBal = bankAcc.account.getAccBalance();
    std::cout << "Your available balance: " << senderBal;

    long int recAccNumber = getLong("\nEnter reciepient's account number: ");

    if (!accountExists(recAccNumber))
    {
        std::cout << "Invalid account number!" << std::endl;
        return;
    }

    BankAccount &recBankAcc = bankDatabase[recAccNumber];
    float recAccBalance = recBankAcc.account.getAccBalance();

    std::cout << "\n"
              << recBankAcc.customerDetails.name << std::endl;

    float amount = getLong("\nEnter amount to transfer: ");

    // Depositing Reciepient Account
    recBankAcc.account.setAccBalance(recAccBalance + amount);
    int newTransactionId = bankDatabase[recAccNumber].transactions.size() + 1;
    Transaction transaction;
    transaction.setTransaction(newTransactionId, getCurrentDateTime(), "Deposit", amount, recAccBalance + amount);
    recBankAcc.transactions.push_back(transaction);

    // Deducting Sender Account
    bankAcc.account.setAccBalance(senderBal - amount);
    int newTransactionId2 = bankDatabase[accNumber].transactions.size() + 1;
    Transaction transaction2;
    transaction2.setTransaction(newTransactionId2, getCurrentDateTime(), "Fund Transfer", amount, senderBal - amount);
    bankAcc.transactions.push_back(transaction2);

    std::cout << "Fund successfully sent to " << recBankAcc.customerDetails.name << std::endl;
}

void CustomerInfo()
{
    long int accNumber = getLong("\nEnter account number: ");

    if (!accountExists(accNumber))
    {
        std::cout << "Account not found!" << std::endl;
        return;
    }

    BankAccount &bankAcc = bankDatabase[accNumber];
    CustomerDetails &info = bankAcc.customerDetails;

    std::cout << "\nAccount Number: " << info.accountNumber;
    std::cout << "\nOwner's Name: " << info.name;
    std::cout << "\nOwner's Age: " << info.age;
    std::cout << "\nOwner's NIN: " << info.NIN;
    std::cout << "\nAccount Balance: " << bankAcc.account.getAccBalance() << std::endl;
}

void TransactionHistory()
{
    long int accNumber = getLong("\nEnter account number: ");

    if (!accountExists(accNumber))
    {
        std::cout << "Account not found!" << std::endl;
        return;
    }

    BankAccount &bankAcc = bankDatabase[accNumber];

    for (Transaction &txn : bankAcc.transactions)
    {
        TransactionDetails history = txn.getTransactionDetails();
        std::cout << "\nTransaction ID: " << history.id;
        std::cout << "\nTransaction Date: " << history.transactionDate;
        std::cout << "\nTransaction Description: " << history.description;
        std::cout << "\nTransaction Amount: " << history.amount;
        std::cout << "\nBalance: " << history.balance << std::endl;
    }
}

// MAIN FUNCTION
int main()
{
    while (true)
    {
        std::cout << "\n\nWelcome to the Banking System!" << std::endl;
        std::cout << "What will you like to do today? "
                    << "\n1. Create Account"
                    << "\n2. View Balance"
                    << "\n3. Deposit Money"
                    << "\n4. Withdraw Money"
                    << "\n5. Funds Transfer"
                    << "\n6. View Customer Info"
                    << "\n7. Print Transaction History" 
                    << "\n8. Exit" << std::endl;

        int choice = getInt("\n\n Your option (1-8): ");

        switch (choice)
        {
        case 1:
            CreateAccount();
            break;
        case 2:
            BalanceEnquiry();
            break;
        case 3:
            DepositFund();
            break;
        case 4:
            Withdrawal();
            break;
        case 5:
            Transfer();
            break;
        case 6:
            CustomerInfo();
            break;
        case 7:
            TransactionHistory();
            break;
        case 8:
            std::cout << "\nThank you for using this Banking System. Exiting..." << std::endl;
            break;
        default:
            std::cout << "\nInput entered is not part of the options! \nTry again." << std::endl;
            continue;
            // break;
        }

        std::cout << "\nDo you wish to perform another operation? (y/n)" << std::endl;
        std::cout << "Your option (y/n): ";
        std::string choiceChar;
        getline(std::cin, choiceChar);

        if (choiceChar == "y")
        {
            continue;
        }
        else
        {
            break;
        }
    }

    return 0;
}
