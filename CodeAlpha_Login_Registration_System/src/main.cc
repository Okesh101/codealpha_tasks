#include <iostream>
#include <fstream>
#include <functional>
#include <sqlite3.h>
#include <algorithm>
#include <cctype>
#include <filesystem>

using namespace std;

// ===================== CONSTANTS =====================
const string DB_DIR = "data";
const string DB_NAME = "data/users.db";
const string TABLE = "USERS";

// ===================== INPUT UTILITIES =====================
int getInt(const string &message)
{
    while (true)
    {
        cout << message;
        string input;
        getline(cin, input);

        try
        {
            return stoi(input);
        }
        catch (...)
        {
            cout << "\n[Input Error] Please enter a valid number.\n";
        }
    }
}

string getString(const string &message)
{
    cout << message;
    string input;
    getline(cin, input);
    return input;
}

// ===================== SECURITY =====================
string hashPassword(const string &password)
{
    hash<string> hasher;
    return to_string(hasher(password));
}

// ===================== FILESYSTEM =====================
void ensureDatabaseDirectory()
{
    if (!filesystem::exists(DB_DIR))
    {
        filesystem::create_directory(DB_DIR);
    }
}

// ===================== DATABASE CORE =====================
bool openDatabase(sqlite3 *&db, string &error)
{
    ensureDatabaseDirectory();

    if (sqlite3_open(DB_NAME.c_str(), &db) != SQLITE_OK)
    {
        error = sqlite3_errmsg(db);
        return false;
    }
    return true;
}

string createUsersTable()
{
    sqlite3 *db;
    char *errMsg = nullptr;
    string error;

    if (!openDatabase(db, error))
        return "Database open failed: " + error;

    string sql =
        "CREATE TABLE IF NOT EXISTS USERS ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
        "USERNAME TEXT UNIQUE NOT NULL,"
        "PASSWORDHASH TEXT NOT NULL);";

    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK)
    {
        string err = errMsg;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return "Table creation failed: " + err;
    }

    sqlite3_close(db);
    return "success";
}

bool validateUsername(const string &username)
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    string error;

    if (!openDatabase(db, error))
        return false;

    string sql = "SELECT 1 FROM USERS WHERE USERNAME = ?;";
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

    bool exists = (sqlite3_step(stmt) == SQLITE_ROW);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return exists;
}

string addUser(const string &username, const string &passwordHash)
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    string error;

    if (!openDatabase(db, error))
        return "Database open failed: " + error;

    string sql =
        "INSERT INTO USERS (USERNAME, PASSWORDHASH) VALUES (?, ?);";

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, passwordHash.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
        string err = sqlite3_errmsg(db);
        sqlite3_finalize(stmt);
        sqlite3_close(db);

        return "Registration failed: " + err +
               "\nPossible reasons:\n"
               "- Username already exists\n"
               "- Database file is locked\n"
               "- Insufficient file permissions";
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return "success";
}

string retrieveUserCredentials(const string &username)
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    string error;

    if (!openDatabase(db, error))
        return "";

    string sql =
        "SELECT PASSWORDHASH FROM USERS WHERE USERNAME = ?;";

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

    string hash = "";
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        hash = reinterpret_cast<const char *>(
            sqlite3_column_text(stmt, 0));
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return hash;
}

// ===================== MAIN FUNCTIONS =====================
string registerUser(string &username, string &password)
{
    string tableStatus = createUsersTable();
    if (tableStatus != "success")
        return "[System Error] " + tableStatus;

    if (validateUsername(username))
        return "[Validation Error] Username already exists. Please choose another.";

    string result = addUser(username, hashPassword(password));
    if (result != "success")
        return result;

    return "Registration successful! You can now log in.";
}

string loginUser(string &username, string &password)
{
    string storedHash = retrieveUserCredentials(username);

    if (storedHash.empty())
        return "[Login Failed] Username not found.";

    if (hashPassword(password) != storedHash)
        return "[Login Failed] Incorrect password.";

    return "Login successful! Welcome back.";
}

// ===================== UI OPERATIONS =====================
void Register()
{
    cout << "\n--- USER REGISTRATION ---\n";

    string username = getString("Enter username: ");
    string password;

    while (true)
    {
        password = getString("Enter password: ");

        if (password.length() < 8 ||
            !any_of(password.begin(), password.end(), ::isdigit) ||
            !any_of(password.begin(), password.end(), ::isupper) ||
            !any_of(password.begin(), password.end(), ::islower))
        {
            cout << "\n[Password Weak]\n"
                 << "- Minimum 8 characters\n"
                 << "- At least one uppercase letter\n"
                 << "- At least one lowercase letter\n"
                 << "- At least one number\n\n";
            continue;
        }
        break;
    }

    cout << "\n"
         << registerUser(username, password) << endl;
}

void Login()
{
    cout << "\n--- USER LOGIN ---\n";

    string username = getString("Username: ");
    string password = getString("Password: ");

    cout << "\n"
         << loginUser(username, password) << endl;
}

// ===================== MAIN =====================
int main()
{
    cout << "Welcome to this Login & Registration System\n";

    while (true)
    {
        cout << "\nWhat would you like to do?\n"
             << "1. Register\n"
             << "2. Login\n"
             << "3. Exit\n";

        int choice = getInt("Your option (1-3): ");

        if (choice == 1)
            Register();
        else if (choice == 2)
            Login();
        else if (choice == 3)
        {
            cout << "\nThank you for using the system. Goodbye!\n";
            break;
        }
        else
        {
            cout << "\n[Input Error] Invalid menu option.\n";
        }

        string cont = getString(
            "\nDo you want to perform another operation? (y/n): ");

        if (cont != "y" && cont != "Y")
        {
            cout << "\nSession ended. Stay safe!\n";
            break;
        }
    }
}