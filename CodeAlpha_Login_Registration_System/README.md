# 🔐 Console Authentication System (C++)

A simple **console-based authentication system** built with **modern C++**, designed to demonstrate real-world concepts such as:

- Secure user registration & login
- SQLite database integration
- Password hashing
- Input validation
- Error handling
- Modular program structure

This project is suitable for **learning**, **practice**, and **portfolio demonstration**, especially for developers exploring **systems programming and backend fundamentals in C++**.

---

## 🚀 Features

✔ User registration  
✔ Secure password hashing  
✔ User login authentication  
✔ SQLite database persistence  
✔ Automatic database & table creation  
✔ Username uniqueness validation  
✔ Strong password enforcement  
✔ Robust input validation  
✔ Clear and descriptive error messages  
✔ Continuous user interaction flow  

---

## 🛠 Technologies Used

- **Language:** C++ (C++17)
- **Database:** SQLite3
- **Build System:** CMake
- **Compiler:** GCC / Clang
- **Platform:** Linux / macOS / Windows (with MinGW)

---

## ⚙️ Build & Run Instructions

### Clone the Repository
```bash
git clone https://github.com/Okesh101/codealpha_tasks.git
cd codealpha_tasks
cd CodeAlpha_Login_Registration_System
```

### Create Build Directory
```bash
mkdir build
cd build
```

### Build with CMake
```bash
cmake ..
cmake --build .
```

### Run the Program 
#### On Linux
```bash
./AuthenticationSystem
```

#### On Windows
```bash
AuthenticationSystem.exe
```

## Available Operations
| Option | Action |
| --- | --- |
| 1	     | Register a new user |
| 2	     | Login with existing credentials |
| 3	     | Exit the program |

---

## 🧠 Design Overview
### Core Responsibilities ###

#### Input Utilities ####
Handles safe and validated user input using `getline` and exception handling.

#### Security Layer ####
Passwords are hashed using `std::hash` before storage to avoid plain-text credentials.

#### Database Layer ####
Uses SQLite3 for persistent storage
Automatically creates the database directory and users table
Prepared statements prevent SQL injection

#### UI Layer ####
Clearly structured prompts and user-friendly messages guide the user through each operation.

## 🗄 Data Storage

All user data is persisted using **SQLite**: <br>
Database File: `data/users.db` <br>
Table: `USERS`

Schema
```sql
ID INTEGER PRIMARY KEY AUTOINCREMENT
USERNAME TEXT UNIQUE NOT NULL
PASSWORDHASH TEXT NOT NULL
```
This ensures that data remains available across program restarts.

---

## 🔐 Password Rules

Passwords must contain:

Minimum of **8 characters**

At least **one uppercase letter**

At least **one lowercase letter**

At least **one digit**

*Weak passwords are rejected with clear guidance.*

---


## ⚠️ Limitations

Uses `std::hash` (not suitable for production-grade security)

No password recovery mechanism

No account lockout after repeated failures

Single-user console interaction only

---


## 🔮 Future Improvements

Replace `std::hash` with bcrypt / Argon2

Password reset functionality

Account lockout on multiple failed logins

Role-based access (admin / user)

Logging system

Unit and integration tests

Separation into multiple source files

---


## 👤 Author

**Goodluck** <br>
*C++ Developer & Systems Programming Enthusiast* <br>
*An Intern at CodeAlpha*