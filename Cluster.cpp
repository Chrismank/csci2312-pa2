//
//  Cluster.cpp
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

#include "Cluster.hpp"
#include "Point.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
<<<<<<< HEAD
<<<<<<< HEAD
#include <fstream>
#include <string>
#include <sstream>

=======
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
=======
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f
using namespace std;

namespace Clustering
{
<<<<<<< HEAD
<<<<<<< HEAD
  
    unsigned int Cluster::_idGenerator = 1;
    
    const char Cluster::POINT_CLUSTER_ID_DELIM = ':';
    
    
    Cluster::~Cluster()
    {
        LNodePtr travelPtr, prevNode = nullptr;
=======
=======
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f
    Cluster::Cluster() // Default Constructor
    {
        size = 0; // size of our cluster initialized to 0
        points = nullptr; // head pointer initialzed to nullptr
    }
    
    Cluster::Cluster(const Cluster & rhs) // Overloaded Copy Constructor - copies the contents (PointPtrs) from the cluster on the rhs to create a new cluster on the lhs
    {
        // This function creates a new lhs cluster
        // Set pointptrs equal, don't create a new point
        
        LNodePtr travelPtrR, travelPtrL;
        
        travelPtrL = new LNode;
        points = travelPtrL; // set our head pointer equal to the first node in our list that we just created
        
        travelPtrR = rhs.points; // sets travelptrR up to start at the head of the list
        size = rhs.size; // sets the sizes equal
        
        points = travelPtrL;
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
        
    }
    
    Cluster::~Cluster()
    {
        LNodePtr travelPtr, smallerNode = nullptr;
<<<<<<< HEAD
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
=======
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f
        
        travelPtr = points;
        
        while(travelPtr != nullptr)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            prevNode = travelPtr; // set prev node up to equal our travelptr
            travelPtr = travelPtr->next; // set travelptr equal to the next node in the list
            delete prevNode; // delete the previous node
            
=======
            smallerNode = travelPtr;
            delete smallerNode;
            travelPtr = travelPtr->next;
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
=======
            smallerNode = travelPtr;
            delete smallerNode;
            travelPtr = travelPtr->next;
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f
        }
    }
    
    Cluster & Cluster::operator=(const Cluster & rhs)
    {
        // This function modifies an existing object, not create a new one
        // Set pointptrs equal, don't create a new point
        
        LNodePtr travelPtrR, travelPtrL;
        
       if(size == rhs.size || size != rhs.size) // delete cluster on lhs so you can assign values in rhs to it
       {
           LNodePtr travelPtr, smallerNode = nullptr;
           
           travelPtr = points;
           
           while(travelPtr != nullptr)
           {
               smallerNode = travelPtr;
               delete smallerNode;
               travelPtr = travelPtr->next;
           }
           
           travelPtrL = new LNode;
           points = travelPtrL; // set our head pointer equal to the first node in our list that we just created
        }
        
        travelPtrR = rhs.points; // sets travelptrR up to start at the head of the list
        size = rhs.size; // sets the sizes equal
        
        points = travelPtrL;
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
        
        travelPtrL->next = nullptr; // The last node in the cluster on our lhs is now pointing to nullptr
        
        return *this;
    }
    
