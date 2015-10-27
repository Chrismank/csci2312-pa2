//
//  KMeans.hpp
//  Programming Assigment 3
//
//  Created by Kathryn Chrisman on 10/7/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

// This class implements the K-Means clustering algorithm
// 1. Set-up and initialization
// 2. Iterations of recomputing clusters until the changes become minimal (based on a score difference threshold)
// 3. Result output and teardown

#ifndef KMeans_hpp
#define KMeans_hpp

#include <stdio.h>
#include "Cluster.hpp"
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
    typedef Cluster *ClusterPtr;
    
    class KMeans
    {
        private:
        int _k;
        unsigned _dims;
        Cluster point_space;
        Cluster *clustArray; // Holds the dynamic array of Clusters
        Cluster::Move _move;
        
    public:
        // Default constructor
        KMeans(int k, unsigned d):_k(k), point_space(_dims), _dims(d), _move(nullptr, nullptr, nullptr)
        {
            std::ifstream inputFile;
           
            // Read points into point_space
            inputFile.open("SampleFile.txt");
            inputFile >> point_space;
            inputFile.close();
            
            // Call the compute function to perform algorithm on the values just read in
            computeAlgorithm();
            
        }
        
        static const double SCORE_DIFF_THRESHOLD;
        double computeClusteringScore(ClusterPtr *);
        void computeAlgorithm();
    };
}

#endif /* KMeans_hpp */

