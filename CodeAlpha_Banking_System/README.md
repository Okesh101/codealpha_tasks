# 🏦 Console Banking System (C++)

This project is a **console-based Banking System** developed in **C++** as part of **CodeAlpha – Task 4**.

It demonstrates how core banking operations can be implemented using **Object-Oriented Programming (OOP)**, standard C++ libraries, and clean program structure.

---

## 📌 Task Objective (CodeAlpha – Task 4)

The goal of this task was to:

- Design classes for **Customer**, **Account**, and **Transaction**
- Create and manage customer bank accounts
- Support **deposits, withdrawals, and fund transfers**
- Allow users to **view account details and balance**
- Store and display **transaction history**

✔ All required features have been implemented in this project.

---

## 🚀 Features Implemented

✔ Create new customer accounts  
✔ Automatically generate unique account numbers  
✔ Deposit money into an account  
✔ Withdraw money from an account  
✔ Transfer funds between accounts  
✔ View current account balance  
✔ View customer account details  
✔ View complete transaction history  
✔ Input validation for safe operations  
✔ Timestamped transaction records  

---

## 🛠 Technologies Used

- **Language:** C++ (C++17)
- **Build System:** CMake
- **Compiler:** GCC / Clang
- **Platform:** Linux / Windows (MinGW)

---

## ⚙️ Build & Run Instructions

#### Clone the Repository
```bash
git clone https://github.com/Okesh101/codealpha_tasks.git
cd codealpha_tasks
cd CodeAlpha_Banking_System
```

#### Build the Project
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

#### Run the Application 
##### On Linux
```bash
./BankingSystem
```

##### On Windows
```bash
BankingSystem.exe
```

## Available Operations
| Option | Action |
| --- | --- |
| 1	     | Create Account |
| 2	     | View Balance |
| 3	     | Deposit Money |
| 4	     | Withdraw Money |
| 5	     | Funds Transfer |
| 6	     | View Customer Information |
| 7	     | View Transaction History |
| 8	     | Exit |

---

## 🧠 Design Overview
### Core Classes ###

**Customer** → Stores personal customer details and is responsible for account creation.

**Account** → Manages account number and balance-related operations.

**Transaction** → Represents individual transactions, including amount, type, and timestamp.

### Generated Struct <br>

**BankAccount** → Combines customer data, account data, and transaction history into a single unit.

## 🗄 Data Storage

All data is stored in memory during program execution using:
```cpp
std::unordered_map<long int, BankAccount> bankDatabase;
```

---

## 🕒 Transaction Tracking

Each transaction stores:

Unique transaction ID

Date and time

Transaction type (deposit / withdrawal / transfer)

Transaction amount

Account balance after transaction

*This ensures transparent and accurate transaction history for every account.*

---


## ⚠️ Limitations

Data is not persisted (resets on program exit)

No user authentication (PIN / password)

No concurrency or multi-user support

---


## 🔮 Possible Improvements

File-based or database persistence

PIN or password authentication

Interest calculation on balances

Admin management features

Unit testing

Transaction filtering by date or type

---


## 👤 Author

**Goodluck** <br>
*C++ Intern at CodeAlpha* <br>
*Systems & Backend Programming Enthusiast*