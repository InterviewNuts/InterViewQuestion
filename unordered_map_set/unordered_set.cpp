/**
 * @file unordered_set.cpp
 * @author Haramohan Sahu (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */



#include<iostream>
#include <unordered_set>

using namespace std;


class Employee
{
    int mId;
    std::string mName;
public:
    Employee(int id, std::string name) :
        mId(id), mName(name)
    {
    }
    void displayInfo()
    {
        std::cout << mId << " :: " << mName << std::endl;
    }

    // bool operator()(const std::string& str1, const std::string& str2) const {
    //     if (str1.length() == str2.length())
    //         return true;
    //     else
    //         return false;
    // }

//! this is the comparison 
    bool operator == (const Employee& obj) const
    {
        return (this->mId == obj.mId) ? true : false;
    }


    int getId() const
    {
        return mId;
    }
    std::string getName() const
    {
        return mName;
    }

};

namespace std
{
    template<>
    struct hash<Employee>
    {
        size_t
            operator()(const Employee& obj) const
        {
            return hash<int>()(obj.getId());
        }
    };
}



// Custom Hash Functor that will compute the hash on the passed string objects length
struct EmployeeHasher
{
    size_t
        operator()(const Employee& obj) const
    {
        return std::hash<std::string>()(obj.getName());
    }
};
// Custom comparator that compares the string objects by length
struct EmployeeComparator
{
    bool
        operator()(const Employee& obj1, const Employee& obj2) const
    {
        if (obj1.getName() == obj2.getName())
            return true;
        return false;
    }
};


int main()
{
    // Declaring unordered_set of Employee
    std::unordered_set<Employee> setOfEmployee;
    std::cout << "Creating an Unordered_set by unique ID\n";
    // Inserting elements
    setOfEmployee.insert(Employee(11, "John"));
    setOfEmployee.insert(Employee(12, "Harry"));
    setOfEmployee.insert(Employee(13, "Ritz"));
    setOfEmployee.insert(Employee(14, "John"));

    // Trying to insert with duplicate ID
    auto res = setOfEmployee.insert(Employee(12, "Varun"));
    if (res.second == false)
        std::cout << "Failed to insert with ID 12" << std::endl;
    for (Employee st : setOfEmployee)
        st.displayInfo();

    //!--------------------------------------------------------------
    // Declaring unordered_set of Student
    std::unordered_set<Employee, EmployeeHasher, EmployeeComparator> setOfEmpByName;
    std::cout << "Creating an Unordered_set by Unique Name\n";
    // Inserting elements
    setOfEmpByName.insert(Employee(11, "John"));
    setOfEmpByName.insert(Employee(12, "Harry"));
    setOfEmpByName.insert(Employee(13, "Ritz"));
    res = setOfEmpByName.insert(Employee(14, "John"));
    if (res.second == false)
        std::cout << "Failed to insert with duplicate name - John" << std::endl;
    // Trying to insert with duplicate ID
    res = setOfEmpByName.insert(Employee(12, "Varun"));
    if (res.second == false)
        std::cout << "Failed to insert with ID 12" << std::endl;
    else
        std::cout << "Successful in inserting with ID 12 again" << std::endl;
    for (Employee st : setOfEmpByName)
        st.displayInfo();

    return 0;
}