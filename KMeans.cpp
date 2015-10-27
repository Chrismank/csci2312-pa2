//
//  KMeans.cpp
//  Programming Assigment 2
//  PA3
//  Created by Kathryn Chrisman on 10/7/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#include "KMeans.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <limits>

using namespace std;
namespace Clustering
{
    const double KMeans::SCORE_DIFF_THRESHOLD = 0.05;
    
    double KMeans::computeClusteringScore(ClusterPtr *clustArray)
    {
        double valueOuter, valueInner, score;
        
//        for(int i = 0; i < _k; i++)
//        {
//        cout << "Clusters stored in kmeans array: " << *clustArray[i] << endl;
//        }
        
        for(int i = 0; i < _k; i++)
        {
            valueOuter += clustArray[i]->intraClusterDistance()/clustArray[i]->getClusterEdges();
            
            for(int j = 1; j < _k; j++)
            {
                valueInner += interClusterDistance(*clustArray[i], *clustArray[j])/interClusterEdges(*clustArray[i], *clustArray[j]);
            }
        }
    
        if(valueInner == 0)
        {
            valueInner = 1;
        }
        
        score = valueOuter/valueInner;
        
        cout << "Score: " << score << endl;
        
        return score;
    }
    
    void KMeans::computeAlgorithm()
    {
        // Cluster & point_space is our collection of all points
        
        // create an array of k points (k is initialized in constructor) to pass to void pickPoints() function for our initial centroids
        PointPtr p[_k];
    
        // create an array of k clusters
        ClusterPtr clustArray[_k];
        
        // Set the first index in our array equal to our first cluster, point_space
        clustArray[0] = &point_space;
        
        // Initialze all the points in our pointptr array as well as the clusters in our clusterptr array
        for(int i = 1; i < _k; i++)
        {
            clustArray[i] = new Cluster(_dims);
            p[i] = new Point(_dims);
        }

        int i = 0;
    
        // Using the values in our point_space cluster, we will fill our array with the points we want for our initial clusters
        clustArray[i]->pickPoints(_k, p);
        
        for(int i = 0; i < _k; i++)
        {
            clustArray[i]->setCentroid(*p[i]); // sets Centroid based on the values we stored in our array in the pickPoints function
           // cout << "Check validity: " << clustArray[i]->getStatus() << endl;
           // cout << "Centroid of each cluster: " << clustArray[i]->getCentroid() << endl;
        }
     
        double oldScore, scoreDiff, newDist;
        double newScore = 0;
       
        int index = 0;
        PointPtr moveP;

        scoreDiff = SCORE_DIFF_THRESHOLD + 1;
        
//        for(int i = 0; i < _k; i++)
//        {
//            cout << "Cluster check before entering loop: " << *clustArray[i] << endl;
//        }

        while(scoreDiff >= SCORE_DIFF_THRESHOLD)
        {
            for(int i = 0; i < _k; i++)
            {
                
                // Loop through all clusters
                cout << "Cluster: " << *clustArray[i] << endl;
            
                // Create an LNodePtr and set it to the head of our cluster so that we can loop through and access the points in the cluster
                LNodePtr travelNode = clustArray[i]->getPoints();

                while(travelNode)
                    {
                        double oldDist = std::numeric_limits<double>::infinity();
                        // Loop through all points
                        cout << "Point before entering loop: " << *travelNode->p << endl;
                        
                            for(int k = 0; k < _k; k++)
                                {
                                    // Loop through all centroids
                                
                                    newDist = (*travelNode->p).distanceTo(clustArray[k]->getCentroid());
                                    cout << "New Distance: " << newDist << endl;
                                    cout << "Old Distance: " << oldDist << endl;
                                
                                    // If the point is closer to the centroid of another cluster, move the point to that cluster
                                    if(newDist < oldDist)
                                    {
                                        index = k;
                                        moveP = travelNode->p;
                                      //  cout << "index inside: " << index << endl;
                                    }
                                
                                    oldDist = newDist;
                           
                                }
                        
                        travelNode = travelNode->next;
                        
                        cout << "Point being moved: " << *moveP << endl;
                        cout << "Cluster from: " << *clustArray[i] << endl;
                        cout << "Cluster to: " << *clustArray[index] << endl;
                        
                        _move.Perform(moveP, clustArray[i], clustArray[index]);
                        // If centroid not of current cluster as determined by distance, perform move(point, current cluster, other cluster)
                        
                        for(int n = 0; n < _k; n++)
                        {
                            cout << "Check on Clusters after move: " << *clustArray[n] << endl;
                        }
                    }
                
            }
            
            for(int h = 0; h < _k; h++)
            {
               // cout << "Centroid status check: " << clustArray[h]->getStatus() << endl;
                
               //  Loop through all clusters and if centroid is invalid, compute and set valid to true
                if(clustArray[h]->getStatus() == false)
                {
                    cout << "Entering if statement" << endl;
                    clustArray[h]->computeCentroid(*clustArray[h]);
                }
                
                cout << "Centroid status check: " << clustArray[h]->getStatus() << endl;
            }
            
            oldScore = newScore;
            cout << "Old score: " << oldScore << endl;
            newScore = computeClusteringScore(clustArray);
            cout << "New score: " << newScore << endl;
            
            // Compute absolute difference and set scoreDiff
            scoreDiff = abs(newScore-oldScore);
          
        
            // Compute new clustering score
        }
    
         std::ofstream outputFile;
        
        // Write the results to outputFile
        outputFile.open("OutputFile.txt");
        for(int i = 0; i < _k; i++)
        {
            outputFile << *clustArray[i] << endl;
        }
        outputFile.close();
        
    }
    
    
}