//  Cluster.cpp
//  Programming Assignment 4 Final
//  Created by Kathryn Chrisman on 10/31/15.
//  Copyright © 2015 Kathryn. All rights reserved.

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <forward_list>

#include "Point.hpp"
#include "Cluster.hpp"
#include "Exceptions.hpp"

using namespace std;

namespace Clustering
{
    template<typename T, int dim>
    unsigned int Cluster<T, dim>::numberImported()
    {
        return _numImported++;
    }
    
    template<typename T, int dim>
    unsigned int Cluster<T, dim>::numberFailed()
    {
       return _numFailed++;
    }
    
    template<typename T, int dim>
    unsigned int Cluster<T, dim>::_idGenerator = 1;
    
    template<typename T, int dim>
    const char Cluster<T, dim>::POINT_CLUSTER_ID_DELIM = ':';
    
    template<typename T, int dim>
    Cluster<T, dim>::~Cluster<T, dim>()
    {
        
    }
    
    template<typename T, int dim>
    Cluster<T, dim>::Cluster()
    {
        size = 0;
        _id = _idGenerator++;
        _centroidValid = false;
    }
    
    template<typename T, int dim>
    Cluster<T, dim>::Cluster(const Cluster<T, dim> & rhs) // Overloaded copy constructor
    {
        auto it = rhs.list.begin();
        
        for( ; it != rhs.list.end(); ++it)
        {
            add(*it);
        }
        
        _id = rhs._id;
        size = rhs.size;
        setStatus(false); // Centroid status set to false
    }
    
    template<typename T, int dim>
    Cluster<T, dim> & Cluster<T, dim>::operator=(const Cluster<T, dim> & rhs)
    {
        // Assign contents of rhs list to lhs list and set sizes equal
        
        list.assign(rhs.list.begin(), rhs.list.end());
        
        size = rhs.size;

        return *this;
    }
    
    template<typename T, int dim>
    void Cluster<T, dim>::add(const Point<T, dim> & value)
    {
        // If the list is empty, we will insert the point at the front
        if(list.empty() == true)
        {
            list.push_front(value);
        }
        
        // Otherwise, insert the point somewhere else in our list, keeping our points in order
        
        else
        {
            auto it = list.begin(); // Start at the head of our list
            auto before = list.before_begin(); // Start at one before the head of our list
            
            // While our list isn't at the end and the values in the list are less than the value we're inserting, continue looping
            while(it != list.end() && (*it) < (value))
            {
                before = it;
                ++it;
            }

            // If the new point is the smallest, we need to insert it at the start of the list
            if(before == list.before_begin())
            {
                list.push_front(value);
            }
            
            // If the new point is the largest, we need to insert it at the end of the list
            else
            {
                list.insert_after(before, value);
            }
            
        }
        
        size++; // Add 1 to the size of the cluster
    }
    
    template<typename T, int dim>
    const Point<T, dim> & Cluster<T, dim>::remove(const Point<T, dim> & value)
    {
        // Check to see if there is anything in our list, if not then simply return the value without changing anything
        
        if(list.empty() == true)
        {
            throw RemoveFromEmptyEx();
            return value;
        }
        
        else
        {
            auto it = list.begin();
            
            for( ; it != list.end(); ++it)
            {
                if(*it == value) // id values and coordinates in overloaded == are being compared before removing
                {
                    list.remove(value);
                }
            }
            
        }
        
        size--; // Decrease the size of our cluster by 1
        
        return value;
    }
    
    template<typename T, int dim>
    bool operator==(const Cluster<T, dim> & lhs, const Cluster<T, dim> & rhs)
    {
        // Comparing the points in two clusters to see if the two clusters are equal
       
        if(lhs.size != rhs.size) // If the sizes of the two clusters aren't equal, they are not the same
        {
            return false;
        }
        
        else
        {
            auto it = rhs.list.begin();
            auto it2 = lhs.list.begin();
         
            while(it != rhs.list.end() && it2 != lhs.list.end()) // Go through each linked list
            {
                if(*it == *it2) // If the addresses at each node are equal, continue iterating, else return false
                {
                    ++it;
                    ++it2;
                }
                
                else
                {
                    return false;
                }
                
            }
            
            return true;
        }
    }
    
    template<typename T, int dim>
    const Cluster<T, dim> operator+(const Cluster<T, dim> & lhs, const Cluster<T, dim> & rhs)
    {
        Cluster<T, dim> newCluster; // newCluster now contains all points in lhs cluster
        
        auto it = rhs.list.begin();
        
        for( ; it != rhs.list.end(); ++it) // add all points in rhs cluster to newCluster
        {
            newCluster.add(*it);
        }
        
        return newCluster;
        
    }
    
