# 🎓 CGPA Calculator (C++)

This project is a **console-based CGPA Calculator** developed in **C++** as part of **CodeAlpha – Task 1**.

It demonstrates how **academic performance calculations (GPA & CGPA)** can be implemented using **Object-Oriented Programming (OOP)** principles, standard C++ libraries, and a clean, structured console interface.

---

## 📌 Task Objective (CodeAlpha – Task 1)

The goal of this task was to:

- Take input for the **number of courses** taken by a student
- For each course, input the **course code**, **grade**, and **credit hours**
- Calculate **total credit units** and **total grade points**
- Compute the **GPA** for each semester
- Compute the overall **CGPA** for an academic session
- Display individual **course grades**, **semester GPA**, and **final CGPA**

✔ All required features have been implemented in this project.

---

## 🚀 Features Implemented

✔ Menu-driven console interface  
✔ GPA calculation for a single semester  
✔ CGPA calculation across multiple semesters  
✔ Automatic grouping of semesters into **academic years**  
✔ Credit-weighted grade point calculation  
✔ Input validation for grades and credit units  
✔ Clean, readable output formatting  
✔ Continuous operation until user exits  

---

## 🛠 Technologies Used

- **Language:** C++ (C++17)
- **Compiler:** GCC / Clang
- **Platform:** Linux / Windows

---

## ⚙️ Build & Run Instructions

#### Clone the Repository
```bash
git clone https://github.com/Okesh101/codealpha_tasks.git
cd codealpha_tasks
cd CodeAlpha_CGPA_Calculator
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
./CGPACalculator
```

##### On Windows
```bash
CGPACalculator.exe
```

## Available Operations
| Option | Action |
| --- | --- |
| 1	     | Calculate GPA (Single Semester) |
| 2	     | Calculate CGPA (Multiple Semesters) |
| 3	     | Exit Application |

---

## 🧠 Program Design Overview

### Core Components

#### **Course**
- Stores course grade and credit unit  
- Computes individual grade points  

#### **Semester**
- Holds multiple courses  
- Calculates semester GPA  

#### **AcademicSession**
- Groups semesters into academic years  
- Computes overall CGPA  

The program intelligently infers the **number of academic years** based on the total number of semesters  
*(2 semesters = 1 academic year)*.

---

## 🧮 CGPA Calculation Logic

- **Grade Point** = Grade Value × Credit Unit  
- **Semester GPA** = Total Grade Points ÷ Total Credit Units  
- **CGPA** = Sum of all Grade Points ÷ Sum of all Credit Units  

This ensures accurate, standard-compliant academic results.

---

## ⚠️ Limitations

- Data is not saved after program exits  
- No file or database persistence  
- Grade scale is fixed (can be extended)

---

## 🔮 Possible Improvements

- File-based or database storage  
- Custom grading scales  
- PDF or transcript export  
- GUI version  
- Unit testing

---

## 👤 Author

**Goodluck**  
*C++ Intern at CodeAlpha*  
*Systems & Backend Programming Enthusiast*