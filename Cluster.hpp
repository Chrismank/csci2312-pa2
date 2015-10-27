//
//  Cluster.hpp
//  PA3
//
//  Created by Kathryn Chrisman on 9/17/15.
//  Copyright © 2015 Kathryn. All rights reserved.
// PA3

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
    private:
//        class Centroid
//        {
//        private:
//            PointPtr _centroid;
//            Dimension dim;
//            
//        public:
//            Centroid(Dimension d): dim(d), _centroid(new Point(d)) {}
//            ~Centroid() {delete _centroid;};
//            const Point get() const {return *_centroid;}
//            void set(const Point & point) {*_centroid = point;}
//            
//        };
        
        int size;
        LNodePtr points; // Pointer variable that points to the head of our linked list (head pointer)
        bool _release_points; // Specifies whether the class should deallocate points that are pointed to by its nodes- true then deallocate memory from one cluster and add this memory to the other cluster's link list
        unsigned int _id; // Identifies clusters
        static unsigned int _idGenerator;
        unsigned _dimensionality;
        Point _centroid;
        bool _centroidValid;
        static const char POINT_CLUSTER_ID_DELIM;
        
    public:
        // Overloaded constructor
        // Inner class Move represents the motion of a point from one cluster to another
        class Move
        {
            PointPtr _value;
            Cluster *_from;
            Cluster *_to;
            
        public:
            Move(const PointPtr & ptr, Cluster *from, Cluster *to): _value(ptr), _from(from), _to(to) {}
            void Perform(const PointPtr & value, Cluster *from, Cluster *to)
            {
                to->add(from->remove(value));
                from->setStatus(false);
            }
            
            // Invalidate the centroids of both cluster from and to
        };
        
        Cluster(unsigned d) : _centroid(_dimensionality), _dimensionality(d), size(0), points(nullptr), _id(_idGenerator++), _centroidValid(false){} // Default constructor to initialize Cluster to 0, points to nullptr, takes an int for the to initialize the number of dimensions of points in the cluster
        
        // Overloaded copy constructor
        Cluster(const Cluster & rhs) : _centroid(rhs._dimensionality)
        {   // This function creates a new lhs cluster
            // Set pointptrs equal, don't create a new point
            
            LNodePtr travelPtrR, travelPtrL;
            
            travelPtrL = new LNode;
            points = travelPtrL; // set our head pointer equal to the first node in our list that we just created
            
            travelPtrR = rhs.points; // sets travelptrR up to start at the head of the list
            size = rhs.size; // sets the sizes equal
            
            travelPtrL->next = new LNode;
            
            while(travelPtrR != nullptr)
            {
                travelPtrL->p = travelPtrR->p; // set the pointptr of this node equal to the pointptr of the rhs cluster
                travelPtrR = travelPtrR->next; // move to next node in rhs cluster
                
                if(travelPtrR != nullptr)
                {
                    travelPtrL->next = new LNode; // point my last travelptr to a new node
                    travelPtrL = travelPtrL->next;
                }
                
            }
            
            travelPtrL->next = nullptr; // the last node in the cluster on our lhs is now pointing to nullptr
            
            _id = _idGenerator++;
            
            setStatus(false);
           
        }
        
        Cluster &operator=(const Cluster &); // Overloaded assignment operator
       
        // ID getter
        unsigned int getID() const {return _id;}
        
        ~Cluster(); // Destructor - must be overloaded to deallocate memory
        
        // Set functions - allow you to add a point to one cluster while simultaneously deleting it from its previous cluster (i.e. c1.add(c2.remove(p));
        void add(const PointPtr &); // Add points by linked list
        void setCentroid(const Point & point);
        void setStatus(const bool & status) {_centroidValid = status;}
        
        
        // Accessor Functions
        const int getSize() {return size;}
        const Point getCentroid() const {return _centroid;}
        const unsigned getDimensionality() {return _dimensionality;}
        const LNodePtr getPoints() {return points;}
        const bool getStatus() {return _centroidValid;}
        
        // Compute Centroid
        void computeCentroid(const Cluster &);
        
        // Remove Functions
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
        
        // Function to pick points from a cluster that would serve as the initial set of centroids
        
        void pickPoints(int k, PointPtr *pointArray);
        
        // Methods for scoring the cluster
        
        double intraClusterDistance() const;
        
        friend double interClusterDistance(const Cluster & c1, const Cluster & c2);
        
        int getClusterEdges() const;
        
        friend double interClusterEdges(const Cluster & c1, const Cluster & c2);
        
    };

}
#endif /* Cluster_hpp */
