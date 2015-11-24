//
//  main.cpp
//  Programming Assignment 4 Final
//
//  Created by Kathryn Chrisman on 10/31/15.
//  Copyright © 2015 Kathryn. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

#include "Point.hpp"
#include "Cluster.hpp"
#include "KMeans.hpp"

using namespace std;
using namespace Clustering;

int main()
{
//    // Out of Bounds Exception Tests
    
//    // Point
//    Point<double, 3> p;
//    Point<double, 2> p1;
//    
//    p.setValue(1, 2);
//    p.setValue(2, 3);
//    p.setValue(3, 4);
//    
//    try {
//        cout << "Access point index outside of size: " << p[0] << endl;
//        cout << p[1] << endl;
//        cout << p[2] << endl;
//        cout << p[3] << endl;
//    } catch (OutOfBoundsEx(e)) {
//        cout << e << endl;
//    }
//    
//    // Cluster
//    Cluster<double, 3> c;
//    
//    c.add(p);
//    
//    try {
//        cout << "Access cluster index outside of size: " << c[0] << endl;
//        cout << c[1] << endl;
//    } catch (OutOfBoundsEx(e)) {
//        cout << e << endl;
//    }
    
    
   KMeans<double, 4, 5> k;
    
    return 0;
}