    void Cluster::add(const PointPtr & value) // Add a node to the linked list (PointPtrs are contained in our nodes) - Refer to page 1035 in Starting Out W C++
    {
        LNodePtr newNode; // This is the pointer that will point to the new node in our list
        LNodePtr travelPtr; // Used to travel down the linked list in search of the last node
        LNodePtr smallerNode = nullptr; // Points to the node in our list holding a smaller value than our new node, which allows us to insert the new node in between here and the next node
<<<<<<< HEAD
<<<<<<< HEAD
=======
    
 
        ++ size; // Adds 1 to the size of the cluster
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
=======
    
 
        ++ size; // Adds 1 to the size of the cluster
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f
        
        // Here is where we will make a new node and store the pointer to our point value in it. The pointptr is represented by member variable p
        
        newNode = new LNode;
        newNode->p = value;
        
        // Here we're checking to see if our head pointer points to nullptr, indicating that there are no nodes in our list. If it does, the new node we created is now the first in our list
    
        if(points == nullptr)
        {
            points = newNode; // now our head pointer is pointing to this new node
            newNode->next = nullptr; // this new node is last in our list and is now pointing to nullptr
        }
        
        // Otherwise, insert newNode somewhere else in our list, keeping our points in order
        
        else
        {
            travelPtr = points; // Initialize travelPtr to the head of our list, so it can travel down the list and find where we want to insert our new node
            smallerNode = nullptr;
            
            while(travelPtr != nullptr && *(travelPtr->p) < *(value)) // while our travelptr points to a node, and the value pointed to by our pointptr is less than the new value, continue looping
            {
                smallerNode = travelPtr;
                travelPtr = travelPtr->next;
            }
            
            // If the new node is the smallest, we need to insert it at the start of the list
            
            if(smallerNode == nullptr) // This means that we've gone through the whole list without finding a point larger than the point we're inserting
            {
                points = newNode; // head pointer is now pointing to our new node
                newNode->next = travelPtr; // Our new node is now pointing to the next node in our list (travelptr is one ahead of new node)
            }
            
            // If the new node is the largest, we need to insert it at the end of the list
            
            else
            {
                smallerNode->next = newNode; // Point the final node to the new node
                newNode->next = travelPtr; // Point the new node to nullptr (travelptr is one ahead of new node)
            }
            
        }
    
<<<<<<< HEAD
<<<<<<< HEAD
        size++; // Adds 1 to the size of the cluster
=======
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
=======
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f
    }
    
    
    const PointPtr & Cluster::remove(const PointPtr & value) // Remove a node from the linked list - refer to page 1039 in Starting Out w C++
    {
        LNodePtr travelPtr; // Goes through the list
        LNodePtr smallerNode = nullptr; // Points to the node in the list that is before the node pointed to by the travelptr
        
        // Checks to see if there is anything in our list, if not then simply return the value without changing anything
        
        if(points == nullptr)
        {
            return value;
        }
        
        // Checks to see if the first node is the one being deleted. If so, we need to make sure our head pointer is now pointing to the new first node in our list
        
        if(*(points->p) == *(value))
        {
            travelPtr = points->next; // travelptr now points to the node that our head pointer was pointing to
            delete points; // delete the old head node
            points = travelPtr; // new head node is now the travelptr
            
            size--; // decrease size of our cluster by 1
        }
        
        // If the value being deleted is somewhere in the middle or at the end of our node
        
        else
        {
            
            travelPtr = points; // make sure travelptr is starting out at the head of our list
            
        while(travelPtr != nullptr && *(travelPtr->p) != *(value)) // loops through while our travelptr doesn't hit the end of our list and while the travel pointer doesn't equal the point we want to delete
        {
            smallerNode = travelPtr;
            travelPtr = travelPtr->next;
        }
        
        // Once our travelptr hits the node we want to delete, we need to have our smallerPtr point to the next node that our travelptr was pointing to (the one after the node we want to delete)
        
        if(travelPtr != nullptr)
        {
            smallerNode->next = travelPtr->next;
            delete travelPtr; // node is no longer a part of our linked list and therefore needs to be deleted
        }
            
            size--; // Decrease the size of our cluster by 1
    
        }

        return value;
}
    
    bool operator==(const Cluster & lhs, const Cluster & rhs) // Comparing the points in two clusters to see if the two clusters are equal
    {
        LNodePtr travelPtrL, travelPtrR; // travelPtrL is a pointer corresponding to the lhs cluster, and travelPtrR is a pointer corresponding to the rhs cluster
        
        if(lhs.size != rhs.size) // If the sizes of the two clusters aren't equal, they are not the same
        {
            return false;
        }
        
        else
        {
        
            travelPtrL = lhs.points; // sets travelPtrL to the head of cluster on left hand side
            travelPtrR = rhs.points; // sets travelPtrR to the head of cluster on the right hand side
            
            while(travelPtrL && travelPtrR) // Will go through each linked list until it hits nullptr
            {
                if(travelPtrL->p == travelPtrR->p) // If the addresses at each node are equal, continue iterating, else return false
                    {
                        travelPtrL = travelPtrL->next;
                        travelPtrR = travelPtrR->next;
                    }
                
                else
                {
                    return false;
                }
               
            }
            
            return true;
        }
    }
        
