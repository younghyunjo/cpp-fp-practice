#pragma once

#include <string>

class MutableEmployee {
public:
    MutableEmployee(
        int id,
        const std::string& firstName,
        const std::string& lastName,
        const double& salary);
    MutableEmployee();

    void setId(const int id);
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setSalary(const double& salary);

    int id() const {return m_id;}
    std::string firstName() const {return m_firstName;}
    std::string lastName() const {return m_lastName;}
    double salary() const {return m_salary;}

private:
    int m_id;
    std::string m_firstName;
    std::string m_lastName;
    double m_salary;
};
