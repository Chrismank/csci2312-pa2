//
//  Point.cpp
//  PA3
//
//  Created by Kathryn Chrisman on 9/17/15.
//  Copyright © 2015 Kathryn. All rights reserved.
// PA3

#include "Point.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

namespace Clustering
{
    const char Point::POINT_VALUE_DELIM = ',';
    
    Point::Point(int d) // Constructor invoked when user inputs the number of dimensions
    {
        if (d == 0)
        {
            cout << "You must have at least one dimension." << endl;
        }
        
        dim = d;
        
        a = new double[dim]; // Sets the pointer equal to this dynamically allocated array with a certain number of dimensions
    }
    
    Point::Point(const Point &rhs) // Overloaded copy constructor
    {
        dim = rhs.dim; // Sets same number of dimensions to each object
        a = new double[dim]; // Makes the new object an array that is dynamically allocated
        
        for (int i = 0; i < dim; i++) // Copies the values from one array to another
        {
            a[i] = rhs.a[i];
        }
    }
    
    Point & Point::operator=(const Point & rhs) // Overloaded assignment operator
    {
        if(dim != rhs.dim)
        {
            delete [] a;
            a = new double[rhs.dim];
        }
        
        dim = rhs.dim;
        
        for(int i = 0; i < dim; i++)
        {
            a[i] = rhs.a[i];
        }
        
        return *this;
    }
    
    Point::Point(int dimension, double * something)
    {
       // Is this for our "universe" of points?
    }
    
    //Destructor
    
    Point::~Point()
    {
        if(a!= nullptr)
        {
            delete[] a; // Deletes the array
        }
        
    }
    
    // Accessor/Mutator methods
    // Change/get the values of private member variables
    
    void Point::setValue(int dimension, double newValue) // dimension is the actual dimension (i.e. x, y, z) that we are changing
    {
        if (dimension >= 1 && dimension <= dim)
        {
            a[dimension-1] = newValue;
        }
        
    }
    
    double Point::getValue(int dim) const
    {
        cout << a[dim-1] << endl;
        return a[dim-1];
    }
    
    int Point::getDims() const
    {
        return dim;
    }
    
    // Overloaded Stream Operators
    
    std::ostream &operator<<(std::ostream & out, const Point & p)
    {
        cout << fixed << showpoint << setprecision(1);
       
        int i = 0;
        for( ; i < (p.dim-1); i++)
        {
            out << p.a[i] << ", ";
        }
        
        out << p.a[i] << " ";
    
        return out;
    }
    
    std::istream &operator>>(std::istream & in, Point & p)
    {
        // adding in comma separated values of doubles, each line is a point, the number of values in each line are the number of dimensions in our point
        
                string value; // Take in each point in our line as a string
        
                double pt; // Holds the point values after we convert them from string to double
                
                int i = 1; // counter to hold the number of dimensions (starts at 1 since dimensions will be number of commas + 1)
        
                while(getline(in, value, Point::POINT_VALUE_DELIM)) // omit commas when reading lines, store points into "value"
                {
                    pt = stod(value); // convert the strings to doubles
                   // cout << "Value: " << pt << endl;
                    p.setValue(i++, pt);
                }
        
        return in;
        
    }
    
    // Overloaded [] Operator
    
    double & Point::operator[](int index)
    {
        return a[index-1];
    }
    
    // distanceTo Function to approximate the distance between two points
    
    double Point::distanceTo(const Point & other) const
    {
        if (other.dim == dim)
        {
            double sum = 0;
            
            for (int i = 0; i < dim; i++)
            {
                double diff = a[i] - other.a[i];
                sum += diff * diff; // sum = sum + (diff)^2 for every dimension
            }
            
            cout << fixed << showpoint << setprecision(2);
            return sqrt(sum);
        }
        
        return 0; // If the if statement is not satisfied
    }
    
    // Comparison Operators
    
    bool operator==(const Point & lhs, const Point & rhs)
    {
        if(lhs.dim != rhs.dim)
        {
            cout << "The dimensions must be the same to compare." << endl;
            return 0;
        }
        
        for (int i = 0; i < lhs.dim; i++)
        {
            if(lhs.a[i] != rhs.a[i])
            {
                return false;
            }
        }
        
        return true;
    }
    