    template<typename T, int dim>
    Cluster<T, dim> & Cluster<T, dim>::operator+=(const Cluster<T, dim> & rhs)
    {
        // Union of 2 clusters - only those values that are unique are added
      
        // Loop through and count the number of duplicates
        auto it = rhs.list.begin();
        auto it2 = list.begin();
        int count = 0;
        
        for( ; it2 != list.end() ; ++it2)
        {
            auto it3 = rhs.list.begin();
            
            cout << "it2: " << *it2 << endl;
            
            for( ; it3 != rhs.list.end(); ++it3)
            {
                cout << "it3: " << *it3 << endl;
                
                if(*it2 == *it3)
                {
                    count++;
                }
            }
        }
        
        // Add all values from rhs cluster to this cluster
        for( ; it != rhs.list.end(); ++it)
        {
           add(*it);
        }
        
        // Remove duplicate elements of the list
        list.unique();
        
        // Update size of cluster
        size = size-count;
        
        return *this;
    }
    
    template<typename T, int dim>
    void Cluster<T, dim>::removeDuplicates(Cluster<T, dim> & value)
    {
        auto it = ++ value.list.begin();
        auto before = value.list.begin();
        
        // While our iterator points to a node, and the value pointed to before is less than/equal to next value, continue looping
        while(it != value.list.end() && *before <= *it)
        {
            if(*before == *it) // If the point values are equal, remove one and then move to the next two nodes
            {
                remove(*before);
                before = it;
                ++it;
                cout << "list after iteration: " << value << endl;
            }
            
            else // If the points are not equal, do nothing and move on to the next two nodes
            {
                before = it;
                ++it;
            }
            
            
        }
        
    }
    
    template<typename T, int dim>
    const Cluster<T, dim> operator-(const Cluster<T, dim> & lhs, const Cluster<T, dim> & rhs)
    {
        // This operator is set destructive, so it will not remove all of the instances of a point in the lhs
        
        Cluster<T, dim> newCluster; // newCluster now contains all points in lhs cluster
      
        auto it = rhs.list.begin();
        
        for( ; it != lhs.list.end(); ++it)
        {
            auto it2 = rhs.list.begin();
            
            for( ; it2 != rhs.list.end(); ++it2)
            {
                if(*it == *it2)
                {
                    newCluster.remove(*it);
                }
            }
            
        }
        
        return newCluster;
    }
    
    template<typename T, int dim>
    Cluster<T, dim> & Cluster<T, dim>::operator-=(const Cluster<T, dim> & rhs)
    {
        // Asymmetric difference - if there is a value present in both the rhs and the lhs (intersection) then we need to remove the point from the lhs cluster
       
        auto it = list.begin();
        
        while(it != list.end())
        {
            auto it2 = rhs.list.begin();
            
            for( ; it2 != rhs.list.end(); ++it2)
            {
                if(*it == *it2)
                {
                   *this = *this - *it2;
                }
            }
            
            ++it;
        }
        
       return *this;
    }
    
    template<typename T, int dim>
    Cluster<T, dim> & Cluster<T, dim>::operator+=(const Point<T, dim> & rhs)
    {
        add(rhs);

        return *this;
    }
    
    template<typename T, int dim>
    Cluster<T, dim> & Cluster<T, dim>::operator-=(const Point<T, dim> & rhs)
    {
        remove(rhs);
        
        return *this;
    }
    
    template<typename T, int dim>
    const Cluster<T, dim> operator+(const Cluster<T, dim> & lhs, const Point<T, dim> & rhs)
    {
        // newCluster = cluster + point
        
        Cluster<T, dim> newCluster; // copy values of lhs cluster into a temporary cluster before adding
        
        newCluster.add(rhs);
        
        return newCluster;
    }
    
    template<typename T, int dim>
    const Cluster<T, dim> operator-(const Cluster<T, dim> & lhs, const Point<T, dim> & rhs)
    {
        // newCluster = cluster - point
        
        Cluster<T, dim> newCluster; // copy values of lhs cluster into a temporary cluster before removing
        
        newCluster.remove(rhs);
        
        return newCluster;
    }
    
    template<typename T, int dim>
    std::ostream &operator<<(std::ostream & os, const Cluster<T, dim> & c)
    {
        // Prints out the points in the cluster
        
        // If the list isn't empty
        if(c.list.empty() != true)
        {
            auto it = c.list.begin();
        
            for( ; it != c.list.end(); ++it)
            {
                os << *it << Cluster<T, dim>::POINT_CLUSTER_ID_DELIM << " " << c.getID() << endl;
            }
            
            return os;
        }
        
        else
        {
            os << c.getID() << endl;
            return os;
        }
        
    }
    
