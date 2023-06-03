#include "MagicalContainer.hpp"

namespace ariel
{
    // Constructor
    MagicalContainer::MagicalContainer()
    {
        sizeOfContainer = 0;
    }

    // Add an element to the container
    void MagicalContainer::addElement(int element)
    {
        elements.push_back(element);
        sizeOfContainer++;
    }

    // Remove an element from the container
    void MagicalContainer::removeElement(int element)
    {
        elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
        sizeOfContainer--;
    }

    // Get the size of the container
    size_t MagicalContainer::size() const
    {
        
        return (size_t)sizeOfContainer;
    }

    // AscendingIterator Constructor
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
    {
        it = container.elements.begin();
        sizeOfAscIter = container.size();
    }

    // AscendingIterator: Get the beginning iterator
    vector<int>::iterator MagicalContainer::AscendingIterator::begin() const
    {
        return it;
    }

    // AscendingIterator: Get the ending iterator
    vector<int>::iterator MagicalContainer::AscendingIterator::end() const
    {
        return it + sizeOfAscIter;
    }

    // AscendingIterator: Equality operator
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return it == other.it;
    }

    // AscendingIterator: Inequality operator
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return !(*this == other);
    }

    // AscendingIterator: Greater than operator
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return it > other.it;
    }

    // AscendingIterator: Less than operator
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return it < other.it;
    }

    // AscendingIterator: Dereference operator
    int MagicalContainer::AscendingIterator::operator*() const
    {
        return *it;
    }

    // AscendingIterator: Pre-increment operator
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        ++it;
        return *this;
    }

    // SideCrossIterator Constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
    {
        forwardIt = container.elements.begin();
        reverseIt = container.elements.rbegin();
        isForward = true;
        sizeOfCrossIter = container.size();
    }

    // SideCrossIterator: Get the beginning iterator
    vector<int>::const_iterator MagicalContainer::SideCrossIterator::begin() const
    {
        return isForward ? forwardIt : vector<int>::const_iterator(reverseIt.base());
    }

    // SideCrossIterator: Get the ending iterator
    vector<int>::const_iterator MagicalContainer::SideCrossIterator::end() const
    {
        return isForward ? forwardIt + sizeOfCrossIter : vector<int>::const_iterator(reverseIt.base());
    }

    // SideCrossIterator: Equality operator
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return forwardIt == other.forwardIt && reverseIt == other.reverseIt && isForward == other.isForward;
    }

    // SideCrossIterator: Inequality operator
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }

    // SideCrossIterator: Greater than operator
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return forwardIt > other.forwardIt;
    }

    // SideCrossIterator: Less than operator
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return forwardIt < other.forwardIt;
    }

    // SideCrossIterator: Dereference operator
    int MagicalContainer::SideCrossIterator::operator*() const
    {
        return isForward ? *forwardIt : *reverseIt;
    }

    // SideCrossIterator: Pre-increment operator
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if (isForward)
        {
            ++forwardIt;
            if (forwardIt == reverseIt.base())
            {
                isForward = false;
            }
        }
        else
        {
            ++reverseIt;
        }
        return *this;
    }

    // PrimeIterator Constructor
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
    {
        it = container.elements.begin();
        sizeOfPrimeIter = container.size();
    }

    // PrimeIterator: Get the beginning iterator
    vector<int>::const_iterator MagicalContainer::PrimeIterator::begin() const
    {
        while (it != this->end() && !isPrime(*it))
        {
break;        }
        return it;
    }

    // PrimeIterator: Get the ending iterator
    vector<int>::const_iterator MagicalContainer::PrimeIterator::end() const
    {
        return it + sizeOfPrimeIter;
    }

    // PrimeIterator: Equality operator
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return it == other.it;
    }

    // PrimeIterator: Inequality operator
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return !(*this == other);
    }

    // PrimeIterator: Greater than operator
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return it > other.it;
    }

    // PrimeIterator: Less than operator
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return it < other.it;
    }

    // PrimeIterator: Dereference operator
    int MagicalContainer::PrimeIterator::operator*() const
    {
        return *it;
    }

    // PrimeIterator: Pre-increment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        ++it;
        while (it != this->end()&& !isPrime(*it))
        {
            ++it;
        }
        return *this;
    }

    // Helper function to check if a number is prime
    bool MagicalContainer::PrimeIterator::isPrime(int num) const
    {
        if (num < 2)
        {
            return false;
        }
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}
