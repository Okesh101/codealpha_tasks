#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

// UTILITY FUBCTIONS
int getInt(const std::string &prompt)
{
    while (true)
    {
        std::string input;
        std::cout << prompt;
        getline(std::cin, input);
        try
        {
            return std::stoi(input);
        }
        catch (...)
        {
            std::cout << "Invalid input! Try again.\n";
        }
    }
}

std::string getString(const std::string &prompt)
{
    std::string input;
    std::cout << prompt;
    getline(std::cin, input);
    return input;
}

char getChar(const std::string &prompt)
{
    while (true)
    {
        std::string input;
        std::cout << prompt;
        getline(std::cin, input);
        try
        {
            char c = input[0];
            return c;
        }
        catch (...)
        {
            std::cout << "Invalid input! Try again.\n";
        }
    }
}

bool performOperation()
{
    std::cout << "\nWill you like to perform another calculation?" << std::endl;
    std::string choiceChar = getString("Enter your option (y/n): ");
    if (choiceChar == "y" || choiceChar == "Y")
    {
        return true;
    }
    else if (choiceChar == "n" || choiceChar == "N")
    {
        std::cout << "\nThank you for using the console app. Exiting...\n"
                  << std::endl;
        return false;
    }
    else
    {
        std::cout << "\nInvalid choice!" << std::endl;
        return false;
    }
}

std::string returnSuffix(int j)
{
    switch (j)
    {
    case 1:
        return "st";
        break;
    case 2:
        return "nd";
        break;
    case 3:
        return "rd";
        break;
    default:
        return "th";
        break;
    }
}

int getAcademicYears(int semesters)
{
    if (semesters == 1)
        return 1;
    else if (semesters % 2 != 0)
        return (semesters / 2) + 1;
    else
        return semesters / 2;
}