    const Cluster operator+(const Cluster & lhs, const Cluster & rhs)
        {
            LNodePtr travelPtrR, travelPtrL; // travelPtrR corresponds to rhs cluster, travelPtrL corresponds to lhs cluster
            
            travelPtrR = rhs.points; // sets up our travel pointer to start at the head of the rhs cluster
            travelPtrL = lhs.points; // sets up our travel pointer to start at the head of the lhs cluster
            
<<<<<<< HEAD
<<<<<<< HEAD
            unsigned dimensions = lhs._dimensionality;
            
            Cluster newCluster = Cluster(dimensions); // creates the new cluster that will contain all points in the lhs cluster + all points in the rhs cluster
=======
            Cluster newCluster = Cluster(); // creates the new cluster that will contain all points in the lhs cluster + all points in the rhs cluster
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
=======
            Cluster newCluster = Cluster(); // creates the new cluster that will contain all points in the lhs cluster + all points in the rhs cluster
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f
            
            while(travelPtrR) // add rhs cluster to new cluster
            {
                newCluster.add(travelPtrR->p);
                travelPtrR = travelPtrR->next;
            }
            
            while(travelPtrL) // add lhs cluster to new cluster
            {
                newCluster.add(travelPtrL->p);
                travelPtrL = travelPtrL->next;
            }
            
            return newCluster; // returns the new cluster with the values in both the lhs and rhs
         
        }
    
    Cluster & Cluster::operator+=(const Cluster & rhs) // Union of 2 clusters - only those values that are unique are added
    {
        LNodePtr travelPtrR; // travelPtrR corresponds to rhs cluster
        
        travelPtrR = rhs.points; // sets up our travel pointer to start at the head of the rhs cluster
    
        // Since we are adding the cluster on the rhs to the cluster on the lhs, we need to pass each pointptr from the linked list on the rhs cluster to the add() function so that they will be added in order to the lhs cluster
        
        // Since the linked lists contain different values, we cannot directly compare each element. Therefore, we will add all items from the rhs to the lhs and then we will check for and delete duplicates
        
        while(travelPtrR)
        {
            add(travelPtrR->p);
            travelPtrR = travelPtrR->next;
        }
        
        // Now that all items are added from the rhs, we will check for duplicates and remove them
  
        removeDuplicates(*this);
        
        // Return the lhs cluster, which now contains only the distinct values in the rhs cluster
        
        return *this;
    }
    
    void Cluster::removeDuplicates(Cluster & value)
    {
        LNodePtr travelPtr, smallerNode;
        
        travelPtr = value.points->next; // Sets our travelPtr to the node after the head of our cluster
        smallerNode = value.points; // Sets our smaller node to the head of our cluster
    
        
        while(travelPtr != nullptr && *(smallerNode->p) <= *(travelPtr->p)) // while our travelptr points to a node, and the value pointed to in our smallerNode is less than/equal to next value (pointed to by our travelPtr), continue looping
        {
            if(*(smallerNode->p) == *(travelPtr->p)) // If the point values are equal, remove one and then move to the next two nodes
            {
                remove(smallerNode->p);
                smallerNode = travelPtr;
                travelPtr = travelPtr->next;
            }
            
            else // if the points are not equal, do nothing and move on to the next two nodes
            {
                smallerNode = travelPtr;
                travelPtr = travelPtr->next;
            }
         
        }
        
    }

