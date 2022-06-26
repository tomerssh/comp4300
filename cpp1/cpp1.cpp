#include <iostream>
#include <vector>
#include <fstream>

class Student
{
    std::string m_first = "Tomer";
    std::string m_last = "Shoshani";
    int         m_sid = 0;
    int         m_grade = 0;
public:
    Student()
    {

    }

    Student(const std::string & first, const std::string & last, int id, int grade)
        : m_first(first)
        , m_last(last)
        , m_sid(id)
        , m_grade(grade)

    {
        //std::cout << "Constructor\n";
    }

    ~Student()
    {
        //std::cout << "Destructor\n";
    }

    std::string getFirst()
    {
        return m_first;
    }

    std::string getLast()
    {
        return m_last;
    }

    int getID()
    {
        return m_sid;
    }

    int getGrade()
    {
        return m_grade;
    }

    void print()
    {
        std::cout << m_first << " " << m_last << " " << m_sid << " " << m_grade << "\n";
    }
};

class Course
{
    std::vector<Student> m_students;
    std::string          m_name;

public:
    Course(const std::string & name)
        : m_name(name)
    {
    }

    void addStudent(const Student & s)
    {
        m_students.push_back(s);
    }

    const std::vector<Student> & getStudents()
    {
        return m_students;
    }

    void print()
    {
        for (auto & s : m_students)
        {
            s.print();
        }
    }

    void addStudentsFromFile(const std::string & filename)
    {
        std::ifstream fin(filename);

        std::string first, last;
        int id, grade;

        while (fin >> first)
        {
            fin >> last >> id >> grade;
            addStudent(Student(first, last, id, grade));
        }
    }
};

int main(int argc, char * argv[])
{
    Course c("COMP4300");

    // object stack allocation
    Student s1("Tomer", "Shoshani", 1234, 123);
    Student s2("Tomer2", "Shoshani2", 1234, 123);

    c.addStudent(s1);
    c.addStudent(s2);

    c.addStudentsFromFile("students.txt");

    c.print();

    return 0;
} // destructor runs here