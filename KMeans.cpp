//
//  KMeans.cpp
//  Programming Assignment 4 Final
//
//  Created by Kathryn Chrisman on 10/31/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <limits>

#include "KMeans.hpp"
#include "Exceptions.hpp"

using namespace std;
namespace Clustering
{
    template <typename T, int k, int dim>
    const double KMeans<T, k, dim>::SCORE_DIFF_THRESHOLD = 0.05;
    
    template<typename T, int k, int dim>
    KMeans<T, k, dim>::KMeans()
    {
        // Constructor reads points into point_space and then calls computeAlgorithm method
        _k = k;
      
        std::ifstream inputFile;
        
        inputFile.open("/Users/kathrynchrisman/Documents/2015-2016 School Documents/Intermediate Programming/Programming Assignment 4/Programming Assignment 4/Test.txt");
        
        inputFile >> point_space;
        inputFile.close();
        
        cout << "Number Imported: " << point_space.getNumIn() << endl;
        cout << "Number Failed: " << point_space.getNumFail() << endl;
        
        computeAlgorithm();
    }

    template <typename T, int k, int dim>
    KMeans<T, k, dim>::~KMeans()
    {
        
    }
    
    template <typename T, int k, int dim>
    void KMeans<T, k, dim>::setPointArrayVal(int kVal)
    {
        // Initialze point array to values of zero before passing to pickPoints function
        
        if(kVal >= 1 && kVal <= _k)
        {
            for(int i = 0; i < dim; i++)
            {
                pointArray.push_back(0);
            }
            
        }
    }
    
    template <typename T, int k, int dim>
    void KMeans<T, k, dim>::setClustArrayVal(int kVal)
    {
        // Initialize first k in vector to point_space and the rest to zero before passing to KMeans function
        
        if(kVal == 1)
        {
            clustArray.push_back(point_space);
        }
        
        else if(kVal > 1 && kVal <= _k)
        {
            clustArray.push_back(0);
        }
        
    }
    
    template <typename T, int k, int dim>
    double KMeans<T, k, dim>::computeClusteringScore(vector<Cluster<T, dim>> & clustArray)
    {
        double valueOuter = 0 , valueInner = 0, score, sum, edges;
        
        for(int i = 0; i < _k; i++)
        {
            valueOuter += clustArray[i].intraClusterDistance()/clustArray[i].getClusterEdges();
            
            for(int j = 1; j < _k; j++)
            {
                sum = interClusterDistance(clustArray[i], clustArray[j]);
                edges = interClusterEdges(clustArray[i], clustArray[j]);
                valueInner += (sum/edges);
            }
        }
        
        if(valueInner == 0)
        {
            valueInner = 1;
        }
        
        cout << "value outer: " << valueOuter << endl;
        cout << "value inner: " << valueInner << endl;
        
        score = valueOuter/valueInner;
        
        cout << "Score: " << score << endl;
        
        return score;
    }
    
