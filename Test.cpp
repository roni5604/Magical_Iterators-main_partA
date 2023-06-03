#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <iostream>

using namespace ariel;

TEST_CASE("Test 1-Initialization of MagicalContainer")
{
    MagicalContainer container;
    CHECK(container.size() == 0);
}

TEST_CASE("Test 2-Check Trowing Exception")
{
    MagicalContainer container;
    CHECK_THROWS_AS(container.removeElement(1), std::runtime_error);
}

TEST_CASE("Test 3-Add elements to MagicalContainer")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    CHECK(container.size() == 3);
}

TEST_CASE("Test 4-Check Trowing Exception removeElement that not exist")
{
    MagicalContainer container;
    container.addElement(2);
    CHECK_THROWS(container.removeElement(1));
}

TEST_CASE("Test 5-Remove elements from MagicalContainer")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.removeElement(1);
    CHECK(container.size() == 2);
    CHECK_THROWS(container.removeElement(1));
}


TEST_CASE("Test 6-Check AscendingIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::AscendingIterator ascIter(container);
    CHECK(*ascIter.begin() == 1);
    ++ascIter;
    CHECK(*ascIter.begin() == 2);
    ++ascIter;
    CHECK(*ascIter.begin() == 3);
    ++ascIter;
    CHECK(*ascIter.begin() == 4);
    ++ascIter;
    CHECK(*ascIter.begin() == 5);
}

TEST_CASE("Test 7-Check AscendingIterator update")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::AscendingIterator ascIter(container);
    container.addElement(6);
    container.removeElement(1);
    CHECK(*ascIter.begin() == 2);
    ++ascIter;
    CHECK(*ascIter.begin() == 3);
    ++ascIter;
    CHECK(*ascIter.begin() == 4);
    ++ascIter;
    CHECK(*ascIter.begin() == 5);
    ++ascIter;
    CHECK(*ascIter.begin() == 6);
}

TEST_CASE("Test 8-Check end point AscendingIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::AscendingIterator ascIter(container);
    ++ascIter;
    ++ascIter;
    ++ascIter;
    ++ascIter;
    ++ascIter;
    CHECK(ascIter.begin() == ascIter.end());
    CHECK_THROWS(++ascIter);
}

TEST_CASE("Test 9-Check Copy constructor AscendingIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::AscendingIterator ascIter2(ascIter);
    CHECK(*ascIter2.begin() == 1);
    ++ascIter2;
    CHECK(*ascIter2.begin() == 2);
    ++ascIter2;
    CHECK(*ascIter2.begin() == 3);
    ++ascIter2;
    CHECK(*ascIter2.begin() == 4);
    ++ascIter2;
    CHECK(*ascIter2.begin() == 5);
}

TEST_CASE("Test 10-Check Copy constructor AscendingIterator update")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::AscendingIterator ascIter2(ascIter);
    container.addElement(6);
    container.removeElement(1);
    CHECK(*ascIter2.begin() == 2);
    ++ascIter2;
    CHECK(*ascIter2.begin() == 3);
    ++ascIter2;
    CHECK(*ascIter2.begin() == 4);
    ++ascIter2;
    CHECK(*ascIter2.begin() == 5);
    ++ascIter2;
    CHECK(*ascIter2.begin() == 6);
}

TEST_CASE("Test 11-Check Equality comparison AscendingIterator and  Inequality comparison ")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);
    container.addElement(6);

    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::AscendingIterator ascIter2(container);
    CHECK(ascIter == ascIter2);
    ++ascIter;
    CHECK(ascIter != ascIter2);
    ++ascIter2;
    CHECK(ascIter == ascIter2);
}

TEST_CASE("Test 12-Check SideCrossIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::SideCrossIterator crossIter(container);
    CHECK(*crossIter.begin() == 1);
    ++crossIter;
    CHECK(*crossIter.begin() == 2);
    ++crossIter;
    CHECK(*crossIter.begin() == 3);
    ++crossIter;
    CHECK(*crossIter.begin() == 4);
    ++crossIter;
    CHECK(*crossIter.begin() == 5);
    ++crossIter;
    CHECK(*crossIter.begin() == 4);
    ++crossIter;
    CHECK(*crossIter.begin() == 3);
    ++crossIter;
    CHECK(*crossIter.begin() == 2);
    ++crossIter;
    CHECK(*crossIter.begin() == 1);
}

