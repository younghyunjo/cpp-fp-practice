#include "immutableemployee.h"

ImmutableEmployee::ImmutableEmployee(const int &id,
                                     const std::string &firstName,
                                     const std::string &lastName,
                                     const double &salary) : m_id(id),
                                                             m_firstName(firstName),
                                                             m_lastName(lastName),
                                                             m_salary(salary)
{
}

ImmutableEmployee::ImmutableEmployee()
    : m_id(0),
      m_salary(0.0)
{
}