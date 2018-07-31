#include <iostream>

#include "immutableemployee.h"
#include "mutableemployee.h"

auto mutableEmployeeTest() -> void
{
    std::string firstName = "Frankie";
    std::string lastName = "Kaur";
    double d = 1500.0;

    MutableEmployee me(0, firstName, lastName, d);

    std::cout << "id:" << me.id() << " ";
    std::cout << "firstName:" << me.firstName() << " ";
    std::cout << "lastName:" << me.lastName() << " ";
    std::cout << "salary:" << me.salary() << "\n";

    me.setId(1);
    me.setFirstName("Alexis");
    me.setLastName("Andrwe");
    me.setSalary(1000.0);

    std::cout << "id:" << me.id() << " ";
    std::cout << "firstName:" << me.firstName() << " ";
    std::cout << "lastName:" << me.lastName() << " ";
    std::cout << "salary:" << me.salary() << "\n";

}

auto immutableEmployeeTest() -> void {
    std::string firstName = "Frankie";
    std::string lastName = "Kaur";
    double d = 1500.0;

    ImmutableEmployee me(0, firstName, lastName, d);


    ImmutableEmployee m1 = me.setId(1);
    ImmutableEmployee m2 = m1.setFirstName("Younghyun");
    ImmutableEmployee m3 = m2.setLastName("Jo");
    ImmutableEmployee m4 = m3.setSalary(1000000.0);

    std::cout << "id:" << me.id() << " ";
    std::cout << "firstName:" << me.firstName() << " ";
    std::cout << "lastName:" << me.lastName() << " ";
    std::cout << "salary:" << me.salary() << "\n";

    std::cout << "id:" << m4.id() << " ";
    std::cout << "firstName:" << m4.firstName() << " ";
    std::cout << "lastName:" << m4.lastName() << " ";
    std::cout << "salary:" << m4.salary() << "\n";


}

auto main() -> int
{
    immutableEmployeeTest();
    // mutableEmployeeTest();
}