    template<typename T, int dim>
    std::istream &operator>>(std::istream & in, Cluster<T, dim> & c) // adding in a cluster
    {
        // Adding in comma separated values of doubles, each line is a point, the number of values in each line are the number of dimensions in our point
        
        string line;
        
        // Open the file for input
        
        if(in)
        {
            while(getline(in, line))
            {
                stringstream linestream(line);
                string value;
                
                try
                {
                    Point<T, dim> p;
                    linestream >> p;
                    c.add(p);
                    c.numberImported();

                } catch (DimensionalityMismatchEx e)
                {
                    c.numberFailed();
                    cout << e << endl;
                }
            }
            
        }
        
        else
        {
            cout << "Error opening file" << endl;
        }
        
        return in;
        
    }
    
    template<typename T, int dim>
    void Cluster<T, dim>::pickPoints(int k, vector<Point<T, dim>> *pointArray)
    {
        // Count points (size)
        // Divide by k to get step size "step"
        // For every x points, assign a centroid
        
        int step;
        int newStep = 1;
        int count;
    
        if(k > size)
        {
            cout << "K value is greater than the number of points. K will be changed to equal the number of points." << endl;
            k = size;
        }
        
        step = size/k;
        
        for(int i = 0; i < k; i++)
        {
            auto it = list.begin();
    
            count = 1;
            
            while(it != list.end())
            {
                if(count == newStep)
                {
                    pointArray->push_back(*it);
                }
                
                count++;
                ++it;
            }
            
            newStep+=step;
        }
        
        auto it = pointArray->begin();
        
        for( ; it != pointArray->end(); ++it)
        {
            cout << "Point Array check: " << *it << endl;
        }
        
        
    }
    
    template<typename T, int dim>
    int Cluster<T, dim>::getClusterEdges() const
    {
        int edges = size * (size-1)/2;
        
        if(edges == 0)
        {
            edges = 1;
        }
        
        return edges;
    }
    
    template<typename T, int dim>
    T interClusterEdges(const Cluster<T, dim> & c1, const Cluster<T, dim> & c2)
    {
        double intEdge = (c1.size * c2.size);
        
        if(intEdge == 0)
        {
            intEdge = 1;
        }
        
        return intEdge;
    }
    
    template<typename T, int dim>
    T Cluster<T, dim>::intraClusterDistance() const
    {
        // Calculates the sum of the distances between every two points in the cluster
        
        auto it = list.begin();
        
        double sum;
        
        while(it != list.end())
        {
            auto it2 = list.begin();
            
            while(it2 != list.end())
            {
                sum += (*it).distanceTo(*it2);
                ++it2;
            }
            
            ++it;
        }
        
        cout << "IntraCluter Distance: " << sum/2 << endl;
        
        return (sum/2);
    }
    
    template<typename T, int dim>
    T interClusterDistance(const Cluster<T, dim> & c1, const Cluster<T, dim> & c2)
    {
        // Calculates the sum of the distances between each point in two clusters
      
        auto it = c1.list.begin();
        
        double sum;
        
        while(it != c1.list.end())
        {
            auto it2 = c2.list.begin();
            
            while(it2 != c2.list.end())
            {
                sum += (*it).distanceTo(*it2);
                ++it2;
            }
            
            ++it;
        }
        
        return sum;
    }
    
    template<typename T, int dim>
    void Cluster<T, dim>::setCentroid(const Point<T, dim> & point)
    {
        setStatus(true);
        _centroid = point;
    }
    
    template<typename T, int dim>
    void Cluster<T, dim>::computeCentroid(const Cluster<T, dim> & c)
    {
        // Centroid is an imaginary point that is the mean of all the points in a cluster
        
            auto it = c.list.begin();
        
            if(c.list.empty() == true)
            {
                throw RemoveFromEmptyEx();
            }
            
            while(it != c.list.end())
            {
                cout << "it: " << *it << endl;
                _centroid += (*it);
                ++it;
            }
            
            _centroid /= c.size;
            
            setStatus(true);
            setCentroid(_centroid);
    }
    
    template<typename T, int dim>
    Point<T, dim> & Cluster<T, dim>::operator[](int index)
    {
        int count = 0;
        
        if(index >= size)
        {
            throw OutOfBoundsEx(index);
        }
        
        auto it = list.begin();
        
        for( ; it != list.end(); ++it)
        {
            if(count == index)
            {
                return *it;
            }
            
            count++;
        }
    
        return *list.begin();
    }
    
}