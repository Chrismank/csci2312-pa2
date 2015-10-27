//
//  Point.hpp
<<<<<<< HEAD
<<<<<<< HEAD
//  PA3
//
//  Created by Kathryn Chrisman on 9/17/15.
//  Copyright © 2015 Kathryn. All rights reserved.
// PA3
=======
=======
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f
//  PA2
//
//  Created by Kathryn Chrisman on 9/17/15.
//  Copyright © 2015 Kathryn. All rights reserved.
// PA2
<<<<<<< HEAD
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
=======
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <iostream>

namespace Clustering
{
<<<<<<< HEAD
<<<<<<< HEAD
    
=======
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
=======
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f
    class Point
    {
    private:
        double *a; // values of the point's dimensions
        int dim; // number of dimensions
<<<<<<< HEAD
<<<<<<< HEAD
        static const char POINT_VALUE_DELIM;
        
    public:
        // Constructors
        Point(int d); // Dynamically allocated array and int dim
=======
=======
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f
        
    public:
        // Constructors
        Point(int); // Dynamically allocated array and int dim
<<<<<<< HEAD
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
=======
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f
        Point(int, double*); // OPTIONAL
        
        Point(const Point &); // Overloaded copy constructor
        Point &operator=(const Point &); //Overloaded assignment operator
        
        // Destructor
        ~Point(); // Destructor (needs to be overloaded)
        
        // Mutator methods
        void setValue(int, double);
       
        // Accessor methods
        double getValue(int) const;
        int getDims() const;
        
        // distanceTo function to approximate the distance between two points
        double distanceTo(const Point &other) const;
        
        // Functions for overloaded comparison operators
        friend bool operator==(const Point &, const Point &);
        
        friend bool operator!=(const Point &, const Point &);
        
        friend bool operator<(const Point &, const Point &);
        
        friend bool operator>(const Point &, const Point &);
        
        friend bool operator<=(const Point &, const Point &);
        
        friend bool operator>=(const Point &, const Point &);
        
        // Functions for overloaded arithmetic operators
        Point &operator*=(double);
        
        const Point operator*(double) const;
        
        Point &operator/=(double);
        
        const Point operator/(double) const;
        
        friend Point &operator+=(Point &, const Point &);
        
        friend const Point operator+(const Point &, const Point &);
        
        friend Point &operator-=(Point &, const Point &);
        
        friend const Point operator-(const Point &, const Point &);
        
        // Overloaded cout/cin stream operator
        
        friend std::ostream &operator<<(std::ostream &, const Point &);
        
        friend std::istream &operator>>(std::istream &, Point &);
        
        // Overloaded [] operator
        
        double &operator[](int index);
    };
}

#endif /* Point_hpp */
