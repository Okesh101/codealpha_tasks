# 🔐 Login and Registration System (C++)

This project is a **console-based Login and Registration System** developed in **C++** as part of **CodeAlpha Task 2**.

It demonstrates how user credentials can be securely registered, stored, and verified using basic C++ programming principles / concepts.

---

## 📌 Task Objective (CodeAlpha – Task 2)

The goal of this task was to:

- Create a **registration function** that accepts a username and password
- **Validate inputs** and prevent duplicate usernames
- **Store credentials securely** in a file or database
- Implement a **login system** that verifies user identity
- Display **clear success and error messages**

✔ All the above requirements have been implemented in this project.

---

## 🚀 Features Implemented

✔ User registration with username and password  
✔ Validation to prevent duplicate usernames  
✔ Strong password validation rules  
✔ Secure password storage using hashing  
✔ SQLite database for persistent storage  
✔ User login with credential verification  
✔ Clear success and error feedback  
✔ Continuous console interaction  

---

## 🛠 Technologies Used

- **Language:** C++ (C++17)
- **Database:** SQLite3
- **Build System:** CMake
- **Platform:** Linux / Windows

---

## ⚙️ Build & Run Instructions

### Clone the Repository
```bash
git clone https://github.com/Okesh101/codealpha_tasks.git
cd codealpha_tasks
cd CodeAlpha_Login_Registration_System
```

### Build the Project
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Run the Application
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

*After each operation, the user is asked whether to continue or exit.*

---

### 🗄 Data Storage

All user data is persisted using **SQLite**: <br>
Database File: `data/users.db` <br>
Table: `USERS`

Schema
```sql
ID INTEGER PRIMARY KEY AUTOINCREMENT
USERNAME TEXT UNIQUE NOT NULL
PASSWORDHASH TEXT NOT NULL
```
Passwords are never stored in plain text.

---

## 🔐 Password Rules

Passwords must contain:

Minimum of **8 characters**

At least **one uppercase letter**

At least **one lowercase letter**

At least **one digit**

*Weak passwords are rejected with descriptive error messages.*

---


## ⚠️ Notes & Limitations

Uses `std::hash` for password hashing (educational purposes)

No password recovery feature

Designed for single-user console interaction

---

## 👤 Author

**Goodluck** <br>
*C++ Intern at CodeAlpha* <br>
*Systems & Backend Programming Enthusiast*