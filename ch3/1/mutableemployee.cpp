#include "mutableemployee.h"
MutableEmployee::MutableEmployee() : m_id(0),
                                     m_salary(0.0)
{
}

MutableEmployee::MutableEmployee(
    int id,
    const std::string &firstName,
    const std::string &lastName,
    const double &salary)
    : m_id(id),
      m_firstName(firstName),
      m_lastName(lastName),
      m_salary(salary)
{
}

void MutableEmployee::setId(const int id) {
    m_id = id;
}

void MutableEmployee::setFirstName(const std::string& firstName) {
    m_firstName = firstName;
}

void MutableEmployee::setLastName(const std::string& lastName) {
    m_lastName = lastName;
}

void MutableEmployee::setSalary(const double& salary) {
    m_salary = salary;
}

