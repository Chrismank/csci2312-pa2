//
//  Cluster.hpp
//  PA2
//
//  Created by Kathryn Chrisman on 9/17/15.
//  Copyright © 2015 Kathryn. All rights reserved.
// PA2

#ifndef Cluster_hpp
#define Cluster_hpp

#include <stdio.h>
#include "Point.hpp"

namespace Clustering
{
    typedef Point *PointPtr;
    typedef struct LNode *LNodePtr;
    
    struct LNode
    {
        PointPtr p; // Pointer in each node that points to a point value
        LNodePtr next; // Node pointer that points from one node to the next node
    };
    
    class Cluster
    {
        int size;
        LNodePtr points; // Pointer variable that points to the head of our linked list (head pointer)
        
    public:
        Cluster(); // Default constructor to initialize Cluster to 0 and points to nullptr
        Cluster(const Cluster &); // Overloaded copy constructor
        Cluster &operator=(const Cluster &); // Overloaded assignment operator
        ~Cluster(); // Destructor - must be overloaded to deallocate memory
        
        // Set functions - allow you to add a point to one cluster while simultaneously deleting it from its previous cluster (i.e. c1.add(c2.remove(p));
        void add(const PointPtr &); // Add points by linked list
        const PointPtr &remove(const PointPtr &); // Removed points by linked list 
        void removeDuplicates(Cluster &); // Iterates through a linked list to check for and remove duplicates
        
        // Overloaded Operators
        
        // Stream Operators
        friend std::ostream &operator<<(std::ostream &, const Cluster &); // printing out a point
        friend std::istream &operator>>(std::istream &, Cluster &); // adding in a point
        
        // Set preserving operator (do not duplicate points in the space)
        friend bool operator==(const Cluster & lhs, const Cluster & rhs);
        
        // Set destructive operator (duplicate points in the space)
        Cluster &operator+=(const Cluster & rhs); // Union of 2 clusters
        Cluster &operator-=(const Cluster & rhs); // Asymmetric difference of 2 clusters
        
        // Set preserving operator
        Cluster &operator+=(const Point & rhs); // Add point
        Cluster &operator-=(const Point & rhs); // Remove Point
        
        // Self destructive operators
        friend const Cluster operator+(const Cluster & lhs, const Cluster & rhs);
        friend const Cluster operator-(const Cluster & lhs, const Cluster & rhs);
        
        friend const Cluster operator+(const Cluster & lhs, const PointPtr & rhs);
        friend const Cluster operator-(const Cluster & lhs, const PointPtr & rhs);
        
    };

}
#endif /* Cluster_hpp */
