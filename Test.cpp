#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <iostream>

using namespace ariel;

TEST_CASE("Initialization of MagicalContainer")
{
    MagicalContainer container;
    CHECK(container.size() == 0);
}

TEST_CASE("Check endpoint of AscendingIterator")
{
    MagicalContainer container;
    // Add elements to the container
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    MagicalContainer::AscendingIterator ascIter(container);

    CHECK(*ascIter.begin() == 1);

    // Move iterator to the end
    for (int i = 0; i < container.size() - 1; ++i)
    {
        ++ascIter;
    }
    CHECK(*ascIter.end() == 5);
   
}

TEST_CASE("Check Throw when removing an element from an empty container")
{
    MagicalContainer container;
    CHECK_THROWS_AS(container.removeElement(1), std::out_of_range);
}

TEST_CASE("Initialization of MagicalContainer with elements")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    CHECK(container.size() == 3);
}

TEST_CASE("Check endpoint of SideCrossIterator")
{
    MagicalContainer container;
    // Add elements to the container
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    MagicalContainer::SideCrossIterator crossIter(container);
    CHECK(*crossIter.begin() == 1);
    for (int i = 0; i < container.size() - 1; ++i)
    {
        ++crossIter;
    }
    CHECK(*crossIter.end() == 5);
    ++crossIter;
    CHECK(*crossIter.end() == 4);
    
}

TEST_CASE("Check Throw when removing an element that doesn't exist in the container")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    REQUIRE_THROWS_AS(container.removeElement(3), std::out_of_range);
}

TEST_CASE("Add elements to the container")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    CHECK(container.size() == 3);
}

TEST_CASE("Check endpoint of PrimeIterator")
{
    MagicalContainer container;
    // Add elements to the container
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    MagicalContainer::PrimeIterator primeIter(container);
    CHECK(*primeIter.begin() == 2);
    for (int i = 0; i < container.size() - 1; ++i)
    {
        ++primeIter;
    }
    CHECK(*primeIter.end() == 3);
    ++primeIter;
    CHECK(*primeIter.end() == 2);
    CHECK_THROWS_AS(++primeIter, std::out_of_range);
}

TEST_CASE("Check Throw when adding an element that already exists in the container")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    CHECK_THROWS_AS(container.addElement(1), std::invalid_argument);
}

TEST_CASE("Remove elements from the container")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.removeElement(2);

    CHECK(container.size() == 2);
}

TEST_CASE("Check Throw when accessing the AscendingIterator after removing all elements")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.removeElement(1);
    container.removeElement(2);
    CHECK_THROWS_AS(container.removeElement(2), std::invalid_argument);
}

TEST_CASE("Add elements to the container")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    CHECK(container.size() == 3);
}

TEST_CASE("Check Throw when accessing the SideCrossIterator after removing all elements")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.removeElement(1);
    container.removeElement(2);

    CHECK_THROWS_AS(container.removeElement(2), std::invalid_argument);
}

TEST_CASE("Remove elements from the container")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.removeElement(2);

    CHECK(container.size() == 2);
}

TEST_CASE("Check Throw when accessing the PrimeIterator after removing all elements")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.removeElement(1);
    container.removeElement(2);

    CHECK_THROWS_AS(container.removeElement(2), std::invalid_argument);
}

TEST_CASE("Add elements to the container")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    CHECK(container.size() == 3);
}

TEST_CASE("Check Throw when adding a negative element to the container")
{
    MagicalContainer container;
    CHECK_THROWS_AS(container.addElement(-1), std::invalid_argument);
}

TEST_CASE("Check Throw when removing a negative element from the container")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    CHECK_THROWS_AS(container.removeElement(-1), std::out_of_range);
}

TEST_CASE("Check Throw when adding a large element to the container")
{
    MagicalContainer container;
    CHECK_THROWS_AS(container.addElement(1000000), std::out_of_range);
}

TEST_CASE("Check Throw when removing a large element from the container")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    CHECK_THROWS_AS(container.removeElement(1000000), std::out_of_range);
}