TEST_CASE("Test 13-Check SideCrossIterator update")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::SideCrossIterator crossIter(container);
    container.addElement(6);
    container.removeElement(1);
    CHECK(*crossIter.begin() == 2);
    ++crossIter;
    CHECK(*crossIter.begin() == 3);
    ++crossIter;
    CHECK(*crossIter.begin() == 4);
    ++crossIter;
    CHECK(*crossIter.begin() == 5);
    ++crossIter;
    CHECK(*crossIter.begin() == 6);
    ++crossIter;
    CHECK(*crossIter.begin() == 5);
    ++crossIter;
    CHECK(*crossIter.begin() == 4);
    ++crossIter;
    CHECK(*crossIter.begin() == 3);
    ++crossIter;
    CHECK(*crossIter.begin() == 2);
}

TEST_CASE("Test 14-check endpoint SideCrossIterator")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    MagicalContainer::SideCrossIterator crossIter(container);
    ++crossIter;
    ++crossIter;
    ++crossIter;
    ++crossIter;
    ++crossIter;
    CHECK(crossIter.begin() == crossIter.end());
    CHECK_THROWS(++crossIter);
}

TEST_CASE("Test 15-Check Copy constructor SideCrossIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);

    MagicalContainer::SideCrossIterator crossIter(container);
    MagicalContainer::SideCrossIterator crossIter2(crossIter);
    CHECK(*crossIter2.begin() == 1);
    ++crossIter2;
    CHECK(*crossIter2.begin() == 2);
    ++crossIter2;
    CHECK(*crossIter2.begin() == 3);
    ++crossIter2;
    CHECK(*crossIter2.begin() == 4);
    ++crossIter2;
    CHECK(*crossIter2.begin() == 5);
    ++crossIter2;
    CHECK(*crossIter2.begin() == 4);
    ++crossIter2;
    CHECK(*crossIter2.begin() == 3);
    ++crossIter2;
    CHECK(*crossIter2.begin() == 2);
    ++crossIter2;
    CHECK(*crossIter2.begin() == 1);
}

TEST_CASE("Test 16-Check Equality comparison SideCrossIterator and  Inequality comparison ")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);
    container.addElement(6);

    MagicalContainer::SideCrossIterator crossIter(container);
    MagicalContainer::SideCrossIterator crossIter2(container);
    CHECK(crossIter == crossIter2);
    ++crossIter;
    CHECK(crossIter != crossIter2);
    ++crossIter2;
    CHECK(crossIter == crossIter2);
}

TEST_CASE("Test 17-Check PrimeIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);
    container.addElement(6);

    MagicalContainer::PrimeIterator primeIter(container);
    CHECK(*primeIter.begin() == 2);
    ++primeIter;
    CHECK(*primeIter.begin() == 3);
    ++primeIter;
    CHECK(*primeIter.begin() == 5);
}

TEST_CASE("Test 18-Check PrimeIterator update")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);
    

    MagicalContainer::PrimeIterator primeIter(container);
    container.addElement(6);
    container.addElement(7);
    container.removeElement(2);
    CHECK(*primeIter.begin() == 3);
    ++primeIter;
    CHECK(*primeIter.begin() == 5);
    ++primeIter;
    CHECK(*primeIter.begin() == 7);
}

TEST_CASE("Test 19-Check endpoint PrimeIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);
    container.addElement(6);

    MagicalContainer::PrimeIterator primeIter(container);
    ++primeIter;
    ++primeIter;
    ++primeIter;
    CHECK(primeIter.begin() == primeIter.end());
    CHECK_THROWS(++primeIter);
}

TEST_CASE("Test 20-Check Copy constructor PrimeIterator")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);
    container.addElement(6);

    MagicalContainer::PrimeIterator primeIter(container);
    MagicalContainer::PrimeIterator primeIter2(primeIter);
    CHECK(*primeIter2.begin() == 2);
    ++primeIter2;
    CHECK(*primeIter2.begin() == 3);
    ++primeIter2;
    CHECK(*primeIter2.begin() == 5);
}

TEST_CASE("Test 21-Check Equality comparison PrimeIterator and  Inequality comparison ")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);
    container.addElement(1);
    container.addElement(4);
    container.addElement(6);

    MagicalContainer::PrimeIterator primeIter(container);
    MagicalContainer::PrimeIterator primeIter2(container);
    CHECK(primeIter == primeIter2);
    ++primeIter;
    CHECK(primeIter != primeIter2);
    ++primeIter2;
    CHECK(primeIter == primeIter2);
}




