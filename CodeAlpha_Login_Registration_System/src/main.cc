#include <iostream>
#include <fstream>
#include <functional>
#include <sqlite3.h>

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

std::string hashPassword(std::string &password)
{
    std::hash<std::string> hasher;
    return std::to_string(hasher(password));
}

std::string createUsersTable(const std::string &tableName, const std::string &dbName)
{
    sqlite3 *db;
    char *errMsg = 0;
    int rc = sqlite3_open(dbName.c_str(), &db);

    if (rc)
    {
        return "Can't open database: " + std::string(sqlite3_errmsg(db));
    }

    std::string sql = "CREATE TABLE IF NOT EXISTS " + tableName + " ("
                                                                  "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                                                                  "USERNAME TEXT NOT NULL UNIQUE,"
                                                                  "PASSWORDHASH TEXT NOT NULL);";

    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        std::string errorMsg = "SQL error in creating table: " + std::string(errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return errorMsg;
    }
    else
    {
        sqlite3_close(db);
        // std::cout << "Table '" << tableName << "' created successfully" << std::endl;
        return "success";
    }
}

std::string addUser(const std::string &dbName, const std::string &tableName, const std::string &username, const std::string &passwordHash)
{
    sqlite3 *db;
    char *errMsg = 0;
    int rc = sqlite3_open(dbName.c_str(), &db);

    if (rc)
    {
        return "Can't open database: " + std::string(sqlite3_errmsg(db));
    }

    std::string sql = "INSERT INTO " + tableName + " (USERNAME, PASSWORDHASH) VALUES ('" + username + "', '" + passwordHash + "');";

    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        std::string errorMsg = "SQL error in adding user details: " + std::string(errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return errorMsg;
    }
    else
    {
        sqlite3_close(db);
        return "success";
    }
}

bool validateUsername(std::string username, std::string tableName = "USERS")
{
    bool userExists = false;
    std::string dbName = "data/users.db";
    sqlite3 *db;
    char *errMsg = 0;
    int rc = sqlite3_open(dbName.c_str(), &db);
    if (rc)
    {
        std::cout << "\nCan't open database: " << sqlite3_errmsg(db) << std::endl;
        return userExists;
    }
    std::string sql = "SELECT USERNAME FROM " + tableName + " WHERE USERNAME = '" + username + "';";

    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        // userExists = true;
        // std::cout << "\nSQL error in validating username: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return userExists;
    }
    if (rc == SQLITE_ROW)
    {
        userExists = true;
        // std::cout << "\nUsername already exists. Please choose a different username." << std::endl;
    }
    else
    {
        userExists = false;
    }

    sqlite3_close(db);
    return userExists;
}

std::string retrieveUserCredentials(const std::string dbName, const std::string tableName, const std::string username)
{
    sqlite3 *db;
    char *errMsg = 0;
    std::string passwordHash;
    int rc = sqlite3_open(dbName.c_str(), &db);

    if (rc)
    {
        return "Can't open database: " + std::string(sqlite3_errmsg(db));
    }

    std::string sql = "SELECT PASSWORDHASH FROM " + tableName + " WHERE USERNAME = '" + username + "';";

    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        sqlite3_close(db);
        return "Failed to execute statement: " + std::string(sqlite3_errmsg(db));
    }

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW)
    {
        passwordHash = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
    }
    else
    {
        passwordHash = "";
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return passwordHash;
}

// MAIN FUNCTONS
std::string registerUser(std::string &username, std::string &password)
{
    const std::string dbName = "data/users.db";
    const std::string tableName = "USERS";

    std::string tableCreationStatus = createUsersTable(tableName, dbName);
    if (tableCreationStatus != "success")
    {
        return tableCreationStatus;
    }

    std::string passwordHash = hashPassword(password);
    std::string addUserStatus = addUser(dbName, tableName, username, passwordHash);
    if (addUserStatus != "success")
    {
        if (addUserStatus.find("UNIQUE constraint failed") != std::string::npos)
        {
            return "Username already exists. Please choose a different username.";
        }
        return addUserStatus;
    }
    std::cout << "\nUser details added successfully" << std::endl;
    // saveFile(username, password);
    return "Registration successful!";
}

std::string loginUser(std::string &username, std::string &password)
{
    std::string dbName = "data/users.db";
    std::string tableName = "USERS";
    std::string storedPasswordHash = retrieveUserCredentials(dbName, tableName, username);
    if (storedPasswordHash.find("Error") != std::string::npos || storedPasswordHash.empty())
    {
        return "Invalid credentials.";
    } else {
        std::string inputPasswordHash = hashPassword(password);
        if (inputPasswordHash == storedPasswordHash)
        {
            // std::string userData = readFile(username);
            return "\nLogin successful!";
        }
        else
        {
            return "\nInvalid credentials.";
        }
    }
}

// CASE FUNCTIONS
void Register()
{
    std::string username;
    std::string password;

    std::cout << "\n--- Register ---" << std::endl;
    std::cout << "Enter username: ";
    getline(std::cin, username);

    while (true)
    {
        if (validateUsername(username))
        {
            std::cout << "\nUsername already exists. Please choose a different username." << std::endl;
        }
        std::cout << "\nEnter password: ";
        getline(std::cin, password);

        if (password.length() < 8)
        {
            std::cout << "\nPassword must be at least 8 characters long.";
            continue;
        }
        if (!std::any_of(password.begin(), password.end(), ::isdigit))
        {
            std::cout << "\nPassword must contain at least one number.";
            continue;
        }
        if (!std::any_of(password.begin(), password.end(), ::isupper))
        {
            std::cout << "\nPassword must contain at least one uppercase letter.";
            continue;
        }
        if (!std::any_of(password.begin(), password.end(), ::islower))
        {
            std::cout << "\nPassword must contain at least one lowercase letter.";
            continue;
        }
        break;
    }
    std::cout << registerUser(username, password) << std::endl;
}

void Login()
{
    std::string username;
    std::string password;

    std::cout << "\n--- Login ---" << std::endl;
    std::cout << "Enter username: ";
    getline(std::cin, username);
    std::cout << "\nEnter password: ";
    getline(std::cin, password);

    std::cout << loginUser(username, password) << std::endl;
}

// ENTRY CODE
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
            Register();
            break;
        case 2:
            Login();
            break;
        case 3:
            std::cout << "\nThank you for using this console app. Exiting..." << std::endl;
            break;
        default:
            break;
        }

        std::cout << "\nDo you wish to perform another operation? (y/n): ";
        std::string choiceStr;
        getline(std::cin, choiceStr);

        if (std::tolower(choiceStr[0]) == 'y')
        {
            std::cout << "" << std::endl;
            continue;
        }
        else if (std::tolower(choiceStr[0]) == 'n')
        {
            std::cout << "\nThank you for using this console app. Exiting..." << std::endl;
            break;
        }
        else
        {
            std::cout << "\nInvalid option" << std::endl;
            break;
        }
    }

    return 0;
}
