# 🏦 Console Banking System (C++)

A simple **console-based banking system** built with **modern C++**, demonstrating core programming concepts such as:

- Object-Oriented Programming (OOP)
- STL containers (`vector`, `unordered_map`, `unordered_set`)
- Input validation
- Transaction history management
- Date & time handling
- Modular program design

This project simulates basic banking operations and is suitable for **learning, practice, and portfolio demonstration**.

---

## 🚀 Features

✔ Create a new bank account  
✔ Automatically generate unique account numbers  
✔ Deposit money  
✔ Withdraw money  
✔ Transfer funds between accounts  
✔ View account balance  
✔ View customer information  
✔ View complete transaction history  
✔ Robust input validation  
✔ Timestamped transactions  

---

## 🧱 Project Structure

.
├── main.cpp
├── CMakeLists.txt
└── README.md


---

## 🛠 Technologies Used

- **Language:** C++ (C++17)
- **Build System:** CMake
- **Compiler:** GCC / Clang
- **Platform:** Linux / macOS / Windows (with MinGW)

---

## ⚙️ Build & Run Instructions

### 1️⃣ Clone the Repository
```bash
git clone https://github.com/Okesh101/console-banking-system.git
cd console-banking-system

# Create Build Directory
mkdir build
cd build

# Build with CMake
cmake ..
cmake --build .

# Run the Program
./BankingSystem

# On Windows
BankingSystem.exe
```

## Available Operations
Option	Action
1	    Create Account
2	    View Balance
3	    Deposit Money
4	    Withdraw Money
5	    Funds Transfer
6	    View Customer Info
7	    Print Transaction History
8	    Exit

## 🧠 Design Overview
**Core Structures**

**Customer** → Personal data & account creation

**Account** → Balance management

**Transaction** → Individual transaction records

**BankAccount** → Aggregates customer, account, and transactions

## Storage

All data is stored in-memory using:
```bash
std::unordered_map<long int, BankAccount> bankDatabase;
```

## 🕒 Transaction Tracking

Each transaction stores:

Unique ID

Timestamp

Description

Amount

Account balance after transaction

Transactions are stored per account, allowing accurate history retrieval.

## ⚠️ Limitations

Data is not persisted (resets on program exit)

No authentication (PIN / password)

No concurrency support

## 🔮 Future Improvements

File-based or database persistence

PIN-based authentication

Interest calculation

Admin dashboard

Unit tests

Transaction filtering (date / type)

## 👤 Author

Goodluck
C++ Developer & Systems Programming Enthusiast