// POLYMORPHISM APPLICATION
int convertGrade(const char &grade)
{
    if (grade == 'A' || grade == 'a')
    {
        return 5;
    }
    else if (grade == 'B' || grade == 'b')
    {
        return 4;
    }
    else if (grade == 'C' || grade == 'c')
    {
        return 3;
    }
    else if (grade == 'D' || grade == 'd')
    {
        return 2;
    }
    else if (grade == 'E' || grade == 'e')
    {
        return 1;
    }
    else if (grade == 'F' || grade == 'f')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

char convertGrade(int &grade)
{
    if (grade == 5)
    {
        return 'A';
    }
    else if (grade == 4)
    {
        return 'B';
    }
    else if (grade == 3)
    {
        return 'C';
    }
    else if (grade == 2)
    {
        return 'D';
    }
    else if (grade == 1)
    {
        return 'E';
    }
    else if (grade == 0)
    {
        return 'F';
    }
    return '-';
}

// CORE CLASSES
class Course
{
private:
    int grade;
    int creditHours; // Course Unit
    std::string courseCode;
    int creditPoints;

public:
    int setGrade(char grade)
    {
        int realGrade = convertGrade(grade);
        if (realGrade < 0)
        {
            return -1;
        }
        this->grade = realGrade;
        return 1;
    }
    char getGrade()
    {
        return convertGrade(this->grade);
    }
    void setCreditHours(int creditHours)
    {
        this->creditHours = creditHours;
    }
    int getCreditHours()
    {
        return this->creditHours;
    }
    void setCourseCode(std::string courseCode)
    {
        this->courseCode = courseCode;
    }
    std::string getCourseCode()
    {
        return this->courseCode;
    }
    int getCreditPoints()
    {
        return this->grade * this->getCreditHours();
    }
};

class Semester
{
private:
    int numberOfCourses;
    int TNU = 0; // Total Credit Hours or Total Number of Units
    int TCP = 0; // Total Credit Points
    float GPA;   // Grade Point Average
    void setGPA()
    {
        GPA = (float)this->TCP / (float)this->TNU;
    }

public:
    void setNumberOfCourses(int numberOfCourses)
    {
        this->numberOfCourses = numberOfCourses;
    }
    int getNumberOfCourses()
    {
        return this->numberOfCourses;
    }
    void setTNU(int TNU)
    {
        this->TNU += TNU;
    }
    int getTNU()
    {
        return this->TNU;
    }
    void setTCP(int TCP)
    {
        this->TCP += TCP;
        this->setGPA();
    }
    int getTCP()
    {
        return this->TCP;
    }
    float getGPA()
    {
        return this->GPA;
    }
};

class AcademicSession
{
private:
    int numberOfSemesters;
    int cummulative_TCP;
    int cummulative_TNU;
    float CGPA = 0.0f;

public:
    void setNumberOfSemesters(int semestersCount)
    {
        this->numberOfSemesters = semestersCount;
    }
    int getNumberOfSemesters()
    {
        return this->numberOfSemesters;
    }
    void setCTCP(int CTCP)
    { // Setting Cummulative TCP
        this->cummulative_TCP = CTCP;
    }
    int getCTCP()
    {
        return this->cummulative_TCP;
    }
    void setCTNU(int CTNU)
    { // Setting Cummulative TNU
        this->cummulative_TNU = CTNU;
    }
    int getCTNU()
    {
        return this->cummulative_TNU;
    }
    float getCGPA()
    {
        if (cummulative_TNU == 0)
            return 0.0f;
        return (float)this->cummulative_TCP / (float)this->cummulative_TNU;
    }
};

// MAIN FUNCTIONS
void calculateGPA(Course course, Semester semester)
{
    std::cout << "\n========================================\n";
    std::cout << "        GPA CALCULATION (SEMESTER)\n";
    std::cout << "========================================\n";

    int numberOfCourses = getInt("\nEnter the number of courses you took: ");
    if (numberOfCourses < 1)
    {
        std::cout << "\nYou must have offered at least one course!\n";
        return;
    }

    std::vector<Course> courses(numberOfCourses);
    semester.setNumberOfCourses(numberOfCourses);

    for (int i = 1; i <= numberOfCourses; i++)
    {
        std::cout << "\n----------- Course " << i << " -----------\n";

        std::string courseCode = getString("Course Code: ");
        courses[i - 1].setCourseCode(courseCode);

        char grade = getChar("Grade (A–F): ");
        int value = courses[i - 1].setGrade(grade);
        if (value < 0)
        {
            std::cout << "Invalid Grade Entered!\n";
            return;
        }

        int credit_hours = getInt("Credit Unit (1–6): ");
        if (credit_hours < 1 || credit_hours > 6)
        {
            std::cout << "Credit Units must be between 1 and 6!\n";
            return;
        }

        courses[i - 1].setCreditHours(credit_hours);
        semester.setTNU(courses[i - 1].getCreditHours());
        semester.setTCP(courses[i - 1].getCreditPoints());
    }

    std::cout << "\n========================================\n";
    std::cout << "           SEMESTER RESULT\n";
    std::cout << "========================================\n";

    for (int i = 0; i < numberOfCourses; i++)
    {
        std::cout << courses[i].getCourseCode()
                  << "  ->  " << courses[i].getGrade() << "\n";
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nGPA FOR THIS SEMESTER: "
              << semester.getGPA() << "\n";
}

void calculateCGPA(Course course, Semester semester, AcademicSession session)
{
    std::cout << "\n==== CALCULATING CGPA FOR TOTAL ACADEMIC SESSIONS ====\n";

    int numberOfSemesters = getInt("\nEnter total number of semesters: ");
    if (numberOfSemesters < 1)
    {
        std::cout << "You must have at least one semester!\n";
        return;
    }

    int academicYears = getAcademicYears(numberOfSemesters);
    session.setNumberOfSemesters(numberOfSemesters);

    int cumulativeTCP = 0;
    int cumulativeTNU = 0;

    std::vector<std::vector<Course>> allSemesters(numberOfSemesters);

    int semesterIndex = 0;

    for (int year = 1; year <= academicYears; year++)
    {
        std::cout << "\n===== ACADEMIC YEAR " << year << " =====\n";

        for (int semInYear = 1; semInYear <= 2 && semesterIndex < numberOfSemesters; semInYear++)
        {
            Semester currentSemester;

            std::cout << "\n"
                      << semesterIndex + 1 << returnSuffix(semesterIndex + 1)
                      << " Semester\n";

            int numberOfCourses = getInt("Enter number of courses: ");
            if (numberOfCourses < 1)
            {
                std::cout << "You must have offered at least one course!\n";
                return;
            }

            for (int c = 0; c < numberOfCourses; c++)
            {
                Course course;

                std::cout << "\nCourse " << c + 1 << "\n";
                course.setCourseCode(getString("Enter Course Code: "));

                char grade = getChar("Enter Grade (A-F): ");
                if (course.setGrade(grade) < 0)
                {
                    std::cout << "Invalid grade entered!\n";
                    return;
                }

                int unit = getInt("Enter Credit Unit (1-6): ");
                if (unit < 1 || unit > 6)
                {
                    std::cout << "Invalid credit unit!\n";
                    return;
                }

                course.setCreditHours(unit);

                currentSemester.setTNU(course.getCreditHours());
                currentSemester.setTCP(course.getCreditPoints());

                cumulativeTNU += course.getCreditHours();
                cumulativeTCP += course.getCreditPoints();

                allSemesters[semesterIndex].push_back(course);
            }

            std::cout << std::fixed << std::setprecision(2);
            std::cout << "\nGPA for this semester: "
                      << currentSemester.getGPA() << "\n";

            semesterIndex++;
        }
    }

    session.setCTNU(cumulativeTNU);
    session.setCTCP(cumulativeTCP);

    std::cout << "\n===== COMPLETE ACADEMIC RESULT =====\n";

    semesterIndex = 0;
    for (int year = 1; year <= academicYears; year++)
    {
        std::cout << "\nACADEMIC YEAR " << year << "\n";

        for (int sem = 1; sem <= 2 && semesterIndex < numberOfSemesters; sem++)
        {
            std::cout << "Semester " << semesterIndex + 1 << "\n";
            for (auto &c : allSemesters[semesterIndex])
            {
                std::cout << c.getCourseCode()
                          << " -> " << c.getGrade() << "\n";
            }
            semesterIndex++;
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nFINAL CGPA: " << session.getCGPA() << "\n";
}

int main()
{
    while (true)
    {
        Course course;
        Semester semester;
        AcademicSession session;

        std::cout << "\n========================================\n";
        std::cout << "        WELCOME TO CGPA CALCULATOR\n";
        std::cout << "========================================\n";

        std::cout << "\nSelect an option below:\n";
        std::cout << "----------------------------------------\n";
        std::cout << "  1. Calculate GPA (Single Semester)\n";
        std::cout << "  2. Calculate CGPA (Academic Session)\n";
        std::cout << "  3. Exit Application\n";
        std::cout << "----------------------------------------\n";

        int choice = getInt("Enter your choice (1-3): ");

        if (choice == 1)
        {
            std::cout << "\n>>> GPA Calculation Selected <<<\n";
            calculateGPA(course, semester);

            if (performOperation())
                continue;

            break;
        }
        else if (choice == 2)
        {
            std::cout << "\n>>> CGPA Calculation Selected <<<\n";
            calculateCGPA(course, semester, session);

            if (performOperation())
                continue;

            break;
        }
        else if (choice == 3)
        {
            std::cout << "\n========================================\n";
            std::cout << "   Thank you for using CGPA Calculator\n";
            std::cout << "            Goodbye 👋\n";
            std::cout << "========================================\n";
            break;
        }
        else
        {
            std::cout << "\n❌ Invalid choice! Please select 1, 2 or 3.\n";
            continue;
        }
    }
}