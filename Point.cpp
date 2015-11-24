//
//  Point.cpp
//  Programming Assignment 4 Final
//
//  Created by Kathryn Chrisman on 10/31/15.
//  Copyright © 2015 Kathryn. All rights reserved.

#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>

#include "Point.hpp"
#include "Exceptions.hpp"

using namespace std;

namespace Clustering
{
    template<typename T, int dim>
    const char Point<T, dim>::POINT_VALUE_DELIM = ',';
    
    template<typename T, int dim>
    unsigned int Point<T, dim>::_idGeneratorPt = 1;
    
    template<typename T, int dim>
    Point<T, dim>::Point()
    {
        cout << "Dimensions: " << dim << endl;
        
        _idPt = _idGeneratorPt++;
       
        cout << "Point ID: " << _idPt << endl;
    }
    
    template<typename T, int dim>
    Point<T, dim>::Point(const Point<T, dim> & rhs)
    {
        for (int i = 0; i < dim; i++) // Copies the values from one vector to another
        {
            a.push_back(rhs.a[i]);
        }
        
    }
    
    template<typename T, int dim>
    Point<T, dim> & Point<T, dim>::operator=(const Point<T, dim> & rhs)
    {
        a.clear();
      
        for(int i = 0; i < dim; i++) // Assigns values to vector
        {
            a.push_back(rhs.a[i]);
        }
        
        return *this;
    }
    
    template<typename T, int dim>
    Point<T, dim>::~Point<T, dim>()
    {
        
    }
    
    // Mutator Method
    
    template<typename T, int dim>
    void Point<T, dim>::setValue(int dimension, T newValue)
    {
        // dimension is the actual dimension (i.e. x, y, z) that we are changing
        
        if (dimension >= 1 && dimension <= dim)
        {
            a.push_back(newValue);
        }
        
    }
    
    // Accessor Methods
    
    template<typename T, int dim>
    double Point<T, dim>::getValue(int d) const
    {
        cout << a[d-1] << endl;
        
        return a[d-1];
    }
    
    template<typename T, int dim>
    int Point<T, dim>::getDims() const
    {
        return dim;
    }
    
    // Overloaded Stream Operators
    
    template<typename T, int dim>
    std::ostream &operator<<(std::ostream & out, const Point<T, dim> & p)
    {
        cout << fixed << showpoint << setprecision(1);
        
        // Vector Iterator
        if(p.a.empty() != true)
        {
            auto it = p.a.begin();
        
            for( ; it!= p.a.end()-1; ++it)
            {
                cout << *it << ", ";
            }
        
            cout << *it << " ";
        }
        
        return out;
        
    }
    
    template<typename T, int dim>
    std::istream &operator>>(std::istream & in, Point<T, dim> & p)
    {
        // adding in comma separated values of doubles, each line is a point, the number of values in each line are the number of dimensions in our point
        
        string value; // Take in each point in our line as a string
        
        T pt; // Holds the point values after we convert them from string to double
        
        int i = 1; // counter to hold the number of dimensions (starts at 1 since dimensions will be number of commas + 1)
        
        while(getline(in, value, Point<T, dim>::POINT_VALUE_DELIM)) // omit commas when reading lines, store points into "value"
        {
            pt = stod(value); // convert the strings to doubles
            
            if(i > dim)
            {
                p.rewindIdGen();
                throw DimensionalityMismatchEx(i, dim);
            }
         
             p.setValue(i++, pt);
        }
        
        i--;
        
        if(i < dim)
        {
            p.rewindIdGen();
            throw DimensionalityMismatchEx(i, dim);
        }
        
        return in;
    }
    
    // Overloaded [] Operator
    template<typename T, int dim>
    T & Point<T, dim>::operator[](int index)
    {
        if(index >= dim)
        {
            throw OutOfBoundsEx(index);
        }
       
        return a[index];
    }
    
    // distanceTo Function to approximate the distance between two points
    template<typename T, int dim>
    T Point<T, dim>::distanceTo(const Point<T, dim> & other) const
    {
            double sum = 0;
            
            for (int i = 0; i < dim; i++)
            {
                double diff = a[i] - other.a[i];
                sum += diff * diff; // sum = sum + (diff)^2 for every dimension
            }
            
            cout << fixed << showpoint << setprecision(2);
            return sqrt(sum);
        
        return 0; // If the if statement is not satisfied
    }
    
    // Comparison Operators
    
    template<typename T, int dim>
    bool operator==(const Point<T, dim> & lhs, const Point<T, dim> & rhs)
    {
        cout << "ID Comparison: " << lhs._idPt << " " << rhs._idPt << endl;
        
        for (int i = 0; i < dim; i++)
        {
            if(lhs.a[i] != rhs.a[i])
            {
                return false;
            }
        }
        
        return true;
    }
    
