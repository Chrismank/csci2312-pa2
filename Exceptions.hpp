//
//  Exceptions.hpp
//  Programming Assignment 4 Final
//
//  Created by Kathryn Chrisman on 10/31/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#ifndef Exceptions_hpp
#define Exceptions_hpp

#include <iostream>
#include <stdio.h>

using namespace std;

namespace Clustering
{
    class DimensionalityMismatchEx
    {
    private:
        unsigned int __current, __rhs;
        std::string getName;
        
    public:
        DimensionalityMismatchEx(unsigned int c, unsigned int r) : __current(c), __rhs(r), getName("DimensionalityMismatchEx") {}
        
        // Getters
        unsigned int getCurrent() const { return __current; }
        unsigned int getRhs() const { return __rhs; }
        
        // Cout Operator
        friend std::ostream &operator<<(std::ostream &os, const DimensionalityMismatchEx &ex)
        {
            os << "DimensionalityMismatchEx ("
            << "current = " << ex.__current << ", "
            << "rhs = " << ex.__rhs << ')';
            return os;
        }
        
    };
    
    class OutOfBoundsEx
    {
    private:
        std::string getName;
        unsigned int _index;
        
    public:
        OutOfBoundsEx(unsigned int val) : _index(val), getName("OutOfBoundsEx") {}
        
        // Getters
        unsigned int getIndex() const { return _index; }
        
        // Cout Operator
        friend std::ostream & operator<<(std::ostream & os, const OutOfBoundsEx & ex)
        {
            os << "Out of Bounds Exception Thrown";
            return os;
        }
        
    };
    
    class RemoveFromEmptyEx
    {
    private:
        std::string getName;
    
    public:
        RemoveFromEmptyEx() : getName("RemoveFromEmptyEx") {};
        
        // Throw this for the remove method when the cluster is already empty
        // Throw this for the computeCentroid method when the cluster is empty
        
        friend std::ostream & operator<<(std::ostream & os, const RemoveFromEmptyEx & ex)
        {
            os << "Remove From Empty Exception Thrown";
            return os;
        }
       
    };
    
}

#endif /* Exceptions_hpp */
