#include <iostream>
#include <memory>
#include <tuple>
#include <string>

struct BodyMass
{
    int Id;
    float Weight;

    BodyMass(int id, float weight) : Id(id), Weight(weight)
    {
        std::cout << "constructed" << std::endl;
    }

    ~BodyMass()
    {
        std::cout << "destructed" << std::endl;
    }
};

std::unique_ptr<BodyMass> GetBodyMass()
{
    return std::make_unique<BodyMass>(1, 165.3f);
}

std::unique_ptr<BodyMass> UpdateMass(std::unique_ptr<BodyMass> bodyMass)
{
    bodyMass->Weight += 1.0f;
    return bodyMass;
}

auto sharedPointer()
{
    auto sp1 = std::shared_ptr<int>{};

    if (sp1)
        std::cout << "sp1 initialized\n";
    else
        std::cout << "sp1 uninitialized\n";

    std::cout << "sp1 usecount " << sp1.use_count() << std::endl;
    if (sp1.unique())
        std::cout << "sp1 unique\n";
    else
        std::cout << "sp1 is not unique\n";

    sp1 = std::make_shared<int>(1234);
    if (sp1)
        std::cout << "sp1 is initialized\n";
    else
        std::cout << "sp1 is not initialized\n";

    std::cout << "sp1 usecount " << sp1.use_count() << std::endl;
    if (sp1.unique())
        std::cout << "sp1 unique\n";
    else
        std::cout << "sp1 is not unique\n";

    auto sp2 = sp1;
    std::cout << "sp1 usecount " << sp1.use_count() << std::endl;
    if (sp1.unique())
        std::cout << "sp1 unique\n";
    else
        std::cout << "sp1 is not unique\n";

    sp2.reset();
    std::cout << "sp1 usecount " << sp1.use_count() << std::endl;
    if (sp1.unique())
        std::cout << "sp1 unique\n";
    else
        std::cout << "sp1 is not unique\n";
}

auto weakPointer()
{
    auto sp = std::make_shared<int>(1234);
    auto wp = std::weak_ptr<int>{sp};

    if (wp.expired())
        std::cout << "wp expired\n";
    else
        std::cout << "wp not expired\n";

    if (auto locked = wp.lock())
    {
        std::cout << "wp is locked. Value = " << *locked << std::endl;
    }
    else
    {
        std::cout << "wp is unlocked" << std::endl;
    }

    sp = nullptr;

    if (wp.expired())
    {
        std::cout << "wp is expired" << std::endl;
    }
    else
    {
        std::cout << "wp is not expired" << std::endl;
    }
    if (auto locked = wp.lock())
    {
        std::cout << "wp is locked. Value = " << *locked << std::endl;
    }
    else
    {
        std::cout << "wp is unlocked" << std::endl;
        wp.reset();
    }

    std::cout << std::endl;

    return 0;
}

auto tupleTest() -> void
{
    std::tuple<int, std::string, bool> t1(1, "Robert", true);
    auto t2 = std::make_tuple(2, "Anna", false);

    std::cout << std::get<0>(t1) << std::endl;
    std::cout << std::get<1>(t1) << std::endl;
    std::cout << std::get<2>(t2) << std::endl;

    std::cout << std::get<0>(t2) << std::endl;
    std::cout << std::get<1>(t2) << std::endl;
    std::cout << std::get<2>(t2) << std::endl;
}

auto tupleTieAndIgnore() -> void
{
    auto t1 = std::make_tuple(1, "Robert", true);
    auto t2 = std::make_tuple(2, "Anna", false);

    int i;
    std::string s;
    bool b;

    tie(i, s, b) = t1;
    std::cout << "From tie\n";
    std::cout << i << " " << s << " " << b << std::endl;

    tie(std::ignore, s, std::ignore) = t2;
    std::cout << "From tie\n";
    std::cout << i << " " << s << " " << b << std::endl;
}

auto GetData(int id)
{
    if (id == 1)
    {
        return std::make_tuple(0, "Chloe", false);
    }
    else if (id == 2)
    {
        return std::make_tuple(1, "Bryan", true);
    }
    else
    {
        return std::make_tuple(2, "Zoey", false);
    }
}

auto tupleReturn() -> void {
    auto name = GetData(1);
    std::cout << std::get<0>(name) << " " << std::get<1>(name) << " " << std::get<2>(name) << std::endl;
}

auto main() -> int
{
    tupleReturn();
    // tupleTieAndIgnore();
    // tupleTest();
    // weakPointer();
    // sharedPointer();
    // auto my = GetBodyMass();

    // my = UpdateMass(std::move(my));

    // auto myWeight = std::make_unique<BodyMass>(0, 78.9);
    // auto myWieght2 = myWeight;
    // auto copyWeight = *myWeight;
    return 0;
}