    template<typename T, int dim>
    bool operator!=(const Point<T, dim> & lhs, const Point<T, dim> & rhs)
    {
        for(int i = 0; i < dim; i++)
        {
            if(lhs._idPt != rhs._idPt || lhs.a[i] != rhs.a[i])
            {
                return true;
            }
        }
        
        return false;
    }
    
    template<typename T, int dim>
    bool operator>=(const Point<T, dim> & lhs, const Point<T, dim> & rhs)
    {
        for(int i = 0; i < dim; i++)
        {
            if(lhs.a[i] >= rhs.a[i])
            {
                return true;
            }
            
            if(lhs.a[i] < rhs.a[i])
            {
                return false;
            }
        }
        
        return false;
    }
    
    template<typename T, int dim>
    bool operator<=(const Point<T, dim> & lhs, const Point<T, dim> & rhs)
    {
        for(int i = 0; i < dim; i++)
        {
            if(lhs.a[i] <= rhs.a[i])
            {
                return true;
            }
            
            if(lhs.a[i] > rhs.a[i])
            {
                return false;
            }
        }
        
        return false;
    }
    
    template<typename T, int dim>
    bool operator>(const Point<T, dim> & lhs, const Point<T, dim> & rhs)
    {
        for(int i = 0; i < dim; i++)
        {
            if(lhs.a[i] > rhs.a[i])
            {
                return true;
            }
            
            if(lhs.a[i] < rhs.a[i])
            {
                return false;
            }
        }
        
        return false;
    }
    
    template<typename T, int dim>
    bool operator<(const Point<T, dim> & lhs, const Point<T, dim> & rhs)
    {
        for(int i = 0; i < dim; i++)
        {
            
            if(lhs.a[i] < rhs.a[i])
            {
                return true;
            }
            
            if(lhs.a[i] > rhs.a[i])
            {
                return false;
            }
        }
        
        return false;
    }
    
    // Arithmetic Operators
    
    template<typename T, int dim>
    Point<T, dim> & Point<T, dim>::operator*=(T val)
    {
        for(int i = 0; i < dim; i++)
        {
            (a[i] *= val);
        }
        
        cout << fixed << showpoint << setprecision(2) << endl;
        
        return *this;
    }
    
    template<typename T, int dim>
    Point<T, dim> & Point<T, dim>::operator/=(T val)
    {
        if(val > 0)
        {
            for(int i = 0; i < dim; i++)
            {
                a[i] /= val;
            }
            
            cout << fixed << showpoint << setprecision(2) << endl;
            return *this;
        }
        
        else
        {
            cout << "You cannot divide by zero." << endl;
            return *this;
        }
    }
    
    template<typename T, int dim>
    Point<T, dim> & operator+=(Point<T, dim> & lhs, const Point<T, dim> & rhs)
    {
        for(int i = 0; i < dim; i++)
        {
            lhs.a[i] += rhs.a[i];
        }
        
        cout << fixed << showpoint << setprecision(2);
        return lhs;
    }
    
    template<typename T, int dim>
    Point<T, dim> & operator-=(Point<T, dim> & lhs, const Point<T, dim> & rhs)
    {
        for(int i = 0; i < dim; i++)
        {
            lhs.a[i] -= rhs.a[i];
        }
        
        cout << fixed << showpoint << setprecision(2);
        return lhs;
    }
    
    template<typename T, int dim>
    const Point<T, dim> Point<T, dim>::operator*(T val) const
    {
        Point<T, dim> b;
        
        for(int i = 0; i < dim; i++)
        {
            b.a.push_back(a[i]);
        }
        
        return (b *= val);
    }
    
    template<typename T, int dim>
    const Point<T, dim> Point<T, dim>::operator/(T val) const
    {
        Point<T, dim> b;
        
        for(int i = 0; i < dim; i++)
        {
            b.a.push_back(a[i]);
        }
        
        return b /= val;
    }
    
    template<typename T, int dim>
    const Point<T, dim> operator+(const Point<T, dim> & lhs, const Point<T, dim> & rhs)
    {
        Point<T, dim> b;
        
        for(int i = 0; i < dim; i++)
        {
            b.a.push_back(lhs.a[i] + rhs.a[i]);
        }
        
        cout << fixed << showpoint << setprecision(2);
        return b;
    }
    
    template<typename T, int dim>
    const Point<T, dim> operator-(const Point<T, dim> & lhs, const Point<T, dim> & rhs)
    {
        Point<T, dim> b;
        
        for(int i = 0; i < dim; i++)
        {
            b.a.push_back(lhs.a[i] - rhs.a[i]);
        }
        
        return b;
    }
}
