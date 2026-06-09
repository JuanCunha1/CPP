#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

class Test {
public:
    // Orthodox Canonical Form
    Test();
    Test(const Test& other);
    Test& operator=(const Test& other);
    ~Test();

private:
    int _value;
};

#endif // TEST_HPP
