#pragma once

#include <string>

class ImmutableEmployee
{
  public:
    ImmutableEmployee(
        const int &id,
        const std::string &firstName,
        const std::string &lastName,
        const double &salary);
    ImmutableEmployee();

    const int &id() const
    {
        return m_id;
    }

    const std::string &firstName() const
    {
        return m_firstName;
    }
    const std::string &lastName() const
    {
        return m_lastName;
    }

    const double &salary() const
    {
        return m_salary;
    }

    const ImmutableEmployee setId(const int &id) const
    {
        return ImmutableEmployee(id, m_firstName, m_lastName, m_salary);
    }

    const ImmutableEmployee setFirstName(const std::string& firstName) const {
        return ImmutableEmployee(m_id, firstName, m_lastName, m_salary);
    }

    const ImmutableEmployee setLastName(const std::string& lastName) const {
        return ImmutableEmployee(m_id, m_firstName, lastName, m_salary);
    }

    const ImmutableEmployee setSalary(const double& salary) const {
        return ImmutableEmployee(m_id, m_firstName, m_lastName, salary);
    }

  private:
    const int m_id;
    const std::string m_firstName;
    const std::string m_lastName;
    const double m_salary;
};