    template <typename T, int k, int dim>
    void KMeans<T, k, dim>::computeKMeans(vector<Cluster<T, dim>> & clustArray)
    {
        double oldScore, scoreDiff, newDist;
        double newScore = 0;
        int index = 0;
        Point<T, dim> moveP;
        
        scoreDiff = SCORE_DIFF_THRESHOLD + 1;
        
        // Loop until our score difference is less than the threshold
        while(scoreDiff >= SCORE_DIFF_THRESHOLD)
        {
            for(int i = 0; i < _k; i++)
            {
                // Loop through all clusters
                cout << "Cluster: " << clustArray[i] << endl;
                
                // Make a temporary array and set it equal to the values of the points in each cluster
                vector<Point<T, dim>> tempArray;
                
                // Loop through and assign all points in cluster to tempArray
                for(int val = 0; val < clustArray[i].getSize(); val++)
                {
                    tempArray.push_back((clustArray[i])[val]);
                }
                
                auto it = tempArray.begin();
                
                for( ; it != tempArray.end() ; ++it)
                {
                    cout << "temp array check: " << *it << endl;
                }
                
                int SIZE = (clustArray[i]).getSize();
                
                for(int m = 0; m < SIZE; m++)
                {
                    // Loop through all points in the cluster
                    
                    cout << "Point: " << tempArray[m] << endl;
                    
                    // Set old distance to inifinity so that new distance will always be less for the first iteration
                    
                    double oldDist = std::numeric_limits<double>::infinity();
                    
                    for(int j = 0; j < _k; j++)
                    {
                        // Loop through all centroids and calculate distance from points in cluster
                        
                        newDist = (tempArray[m]).distanceTo(clustArray[j].getCentroid());
                        
                        // If the point is closer to the centroid of another cluster, store index and point value in temporary variable until all iterations of centroids are complete
                        cout << "new dist: " << newDist << endl;
                        
                        if(newDist < oldDist)
                        {
                            index = j;
                            moveP = tempArray[m];
                        }
                        
                        // Old distance is now new distance for next iteration
                        oldDist = newDist;
                    }
                    
                    cout << "Point being moved: " << moveP << endl;
                    cout << "Cluster from: " << clustArray[i] << endl;
                    cout << "Cluster to: " << clustArray[index] << endl;
                
                    // If centroid not of current cluster as determined by distance, perform move(point, current cluster, other cluster)
                    
                    typename Clustering::Cluster<T, dim>::Move move(moveP, &clustArray[i], &clustArray[index]);
                    
                    move.Perform(moveP, &clustArray[i], &clustArray[index]);
                    
                    for(int t = 0; t < _k; t++)
                    {
                        cout << "Check on Clusters after move: " << clustArray[t] << endl;
                    }
                    
                }
                
            }
            
            
            for(int h = 0; h < _k; h++)
            {
                // cout << "Centroid status check: " << clustArray[h].getStatus() << endl;
                
                cout << "cluster: " << clustArray[h] << endl;
                
                
                //  Loop through all clusters and if centroid is invalid, compute and set valid to true
                try
                {
                    if(clustArray[h].getStatus() == false)
                    {
                        clustArray[h].computeCentroid(clustArray[h]);
                    }
                    
                    cout << "Centroid status check: " << clustArray[h].getStatus() << endl;
                } catch (RemoveFromEmptyEx e)
                {
                    cout << e << endl;
                }
                
            }
            
            oldScore = newScore;
            cout << "Old score: " << oldScore << endl;
            
            // Compute new clustering score
            newScore = computeClusteringScore(clustArray);
            cout << "New score: " << newScore << endl;
            
            // Compute absolute difference and set scoreDiff
            scoreDiff = abs(newScore-oldScore);
            
        }
    }
    
    template <typename T, int k, int dim>
    void KMeans<T, k, dim>::computeAlgorithm()
    {
        // If k is greater than the number of points imported, change it here
        
        if(_k > point_space.getSize())
        {
            cout << "K is greater than the number of points imported. K will be changed to equal the number of points." << endl;
            
            _k = point_space.getSize();
            
        }
        
        // Set the first index in our array equal to point_space
        clustArray.push_back(point_space);
        cout << "clust array[0]: " << clustArray[0] << endl;
        
        // Initialize k-1 empty clusters in clustArray
        for(int i = 1; i <_k; i++)
        {
            Cluster<T, dim> temp;
            clustArray.push_back(temp);
        }
        
        auto it = clustArray.begin();
        
        for( ; it != clustArray.end(); ++it)
        {
            cout << "Cluster array contents: " << *it << endl;
        }
        
        // Using the values in our point_space cluster, fill array with points for the initial centroids
        point_space.pickPoints(_k, &pointArray);
        
        for(int i = 0; i < _k; i++)
        {
            // sets Centroid based on the values we stored in our array in the pickPoints function
            clustArray[i].setCentroid(pointArray[i]);
          
            cout << "Check validity: " << clustArray[i].getStatus() << endl;
            cout << "Centroid of each cluster: " << clustArray[i].getCentroid() << endl;
        }
        
        // Call to computeKMeans function
        computeKMeans(clustArray);
        
        // Writes out the contents of our cluster vector to a file
        std::ofstream outputFile;
        
        outputFile.open("/Users/kathrynchrisman/Documents/2015-2016 School Documents/Intermediate Programming/Programming Assignment 4/Programming Assignment 4/OutputFile.txt");
        
        auto it3 = clustArray.begin();
        
        for( ; it3 != clustArray.end(); ++it3)
        {
            // Loop through clusters
            //outputFile << *it3 << endl;
            cout << *it3 << endl;
            
        }
        
        outputFile.close();
        
        
    }
    
   
    
    
}
