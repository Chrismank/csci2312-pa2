//
//  Cluster.hpp
//  Programming Assignment 4 Final
//
//  Created by Kathryn Chrisman on 10/31/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#ifndef Cluster_hpp
#define Cluster_hpp

#include <stdio.h>
#include <forward_list>
#include <unordered_map>

#include "Point.hpp"

using namespace std;

namespace Clustering
{
    template<typename T, int dim>
    
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
        unsigned int _id; // Cluster id values
        static unsigned int _idGenerator;
        unsigned int _numImported = 0;
        unsigned int _numFailed = 0;
        unsigned _dimensionality;
        Point<T, dim> _centroid;
        bool _centroidValid;
        static const char POINT_CLUSTER_ID_DELIM;
        forward_list<Point<T, dim>> list;
        static unordered_map<unsigned int, double> map;
        
    public:
        // Variables to report the number of points read in successfully and unsuccessfully
        unsigned int numberImported();
        unsigned int numberFailed();
        
        // Inner class Move represents the motion of a point from one cluster to another
        class Move
        {
            Point<T, dim> _value;
            Cluster *_from;
            Cluster *_to;
            
        public:
            Move(const Point<T, dim> & pt, Cluster<T, dim> *from, Cluster<T, dim> *to): _value(pt), _from(from), _to(to) {}
            void Perform(const Point<T, dim> & value, Cluster<T, dim> *from, Cluster<T, dim> *to)
            {
                try
                {
                    to->add(from->remove(value));
                    from->setStatus(false); // Centroid status set to false for cluster from
                    to->setStatus(false); // Centroid status set to false for cluster to
                } catch (RemoveFromEmptyEx e)
                {
                    cout << e << endl;
                }
                
            }
        };
        
        // Constructors
        Cluster(); // Constructor takes a dimension as a parameter
        Cluster(const Cluster & rhs);  // Overloaded copy constructor
        
        // Overloaded assignment operator
        Cluster &operator=(const Cluster &);
        
        // Destructor
         ~Cluster();
        
        // Set functions
        void setCentroid(const Point<T, dim> & point);
        void setStatus(const bool & status) {_centroidValid = status;}
        
        // Accessor Functions
        const int getSize() {return size;}
        const Point<T, dim> getCentroid() const {return _centroid;}
        const unsigned getDimensionality() {return _dimensionality;}
        const bool getStatus() {return _centroidValid;}
        unsigned int getID() const {return _id;}
        int getClusterEdges() const;
        Point<T, dim> & operator[](int index);
        unsigned int getNumIn() const {return _numImported;}
        unsigned int getNumFail() const {return _numFailed;}
        
        // Add Functions
        void add(const Point<T, dim> &); // Add a point to forward list
        Cluster &operator+=(const Point<T, dim> & rhs); // Calls add function
        
        // Remove Functions
        const Point<T, dim> & remove(const Point<T, dim> &); // Remove a point from the forward list
        void removeDuplicates(Cluster &); // Checks for and removes duplicates from list
        Cluster &operator-=(const Point<T, dim> & rhs); // Calls remove function
        
        // Stream Operators
        template<typename S, int d>
        friend std::ostream &operator<<(std::ostream &, const Cluster<S, d> &); // printing out a point
        template<typename S, int d>
        friend std::istream &operator>>(std::istream &, Cluster<S, d> &); // adding in a point from file
        
        // Set preserving operator (do not duplicate points in the space)
        template<typename S, int d>
        friend bool operator==(const Cluster<S, d> & lhs, const Cluster<S, d> & rhs);
        
        // Set preserving operators (do not duplicate points in the space)
        Cluster &operator+=(const Cluster & rhs); // Union of 2 clusters
        Cluster &operator-=(const Cluster & rhs); // Asymmetric difference of 2 clusters
        
        // Set destructive operators
        template<typename S, int d>
        friend const Cluster<S, d> operator+(const Cluster<S, d> & lhs, const Cluster<S, d> & rhs);
        
        template<typename S, int d>
        friend const Cluster<S, d> operator-(const Cluster<S, d> & lhs, const Cluster<S, d> & rhs);
        
        template<typename S, int d>
        friend const Cluster<S, d> operator+(const Cluster<S, d> & lhs, const Point<S, d> & rhs);
        
        template<typename S, int d>
        friend const Cluster<S, d> operator-(const Cluster<S, d> & lhs, const Point<S, d> & rhs);
        
        // pickPoints Function
        //void pickPoints(int k, Point *pointArray);
         void pickPoints(int k, vector<Point<T, dim>> *);
        
        // Compute & Distance Functions
        void computeCentroid(const Cluster &);
        T intraClusterDistance() const;
        
        template<typename S, int d>
        friend S interClusterDistance(const Cluster<S, d> & c1, const Cluster<S, d> & c2);
        
        template<typename S, int d>
        friend S interClusterEdges(const Cluster<S, d> & c1, const Cluster<S, d> & c2);
        
    };
    
}

#include "Cluster.cpp"
#endif /* Cluster_hpp */