    const Cluster operator-(const Cluster & lhs, const Cluster & rhs)
    {
        // This operator is set destructive, so it will not remove all of the instances of a point in the lhs
        
        LNodePtr travelPtrR, travelPtrL; // travelPtrR corresponds to rhs cluster, travelPtrL corresponds to lhs cluster
        
        travelPtrR = rhs.points; // sets up our travel pointer to start at the head of the rhs cluster
        travelPtrL = lhs.points; // sets up our travel pointer to start at the head of the lhs cluster
        
<<<<<<< HEAD
<<<<<<< HEAD
        unsigned dimension = rhs._dimensionality; // Sets the dimensionality of the clusters passed in and the cluster that is returned equal to each other
        
        Cluster newCluster = Cluster(dimension); // creates the new cluster that will contain only points unique to the lhs and rhs cluster
        
        Cluster tempCluster = Cluster(dimension); // creates a temporary cluster
=======
        Cluster newCluster = Cluster(); // creates the new cluster that will contain only points unique to the lhs and rhs cluster
        
        Cluster tempCluster = Cluster(); // creates a temporary cluster
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
=======
        Cluster newCluster = Cluster(); // creates the new cluster that will contain only points unique to the lhs and rhs cluster
        
        Cluster tempCluster = Cluster(); // creates a temporary cluster
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f
        
        tempCluster = rhs; // sets the temp cluster equal to the rhs cluster
        
        newCluster = lhs; // sets new cluster equal to the lhs cluster
        
        while(travelPtrL)
        {
            
            travelPtrR = tempCluster.points;
            
            while(travelPtrR)
            {
                if(*(travelPtrR->p) == *(travelPtrL->p))
                {
                    newCluster.remove(travelPtrL->p);
                    tempCluster.remove(travelPtrR->p);
                }
                
                travelPtrR = travelPtrR->next;
            }
            
            
            travelPtrL = travelPtrL->next;
        }
        
        return newCluster; // returns the new cluster with the values in both the lhs and rhs
    }
    
    Cluster & Cluster::operator-=(const Cluster & rhs) // Asymmetric difference
    {
        // If there is a value present in both the rhs and the lhs (intersection) then we need to remove the point from the lhs cluster 
        
        LNodePtr travelPtrR, travelPtrL; // travelPtrR corresponds to rhs cluster
        
        travelPtrR = rhs.points; // sets up our travel pointer to start at the head of the rhs cluster
        travelPtrL = points;
        // We are calculating the asymmetric difference - so if a value is found to be in both clusters, it needs to be removed (lhs - rhs = the points that are in the lhs but not in the rhs)
        
        while(travelPtrL)
        {
            
            travelPtrR = rhs.points;
            
            while(travelPtrR)
            {
                if(*(travelPtrR->p) == *(travelPtrL->p))
                {
                    remove(travelPtrL->p);
                }
                
                travelPtrR = travelPtrR->next;
            }
           
            
            travelPtrL = travelPtrL->next;
        }
        
        // Return the lhs cluster, which now contains only the distinct values in the lhs cluster
        
        return *this;
    }
    
    Cluster & Cluster::operator+=(const Point & rhs)
    {
        // Needs to preserve the set
        
        // Our add function takes a pointptr as an argument, not a point, so we need to make sure this point is pointed to by a pointptr, and then pass this pointptr to our add() function
        
        LNodePtr travelPtrL;
        PointPtr newPoint;
        travelPtrL = points;
        
        newPoint = new Point(rhs);
        
        while(travelPtrL)
        {
            if(*(travelPtrL->p) == *(newPoint)) // if this point is equal to a point that is already in our cluster, we don't want to add it
            {
                return *this;
            }
            
            travelPtrL = travelPtrL->next;
        }
        
        add(newPoint);
        
        return *this;
    }
    
    Cluster & Cluster::operator-=(const Point & rhs)
    {
        // Needs to preserve the set - removes all points that match the argument
        
        // Our remove function takes a pointptr as an argument, not a point, so we need to make sure this point is pointed to by a pointptr, and then pass this pointptr to our remove() function
        LNodePtr travelPtrL = points;
        PointPtr newP = new Point(rhs);
        
        while(travelPtrL) // loops through the cluster
        {
            remove(newP); // removes all points equal to the argument (preserves the set)
            travelPtrL = travelPtrL->next;
        }
        
        return *this;
    }
    
