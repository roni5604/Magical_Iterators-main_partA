#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> elements;
        int sizeOfContainer;

    public:
        MagicalContainer();
        void addElement(int element);
        void removeElement(int element);
        size_t size() const;

        class AscendingIterator
        {
        private:
            vector<int>::iterator it;
            int sizeOfAscIter;

        public:
            AscendingIterator(MagicalContainer &container);
            vector<int>::iterator begin() const;
            vector<int>::iterator end() const;
            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            int operator*() const;
            AscendingIterator& operator++();
        };

        class SideCrossIterator
        {
        private:
            vector<int>::const_iterator forwardIt;
            vector<int>::const_reverse_iterator reverseIt;
            bool isForward;
            int sizeOfCrossIter;

        public:
            SideCrossIterator(MagicalContainer &container);
            vector<int>::const_iterator begin() const;
            vector<int>::const_iterator end() const;
            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;

            int operator*() const;
            SideCrossIterator& operator++();
        };

        class PrimeIterator
        {
            private:
            vector<int>::const_iterator it;
            bool isPrime(int num) const;
            int sizeOfPrimeIter;

            public:
            PrimeIterator(MagicalContainer &container);
            vector<int>::const_iterator begin() const;
            vector<int>::const_iterator end() const;
            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            int operator*() const;
            PrimeIterator& operator++();            

        };
    };
}

#endif