    bool operator!=(const Point & lhs, const Point & rhs)
    {
        if(lhs.dim != rhs.dim)
        {
            cout << "The dimensions must be the same to compare." << endl;
            return 0;
        }
        
        for(int i = 0; i < lhs.dim; i++)
        {
            if(lhs.a[i] != rhs.a[i])
            {
                return true;
            }
        }
        
        return false;
    }
    
    bool operator>=(const Point & lhs, const Point & rhs)
    {
        if(lhs.dim != rhs.dim)
        {
            cout << "The dimensions must be the same to compare." << endl;
            return 0;
        }
        
        for(int i = 0; i < lhs.dim; i++)
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
    
    bool operator<=(const Point & lhs, const Point & rhs)
    {
        if(lhs.dim != rhs.dim)
        {
            cout << "The dimensions must be the same to compare." << endl;
            return 0;
        }
        
        for(int i = 0; i < lhs.dim; i++)
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
    
    bool operator>(const Point & lhs, const Point & rhs)
    {
        if(lhs.dim != rhs.dim)
        {
            cout << "The dimensions must be the same to compare." << endl;
            return 0;
        }
        
        for(int i = 0; i < lhs.dim; i++)
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
    
    bool operator<(const Point & lhs, const Point & rhs)
    {
        if(lhs.dim != rhs.dim)
        {
            cout << "The dimensions must be the same to compare." << endl;
            return 0;
        }
        
        for(int i = 0; i < lhs.dim; i++)
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
    
    Point & Point::operator*=(double val)
    {
        for(int i = 0; i < dim; i++)
        {
            (a[i] *= val);
        }

        cout << fixed << showpoint << setprecision(2) << endl;
        
        return *this;
    }
    
    Point & Point::operator/=(double val)
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
    
    Point & operator+=(Point & lhs, const Point & rhs)
    {
        if(lhs.dim != rhs.dim)
        {
            cout << "The dimensions must be the same." << endl;
            return lhs;
        }
        
        for(int i = 0; i < lhs.dim; i++)
        {
            lhs.a[i] += rhs.a[i];
        }
        
        cout << fixed << showpoint << setprecision(2);
        return lhs;
    }
    
    Point & operator-=(Point & lhs, const Point & rhs)
    {
        if(lhs.dim != rhs.dim)
        {
            cout << "The dimensions must be the same." << endl;
            return lhs;
        }
        
        for(int i = 0; i < lhs.dim; i++)
        {
            lhs.a[i] -= rhs.a[i];
        }
        
        cout << fixed << showpoint << setprecision(2);
        return lhs;
    }
    
     const Point Point::operator*(double val) const
    {
        Point b(dim);
        
        for(int i = 0; i < dim; i++)
        {
            b.a[i] = a[i];
        }
        
        return (b *= val);
    }
    
    const Point Point::operator/(double val) const
    {
        Point b(dim);
        
        for(int i = 0; i < dim; i++)
        {
            b.a[i] = a[i];
        }
        
        return b /= val;
    }

    const Point operator+(const Point & lhs, const Point & rhs)
    {
        if(lhs.dim != rhs.dim)
        {
            cout << "The dimensions must be the same." << endl;
            return 0;
        }
        
        Point b(lhs.dim);
        
        for(int i = 0; i < lhs.dim; i++)
        {
            b.a[i] = (lhs.a[i] + rhs.a[i]);
        }
        
        cout << fixed << showpoint << setprecision(2);
        return b;
    }
    
    const Point operator-(const Point & lhs, const Point & rhs)
    {
        if(lhs.dim != rhs.dim)
        {
            cout << "The dimensions must be the same." << endl;
            return 0;
        }
        
        Point b(lhs.dim);
        
        for(int i = 0; i < lhs.dim; i++)
        {
            b.a[i] = (lhs.a[i] - rhs.a[i]);
        }
        
        return b;
    }
}