    const Cluster operator+(const Cluster & lhs, const PointPtr & rhs)
    {
        
        // Cluster = cluster lhs + pointptr rhs
        
       LNodePtr travelPtrL;
       
        travelPtrL = lhs.points;
        
<<<<<<< HEAD
<<<<<<< HEAD
        unsigned dimension = lhs._dimensionality;
        
        Cluster newCluster = Cluster(dimension);
=======
        Cluster newCluster = Cluster();
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
=======
        Cluster newCluster = Cluster();
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f
        
        while(travelPtrL) // loop through and add all values of the lhs cluster to the new cluster
        {
            newCluster.add(travelPtrL->p);
            travelPtrL = travelPtrL->next;
        }
       
        newCluster.add(rhs); // now add the new pointpointer to our new cluster
        
        return newCluster;
    }
    
    const Cluster operator-(const Cluster & lhs, const PointPtr & rhs)
    {
        // Cluster = cluster lhs - pointptr rhs
        
        LNodePtr travelPtrL;
        
        travelPtrL = lhs.points;
        
<<<<<<< HEAD
<<<<<<< HEAD
        unsigned dimensions = lhs._dimensionality;
        
        Cluster newCluster = Cluster(dimensions);
=======
        Cluster newCluster = Cluster();
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
=======
        Cluster newCluster = Cluster();
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f
        
        while(travelPtrL) // loop through and add all values of the lhs cluster to the new cluster
        {
            newCluster.add(travelPtrL->p);
            travelPtrL = travelPtrL->next;
        }
        
        newCluster.remove(rhs); // now remove the point from this new cluster
        
        return newCluster;
    }
    
    std::ostream &operator<<(std::ostream & out, const Cluster & c) // Prints out the points in a cluster (linked list) - page 1034 of Starting Out w c++
    {
        LNodePtr travelPtr; // This is the pointer that will move through each point in our linked list
        
        travelPtr = c.points; // Travel pointer starts at the head
        
<<<<<<< HEAD
<<<<<<< HEAD
        if(c.points != nullptr)
        {
            while(travelPtr) // while our travel pointer is pointing to a node, continue looping
            {
                out << *(travelPtr->p) << Cluster::POINT_CLUSTER_ID_DELIM << " " << c.getID() << endl; // cout the point that pointptr p is pointing to
            
                travelPtr = travelPtr->next; // Move to the next node
            }
        
            return out;
        }
        
        else
        {
            cout << c.getID() << endl;
            return out;
        }
    }
    
    std::istream &operator>>(std::istream & in, Cluster & c) // adding in a cluster
    {
        // adding in comma separated values of doubles, each line is a point, the number of values in each line are the number of dimensions in our point
    
        string line; // since getline only takes string arguments, we will have to read in the values and then convert to a double after
    
        // Open the file for input
    
        if(in) // if the file opens, then execute
        {
            while(getline(in, line)) // looks at each line as a whole
            {
              // converts the line to a stringstream
                stringstream linestream(line);
               
                string value; // Take in each point in our line as a string
                
                PointPtr p = new Point(5);
                
                //cout << "linestream values: " << linestream.str() << endl;
                
                linestream >> *p;
                
               // cout << "line: " << line << endl;
                
                c.add(p);
                
            }
            
        }
            
        else
            {
                cout << "Error opening file" << endl;
            }
        
    return in;

    }
    
    // Functions for KMeans Algorithm
    
