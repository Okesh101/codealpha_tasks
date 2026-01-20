![CodeAlpha Logo](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSDUJ4bm5p1jeqH0dyOXgsDxZnL5uOAMI5RyQ&s)

# 🚀 CodeAlpha C++ Internship Projects

This repository contains **three complete C++ console applications** developed as part of the **CodeAlpha C++ Internship Program**.

Each project addresses a specific task assigned by CodeAlpha and demonstrates strong understanding of **Object-Oriented Programming (OOP)**, **file handling**, **program structure**, and **user interaction** using **modern C++**.

---

## 📂 Repository Structure

<!-- Structure -->
```
codealpha_tasks/
├── CodeAlpha_CGPA_Calculator/
│ ├── src/
│ ├── CMakeLists.txt
│ └── README.md
│
├── CodeAlpha_Login_Registration_System/
│ ├── src/
│ ├── CMakeLists.txt
│ └── README.md
│
├── CodeAlpha_Banking_System/
│ ├── src/
│ ├── CMakeLists.txt
│ └── README.md
|
├── .gitignore
└── README.md <-- (This file)
```

Each project folder contains:
- Complete source code
- Its own `CMakeLists.txt`
- A **project-specific README** explaining implementation details

---

## ✅ Task 1: CGPA Calculator

📁 **Project Folder:** `CodeAlpha_CGPA_Calculator`

### 🎯 Task Description
The CGPA Calculator computes a student's academic performance across multiple semesters.

### ✔ Features Implemented
- Input number of courses per semester
- Input grade and credit unit for each course
- Automatic calculation of:
  - Total credit units
  - Total grade points
  - Semester GPA
  - Overall CGPA
- Display of:
  - Individual course grades
  - Semester GPA
  - Final CGPA
- Intelligent grouping of semesters into academic years  
  *(2 semesters = 1 academic year)*

✔ Fully meets **CodeAlpha Task 1 requirements**

---

## ✅ Task 2: Login and Registration System

📁 **Project Folder:** `CodeAlpha_Login_Registration_System`

### 🎯 Task Description
A basic authentication system that allows users to register and log in securely.

### ✔ Features Implemented
- User registration with:
  - Username
  - Password validation
- Prevention of duplicate usernames
- Secure storage of credentials using file handling
- Login verification against stored credentials
- Clear success and error feedback messages

✔ Fully meets **CodeAlpha Task 2 requirements**

---

## ✅ Task 4: Banking System

📁 **Project Folder:** `CodeAlpha_Banking_System`

### 🎯 Task Description
A console-based banking application simulating real-world banking operations.

### ✔ Features Implemented
- Object-oriented design using:
  - `Customer`
  - `Account`
  - `Transaction`
- Create and manage bank accounts
- Deposit and withdraw funds
- Transfer funds between accounts
- View account balance
- Display customer account details
- View complete transaction history with timestamps
- Input validation for all operations

✔ Fully meets **CodeAlpha Task 4 requirements**

---

## 🛠 Technologies Used

- **Language:** C++ (C++17)
- **Programming Paradigm:** Object-Oriented Programming (OOP)
- **Build System:** CMake
- **Compiler:** GCC / Clang / MSVC
- **Platform:** Linux / Windows

---

## ⚙️ How to Build Any Project

```bash
cd <Project_Folder>
mkdir build
cd build
cmake ..
cmake --build .
```

Run the generated executable from the `build` directory.

---

## 🎯 Learning Outcomes

Through these projects, the following concepts were applied:

- C++ class design and encapsulation  
- File handling for persistent storage  
- Modular program structure  
- Input validation and error handling  
- Menu-driven console applications  
- Real-world problem modeling using C++

---

## 👤 Author

**Goodluck**  
*C++ Intern at CodeAlpha*  
*Systems & Backend Programming Enthusiast*

---

## 🏁 Acknowledgement

Special thanks to **CodeAlpha** for providing practical, skill-focused tasks that encourage real-world software development using **C++**.