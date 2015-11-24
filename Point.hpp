//
//  Point.hpp
//  Programming Assignment 4 Final
//
//  Created by Kathryn Chrisman on 10/31/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

namespace Clustering
{
    template <typename T, int dim>
    class Point
    {
    private:
        vector<T> a; // Values of the point's dimensions
        static const char POINT_VALUE_DELIM; // Delimiter in file you're reading in
        unsigned int _idPt; // id to keep track of our points
        static unsigned int _idGeneratorPt;
        
    public:
        // Constructors
        Point(); // Constructor takes a dimension as a parameter
        Point(const Point<T, dim> &); // Overloaded copy constructor
        Point &operator=(const Point<T, dim> &); // Overloaded assignment operator
        
        // Rewind ID
        static void rewindIdGen(){_idGeneratorPt--;}
        
        // Destructor
        ~Point(); 
        
        // Mutator methods
        void setValue(int, T);
        
        // Accessor methods
        double getValue(int d) const;
        int getDims() const;
        unsigned int get_ID() {return _idPt;}
        
        // distanceTo function to approximate the distance between two points
        T distanceTo(const Point &other) const;
        
        // Functions for overloaded comparison operators
        template<typename S, int d>
        friend bool operator==(const Point<S, d> &, const Point<S, d> &);
        
        template<typename S, int d>
        friend bool operator!=(const Point<S, d> &, const Point<S, d> &);
        
        template<typename S, int d>
        friend bool operator<(const Point<S, d> &, const Point<S, d> &);
        
        template<typename S, int d>
        friend bool operator>(const Point<S, d> &, const Point<S, d> &);
        
        template<typename S, int d>
        friend bool operator<=(const Point<S, d> &, const Point<S, d> &);
        
        template<typename S, int d>
        friend bool operator>=(const Point<S, d> &, const Point<S, d> &);
        
        // Functions for overloaded arithmetic operators
        Point &operator*=(T);
        
        const Point operator*(T) const;
        
        Point &operator/=(T);
        
        const Point operator/(T) const;
        
        template<typename S, int d>
        friend Point<S, d> &operator+=(Point<S, d> &, const Point<S, d> &);
        
        template<typename S, int d>
        friend const Point<S, d> operator+(const Point<S, d> &, const Point<S, d> &);
        
        template<typename S, int d>
        friend Point<S, d> &operator-=(Point<S, d> &, const Point<S, d> &);
        
        template<typename S, int d>
        friend const Point<S, d> operator-(const Point<S, d> &, const Point<S, d> &);
        
        // Overloaded [] operator
        T &operator[](int index);
        
        // Overloaded cout/cin stream operator
        template<typename S, int d>
        friend std::ostream &operator<<(std::ostream &, const Point<S, d> &);
        
        template<typename S, int d>
        friend std::istream &operator>>(std::istream &, Point<S, d> &);
    };
}

#include "Point.cpp"
#endif /* Point_hpp */