    void Cluster::pickPoints(int k, PointPtr *pointArray)
    {
        // Count points (size)
        // Divide by k to get step size "step"
        // For every x points, assign a centroid
        
        LNodePtr travelNode;
        //travelNode = points;
        
        int step;
        int newStep = 1;
        int count;
        
        // Checks to see if k is greater than the number of points in the cluster
        if(k > size)
        {
            cout << "K value is greater than the number of points. K will be changed to equal the number of points." << endl;
            k = size;
        }
        
        step = size/k;
        
        // Loop through and assign values to our array
//        for(int i = 0; i < k; i++)
//        {
//            pointArray[i] = travelNode->p;
//          //  cout << "Point: " << *pointArray[i] << endl;
//            travelNode = travelNode->next;
//        }
        
        
        for(int i = 0; i < k; i++)
        {
           // cout << "step going into iteration: " << newStep << endl;
            travelNode = points;
            count = 1;
            
                while(travelNode)
                {
                   // cout << "Point: " << *travelNode->p << endl;
                    if(count == newStep)
                    {
                        pointArray[i] = travelNode->p;
                    }
                    
                    count++;
                    travelNode = travelNode->next;
                }
            
            newStep+=step;
        }
       
    
        for(int i = 0; i < k; i++)
        {
            cout << "Point array check: " << *pointArray[i] << endl;
        }
    }
    
    int Cluster::getClusterEdges() const
    {
        int edges = size * (size-1)/2;
        
        if(edges == 0)
        {
            edges = 1;
        }
        
        return edges; // size = the size of the cluster
    }
    
    double interClusterEdges(const Cluster & c1, const Cluster & c2)
    {
        return(c1.size * c2.size);
    }
    
    double Cluster::intraClusterDistance() const
    {
        // Calculates the sum of the distances between every two points in the cluster - use two while loops
        LNodePtr OuterTravelNode = points; // sets up our travel node to start at the head of the cluster
        LNodePtr InnerTravelNode;
        
        double sum;
        
        while(OuterTravelNode)
        {
            InnerTravelNode = points;
            
            while(InnerTravelNode)
                {
                    sum += (*OuterTravelNode->p).distanceTo(*InnerTravelNode->p);
                    InnerTravelNode = InnerTravelNode->next;
                }
                
            OuterTravelNode = OuterTravelNode->next;
            
        }
        
        cout << "IntraCluter Distance: " << sum/2 << endl;
        
        return (sum/2);
    }
    
    double interClusterDistance(const Cluster & c1, const Cluster & c2)
    {
        // set up our travel pointers to start at the head of each of our clusters
        
        LNodePtr travelNodec1 = c1.points;
        LNodePtr travelNodec2;
        
        double sum;
        
        while(travelNodec1)
        {
            travelNodec2 = c2.points;
            
            while(travelNodec2)
            {
                sum += (*travelNodec1->p).distanceTo(*travelNodec2->p);
                travelNodec2 = travelNodec2->next;
            }
            
            travelNodec1 = travelNodec1->next;
        }
        
        return sum;
    }
    
    void Cluster::setCentroid(const Point & point)
    {
       // cout << "Point: " << point << endl;
       // cout << "Point Dimensions: " << point.getDims() << endl;
        setStatus(true);
        _centroid = point;
    }
    
    void Cluster::computeCentroid(const Cluster & c)
    {
        // Centroid is an imaginary point that is the mean of all the points in a cluster. However big our cluster is will be the number we divide the dimensions in our centroid by.
        cout << "ComputeCentroid function called" << endl;
        LNodePtr travelNode = c.points; // This LNodePtr will travel through the linked list of our cluster and access the points in each of our nodes
        
        Point tempCentroid(_dimensionality);
        
        while(travelNode)
        {
            tempCentroid += *(travelNode->p); // assigning our pointptr to a new, dynamically allocated point that is the sum of the point values in our cluster c
            
            travelNode = travelNode->next;
        }
    
        (tempCentroid) /= c.size;
        
        setStatus(true);
        setCentroid(tempCentroid);
    
    }
=======
=======
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f
        while(travelPtr) // while our travel pointer is pointing to a node, continue looping
        {
            out << *(travelPtr->p) << endl; // cout the point that pointptr p is pointing to
            
            travelPtr = travelPtr->next; // Move to the next node
        }
        
        return out;
    }
    
//    std::istream &operator>>(std::istream & in, Cluster & c) // adding in a cluster
//    {
//
//    }
    
<<<<<<< HEAD
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
=======
>>>>>>> 569579b153efe737b653565f27b287ccaf53517f

}
