//
//  KMeans.hpp
//  Programming Assignment 4 Final
//
//  Created by Kathryn Chrisman on 10/31/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//
#ifndef KMeans_hpp
#define KMeans_hpp

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "Point.hpp"
#include "Cluster.hpp"
#include "Exceptions.hpp"

// This class implements the K-Means clustering algorithm
// 1. Set-up and initialization
// 2. Iterations of recomputing clusters until the changes become minimal (based on a score difference threshold)
// 3. Result output and teardown

using namespace std;
namespace Clustering
{
    template <typename T, int k, int dim>
  
    class KMeans
    {
    private:
        int _k;
        double scoreDiff;
        Cluster<T, dim> point_space; // Collection of all points
        vector<Cluster<T, dim>> clustArray;
        vector<Point<T, dim>> pointArray; // Pass array to pickPoints to calculate our initial centroid values
        
    public:
        // Constructor
        KMeans();
        
        // Destructor
        ~KMeans();
        
        // Mutator Methods
        void setClustArrayVal(int);
        void setPointArrayVal(int);
        void setScoreDiff(double);
        void setID(int);
        
        // Accessor Methods
        vector<Cluster<T, dim>> getclustArrayVal() const {return clustArray;}
        vector<Point<T, dim>> getPointArrayVal() const {return pointArray;}
        double getScoreDiff() const {return scoreDiff;}
        
        // Score Difference Threshold
        static const double SCORE_DIFF_THRESHOLD;
        
        // Compute Functions
        double computeClusteringScore(vector<Cluster<T, dim>> &);
        void computeAlgorithm();
        void computeKMeans(vector<Cluster<T, dim>> &);
    };
}

#include "KMeans.cpp"
#endif /* KMeans_hpp */
