//
//  Point.cpp
<<<<<<< HEAD
//  PA3
//
//  Created by Kathryn Chrisman on 9/17/15.
//  Copyright © 2015 Kathryn. All rights reserved.
// PA3
=======
//  PA2
//
//  Created by Kathryn Chrisman on 9/17/15.
//  Copyright © 2015 Kathryn. All rights reserved.
// PA2
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea

#include "Point.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
<<<<<<< HEAD
#include <sstream>
=======
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea

using namespace std;

namespace Clustering
{
<<<<<<< HEAD
    const char Point::POINT_VALUE_DELIM = ',';
    
    Point::Point(int d) // Constructor invoked when user inputs the number of dimensions
    {
        if (d == 0)
=======
    Point::Point(int dimensions) // Constructor invoked when user inputs the number of dimensions
    {
        if (dimensions == 0)
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
        {
            cout << "You must have at least one dimension." << endl;
        }
        
<<<<<<< HEAD
        dim = d;
=======
        dim = dimensions;
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
        
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
    
<<<<<<< HEAD
    Point::Point(int dimension, double * something)
    {
       // Is this for our "universe" of points?
=======
    Point::Point(int dimensions, double * array)
    {
       // Optional
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
    }
    
    //Destructor
    
    Point::~Point()
    {
<<<<<<< HEAD
        if(a!= nullptr)
        {
            delete[] a; // Deletes the array
        }
        
=======
        delete[] a; // Deletes the array
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
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
<<<<<<< HEAD
        cout << fixed << showpoint << setprecision(1);
       
=======
        out << "(";
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
        int i = 0;
        for( ; i < (p.dim-1); i++)
        {
            out << p.a[i] << ", ";
        }
        
<<<<<<< HEAD
        out << p.a[i] << " ";
=======
        out << p.a[i] << ")";
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
    
        return out;
    }
    
    std::istream &operator>>(std::istream & in, Point & p)
    {
<<<<<<< HEAD
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
=======
        // adding in comma separated values of doubles, each line is a point, the number of values in each line are the number of dimensions in our point (must use getline, not >>)
        
        string point; // since getline only takes string arguments, we will have to read in the values and then convert to a double after
        
        // Open the file for input
        
        ifstream inputFile;
        inputFile.open(""); // place the name of the file inside of the quotations
        
        if(inputFile) // if the file opens, then execute
        {
            getline(inputFile, point, ','); // reads until a comma is encountered, each comma encountered will be a dimension
            p.dim++;
            while(inputFile)
            {
                cout << point << endl; // displays the value we just read in
                getline(inputFile, point, ','); // reads the next number in the list
                p.dim++;
            }
            
            inputFile.close();
        }
        
        else
        {
            cout << "Error opening file" << endl;
        }
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
        
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
        
<<<<<<< HEAD
        cout << fixed << showpoint << setprecision(2);
=======
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
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
