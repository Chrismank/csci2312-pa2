
#include <iostream>
#include "Point.hpp"
#include "Cluster.hpp"
<<<<<<< HEAD
#include "KMeans.hpp"
=======
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace Clustering;

<<<<<<< HEAD
// PA3
Point test(Point &, Point &);
Cluster test2(Cluster &);
//Point test(Point &, Point &);

int main()
{
    KMeans test(4, 5);
    
    
//    const unsigned DIMENSIONALITY = 5;
//    ifstream inputFile;
//    inputFile.open("SampleFile.txt");
////
////    // Test Point Values
//    Cluster universe(DIMENSIONALITY);
////////    Point universe(5);
////////    
//    
//    inputFile >> universe;
////
////  cout << "Universe: " << universe << endl;
////
//    inputFile.close();
//    
////    Cluster test;
////    
////    cout << "empty cluster: " << test << endl;
////
//   Cluster c2(universe);
//    
//    
////  Cluster c2(DIMENSIONALITY);
//////    
////    c2 = universe;
////    
//    cout << "c2: " << c2 << endl;
//////
//  Cluster c3(DIMENSIONALITY);
//////    
//    cout << "c3: " << c3 << endl;
////
//    
    
//    cout << "Universe size: " << universe.getSize() << endl;
//    
//    universe.computeCentroid(universe);
//    
//    cout << "Centroid: " << (universe.getCentroid()) << endl;
//    
//    cout << "Universe unchanged: " << universe << endl;
//
    //cout << "Intra Cluster Distance: " << universe.intraClusterDistance() << endl;
    
//    Cluster c2(universe);
//    
//    cout << "c2: " << c2 << endl;
//    
//    Cluster c3;
//    
//    c3 = c2;
//    
//    cout << "c3: " << c3 << endl;
//    
//    
//    
//  
    
    
//
//    cin >> universe;
//    
//    cout << "Universe: " << universe << endl;
  
//    Cluster c1(DIMENSIONALITY);
//   // Cluster c2(DIMENSIONALITY);
//
//    int dim = 3; // x, y, z values
//    Point temp(dim), temp2(2), temp3(dim), temp4(dim), temp5(dim), temp6(dim);
//    
//    temp.setValue(1, 1); // Temp = (1, 2, 3)
//    temp.setValue(2, 2);
//    temp.setValue(3, 3);
//    
//    temp2 = temp;
//    
//    cout << "Temp2: " << temp2 << endl;
    
//    temp2.setValue(1, 2); // Temp 2 = (2, 2, 3)
//    temp2.setValue(2, 3);
//    temp2.setValue(3, 5);
//    
//    temp3.setValue(1, 1);
//    temp3.setValue(2, 1);
//    temp3.setValue(3, 1);
//    
//    temp4.setValue(1, 4);
//    temp4.setValue(2, 5);
//    temp4.setValue(3, 6);
//    
//    temp5.setValue(1, 7);
//    temp5.setValue(2, 3);
//    temp5.setValue(3, 6);
//    
//    temp6.setValue(1, 8);
//    temp6.setValue(2, 4);
//    temp6.setValue(3, 1);
//
////
//    c1.add(&temp);
//    c1.add(&temp2);
//    c1.add(&temp3);
//
   // cout << "intra cluster dist: " << c1.intraClusterDistance() << endl;
    
//    c2.add(&temp4);
//    c2.add(&temp5);
//    c2.add(&temp6);
    
   // cout << "Intercluster dist: " << interClusterDistance(c1, c2) << endl;

    
    //Point p[2] {Point(5), Point(5)};
    
//    Cluster *check[2];
//    
//    check[0] = &universe;
//    
//    cout << "Cluster array: " << *check[0] << endl;
    
    
//    PointPtr p[5];
//    
//    universe.pickPoints(3, p);
    
    //c1.pickPoints(2, p);
//
//    universe.computeCentroid(universe);
    
//    cout << "2nd Cluster: " << c1 << endl;
////
//    cout << interClusterDistance(c1, c2) << endl;
//    
//    
//
//   
//    cout << c1.getClusterEdges() << endl;
//    
//    c1.computeCentroid(c1);
//    cout << *(c1.getCentroid()) << endl;
//
//   
//
//



//    int dim = 3; // x, y, z values
//    Point temp(dim), temp2(dim), temp3(dim), temp4(dim), temp5(dim), temp6(dim);
//    
//    temp.setValue(1, 1); // Temp = (1, 2, 3)
//    temp.setValue(2, 2);
//    temp.setValue(3, 3);
//    
//    temp2.setValue(1, 2); // Temp 2 = (2, 2, 3)
//    temp2.setValue(2, 2);
//    temp2.setValue(3, 3);
//    
//    c1.add(&temp);
//    c1.add(&temp2);
//
//    Clustering::Cluster::Centroid computeCentroid(c1);
//    
//    c1.computeCentroid(Cluster::Centroid (c1));
//    
    
   
    
    

    
//    cout << "Temp: " << temp << endl;
//    
//    cout << "Temp2: " << temp2 << endl;
//    temp3.setValue(1, 5); // Temp 3 = (5, 7, 3)
//    temp3.setValue(2, 7);
//    temp3.setValue(3, 3);
//    
//    temp4.setValue(1, 1); // Temp 4 = (1, 5, 9)
//    temp4.setValue(2, 5);
//    temp4.setValue(3, 9);
//    
//    temp5.setValue(1, 0); // Temp 5 = (0, 0, 0)
//    temp5.setValue(2, 0);
//    temp5.setValue(3, 0);
//    
//    temp6.setValue(1, 1); // Temp 6 = (1, 2, 3)
//    temp6.setValue(2, 2);
//    temp6.setValue(3, 3);
//    
//    c1.add(&temp); // (1, 2, 3)
//    c1.add(&temp2); // (2, 2, 3)
//    c1.add(&temp3); // (5, 7, 3)
//  
//    
    
    
=======
// PA2 
int main()
{
    // Test Point Values
    
    int dim = 3; // x, y, z values
    Point temp(dim), temp2(dim), temp3(dim), temp4(dim), temp5(dim), temp6(dim);

    temp.setValue(1, 1); // Temp = (1, 2, 3)
    temp.setValue(2, 2);
    temp.setValue(3, 3);
    
    temp2.setValue(1, 2); // Temp 2 = (2, 2, 3)
    temp2.setValue(2, 2);
    temp2.setValue(3, 3);
    
    temp3.setValue(1, 5); // Temp 3 = (5, 7, 3)
    temp3.setValue(2, 7);
    temp3.setValue(3, 3);
    
    temp4.setValue(1, 1); // Temp 4 = (1, 5, 9)
    temp4.setValue(2, 5);
    temp4.setValue(3, 9);
    
    temp5.setValue(1, 0); // Temp 5 = (0, 0, 0)
    temp5.setValue(2, 0);
    temp5.setValue(3, 0);
    
    temp6.setValue(1, 1); // Temp 6 = (1, 2, 3)
    temp6.setValue(2, 2);
    temp6.setValue(3, 3);
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
    
    // Testing for functions in Point class
    
    // Copy Constructor*************************************************
    
//    Point temp7(temp6);
//    
//    cout << "Temp7: " << temp7 << endl; // Temp 7 = (1, 2, 3)

    //cout << "Temp7*2: " << temp7*2 << endl; // Temp7 = (2, 4, 6)
//
//    cout << "Temp 6: " << temp6 << endl; // Temp 6 = (1, 2, 3)
//    
    // Assignment Operator**********************************************
    
//    Point temp7(dim);
//    temp7 = temp4;
//    
//    cout << "Temp7: " << temp7 << endl; // Temp 7 = (1, 5, 9)
////
//    cout << "Temp7 *2: " << temp7*2 << endl; // Temp 7 = (2, 10, 18)
//    
//    cout << "Temp4: " << temp4 << endl; // Temp 4 = (1, 5, 9)
    
    // Get Value********************************************************
    
//    temp6.getValue(1);
//    temp6.getValue(2);
//    temp6.getValue(3);
//
//    cout << temp6[1] << endl; // off by one due to overloaded [] operator
//    cout << temp6[2] << endl;
//    cout << temp6[3] << endl;
//    
//    temp2.getValue(1);
//    temp2.getValue(2);
//    temp2.getValue(3);
////
//    temp3.getValue(2);
    
    // getDims Function*************************************************
    
//    cout << "Dims: " << temp5.getDims() << endl;
//    
    // distanceTo Function**********************************************
    
//    cout << "Distance: " << temp4.distanceTo(temp3) << endl;
    
    // == Function******************************************************
    
//    cout << "Temp4 == Temp3: " << (temp4 == temp3) << endl;
//    cout << "Temp6 == Temp: " << (temp6 == temp) << endl;
//    cout << "Temp == Temp2: " << (temp == temp2) << endl;
    
    // != Function******************************************************
    
//    cout << "Temp2 != Temp: " << (temp2 != temp) << endl;
//    cout << "Temp6 != Temp: " << (temp6 != temp) << endl;
//    cout << "Temp3 != Temp4: " << (temp3 != temp4) << endl;
 
    // < Function*******************************************************
    
//    cout << "Temp2 < Temp: " << (temp2 < temp) << endl;
//    cout << "Temp6 < Temp: " << (temp6 < temp) << endl;
//    cout << "Temp3 < Temp4: " << (temp3 < temp4) << endl;
//    cout << "Temp < Temp2: " << (temp < temp2) << endl;
//    cout << "Temp < Temp6: " << (temp < temp6) << endl;
//    cout << "Temp4 < Temp3: " << (temp4 < temp3) << endl;
//    cout << "Temp < Temp4: " << (temp < temp4) << endl;
//    cout << "Temp4 < Temp: " << (temp4 < temp) << endl;
    
    // > Function*******************************************************
    
//    cout << "Temp2 > Temp: " << (temp2 > temp) << endl;
//    cout << "Temp6 > Temp: " << (temp6 > temp) << endl;
//    cout << "Temp3 > Temp4: " << (temp3 > temp4) << endl;
//    cout << "Temp > Temp2: " << (temp > temp2) << endl;
//    cout << "Temp > Temp6: " << (temp > temp6) << endl;
//    cout << "Temp4 > Temp3: " << (temp4 > temp3) << endl;
//    cout << "Temp > Temp4: " << (temp > temp4) << endl;
//    cout << "Temp4 > Temp: " << (temp4 > temp) << endl;
    
    // <= Function******************************************************
    
//    cout << "Temp2 <= Temp: " << (temp2 <= temp) << endl;
//    cout << "Temp6 <= Temp: " << (temp6 <= temp) << endl;
//    cout << "Temp3 <= Temp4: " << (temp3 <= temp4) << endl;
//    cout << "Temp <= Temp2: " << (temp <= temp2) << endl;
//    cout << "Temp <= Temp6: " << (temp <= temp6) << endl;
//    cout << "Temp4 <= Temp3: " << (temp4 <= temp3) << endl;
//    cout << "Temp <= Temp4: " << (temp <= temp4) << endl;
//    cout << "Temp4 <= Temp: " << (temp4 <= temp) << endl;
    
    // >= Function******************************************************
    
//    cout << "Temp2 >= Temp: " << (temp2 >= temp) << endl;
//    cout << "Temp6 >= Temp: " << (temp6 >= temp) << endl;
//    cout << "Temp3 >= Temp4: " << (temp3 >= temp4) << endl;
//    cout << "Temp >= Temp2: " << (temp >= temp2) << endl;
//    cout << "Temp >= Temp6: " << (temp >= temp6) << endl;
//    cout << "Temp4 >= Temp3: " << (temp4 >= temp3) << endl;
//    cout << "Temp >= Temp4: " << (temp >= temp4) << endl;
//    cout << "Temp4 >= Temp: " << (temp4 >= temp) << endl;
    
    // *= Function******************************************************
//    
//    cout << "temp2 before: " << temp2 << endl;
//    cout << "Temp2 *= 3: " << (temp2*=3) << endl;
    //cout << "New Temp2: " << temp2 << endl;

    // * Function*******************************************************
//    Point test(dim);
//
//    test = temp3;
//    cout << "temp3: " << temp3 << endl;
//    
//    cout << test*3 << endl;
  
    
    // /= Function******************************************************
//    cout << "temp2: " << temp2 << endl;
//    cout << "Temp2 /= 1.73: " << (temp2 /= 1.73) << endl;
//    cout << "Temp2 /= 0: " << (temp2/=0) << endl;
    
<<<<<<< HEAD
       // / Function*******************************************************
=======
    // / Function*******************************************************
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
//    temp3 = temp2/1.73;
//    cout << "Temp2 / 1.73: " << temp3 << endl;
//    cout << "Temp2 / 0: " << (temp2/0) << endl;
    
    // += Function******************************************************
//    cout << "temp2: " << temp2 << endl;
//    cout << "Temp2+=temp: " << (temp2+=temp) << endl;
//    //cout << "New Temp2: " << temp2 << endl;
//    cout << "Temp: " << temp << endl;
        // + Function*******************************************************
//    
//    Point tempPlus(dim);
//    tempPlus = temp2 + temp;
//    
//    cout << "TempPlus = temp2 + temp " << tempPlus << endl;
   // cout << "temp2: " << temp2 << endl;
   // cout << "temp: " << temp << endl;
    
    // -= Function******************************************************
    
//    cout << "Temp2-=temp: " << (temp2-=temp) << endl;
//    cout << "New Temp2: " << temp2 << endl;
//    cout << "Temp: " << temp << endl;
    
    // - Function*******************************************************
    
//        Point tempPlus(dim);
//        tempPlus = temp2 - temp;
//    
//        cout << "TempPlus = temp2 - temp " << tempPlus << endl;
//        //cout << "temp2: " << temp2 << endl;
//        cout << "temp: " << temp << endl;
    
// ******************************************************************************************************
    
    // Testing for functions in Cluster Class
    
    // Add Function*****************************************************
//
//    Cluster c1, c2;
//
//    c1.add(&temp); // (1, 2, 3)
//    
//    c1.add(&temp2); // (2, 2, 3)
//    
//    c1.add(&temp3); // (5, 7, 3)
//    
//    c1.add(&temp4); // (1, 5, 9)
//    
//    c1.add(&temp5); // (0, 0, 0)
//    
//    cout << "c1: " << c1 << endl;
    
    // Remove Function**************************************************
    
//    c1.remove(&temp5);
//    cout << "c1: " << c1 << endl;
    
    // == Operator******************************************************
    
//    c2.add(&temp);
//    c2.add(&temp2);
//    c2.add(&temp3);
//    c2.add(&temp5);
//    
//    cout << "c1 == c2: " << (c1 == c2) << endl;
//
//    c2.add(&temp4);
//    c2.add(&temp5);
//    
//    cout << "c1 == c2: " << (c1 == c2) << endl;
    
    // += Cluster Operator**********************************************
    
//    Cluster c3, c4;
//    
//    c3.add(&temp5);
//    c3.add(&temp4);
//    c3.add(&temp6);
//    c3.add(&temp2);
//    
//    c4.add(&temp3);
//    c4.add(&temp6);
//    c4.add(&temp2);
//    
//    cout << "c3 += c4: " << (c3+=c4) << endl;
//    
//    cout << "c3: " << c3 << endl;
//    cout << "c4: " << c4 << endl;
//    
//    c3.add(&temp3);
//    c3.add(&temp2);
//    
//    c4.add(&temp4);
//    c4.add(&temp5);
//    
//    cout << "c3 += c4: " << (c3+=c4) << endl;
//    
//    cout << "c3: " << c3 << endl;
//    cout << "c4: " << c4 << endl;
//    
//    c3.remove(&temp4);
//    
//    cout << "new c3: " << c3 << endl;
//    cout << "old c4: " << c4 << endl;
    
    // -= Cluster Operator*************************************************
    
<<<<<<< HEAD
//    Cluster c3, c4, c5;
//    
//    c3.add(&temp); // Same as temp 6 - should be removed
//    c3.add(&temp2);
//    c3.add(&temp3);
//
//    c4.add(&temp6);
//    c4.add(&temp5);
//    c4.add(&temp4);
//////
=======
    Cluster c3, c4, c5;
    
    c3.add(&temp); // Same as temp 6 - should be removed
    c3.add(&temp2);
    c3.add(&temp3);

    c4.add(&temp6);
    c4.add(&temp5);
    c4.add(&temp4);
////
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
//    (c3-=c4);
//    
//    cout << "new c3: " << c3 << endl;
 
    // Assignment Operator*************************************************
    
//    c4 = c3;
//
//    cout << "c3: " << c3 << endl;
//    cout << "C4: " << c4 << endl;
<<<<<<< HEAD
//
=======
//    
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
//    c5 = c4;
//    
//    cout << "c4: " << c4 << endl;
//    cout << "c5: " << c5 << endl;
//
    // Copy Constructor****************************************************
//    
//    Cluster c6(c4);
//    
//    cout << "C4: " << c4 << endl;
//    cout << "c6: " << c6 << endl;
    
    // += point operator*************************************************
    
//    Cluster c3;
//    
//    c3.add(&temp);
//    c3.add(&temp2);
//    c3.add(&temp3);
//    c3.add(&temp5);
//    c3.add(&temp6);
//    
//    cout << "c3 before: " << c3 << endl;
//    
//    (c3+=temp4);
//    //c3+=temp;
//    
//    cout << "c3 after: " << c3 << endl;
//    
    
    // -= point operator**************************************************
//    
//    cout << "c3 before: " << c3 << endl;
//    
//    (c3-=temp);
//    
//   cout << "c3 after: " << c3 << endl;
//
//    cout << "c3: " << c3 << endl;
//    
//    c3.remove(&temp5);
//    
//    cout << "c3 again : " << c3 << endl;
    
    // + 2 clusters operator (set-destructive)*****************************
//    
//    Cluster c1, c2, c3, c4, c5;
//    
//    c1.add(&temp);
//    c1.add(&temp2);
//    c1.add(&temp3);
//    
//    c2.add(&temp4);
//    c2.add(&temp5);
//    c2.add(&temp6);
//    
//    c3 = c1 + c2;
    
  //  cout << "C3: " << c3 << endl;
    
  //  c2.remove(&temp5);
    
   // cout << "New c2: " << c2 << endl;
   // cout << "c3 unchanged: " << c3 << endl;
    
    // - 2 clusters operator (set-destructive)*****************************
    
    
//    cout << "c3 before: " << c3 << endl;
//
//    c3-=c2;
//
//   cout << c3 << endl;
    
 //   c4 = c3-c2;
    
 //   cout << "c4: " << c4 << endl;
    
    
    
//    + Cluster and pointptr operator (set-destructive)********************
    
//    cout << "c1: " << c1 << endl;
//    c4 = c1 + (&temp6);
//
//    cout << "C4: " << c4 << endl;
    
    // - Cluster and pointptr operator (set-destructive)*******************
    
//    cout << "c4: " << c4 << endl;
//    
//    c5 = c4 - (&temp2);
//    
//    cout << "c5: " << c5 << endl;
    
<<<<<<< HEAD
 //   int c;

 // cout << "Test: " <<  test(temp, temp2);
    
    
//    cout << "Temp: " << temp << endl;
//    cout << "Temp2: " << temp2 << endl;
    
//    Cluster c1;
//    
//    c1.add(&temp);
//    c1.add(&temp2);
//    
//   // test2(c1);
//    
//    cout << "c1: " << c1 << endl;
//    cout << "c2: " << test2(c1) << endl;
    
    
//    test(temp, temp2);
//   cin >> c;

    return 0;
}

//Point test(Point &value1, Point &value2)
//{
//    cout << "test function" << endl;
//    Cluster c;
//
//    c.add(&value1);
//    c.add(&value2);
//    
//    c.computeCentroid(c); // point destructor is called after this function ends due to dynamically allocated point created inside of this function
//    
//  //  cout << "centroid: " << (c.getCentroid()) << endl;
//    
// //   return (c.getCentroid());
//    // cluster destructor gets called once this function ends
//    return 0;
//}
//
//Cluster test2(Cluster & c)
//{
//    Cluster c2;
//    
//    c2 = c;
//    
//    return c2;
//}
=======
    return 0;
}
>>>>>>> 9a9953fcfe6bd1a9c4a52c1cb6a5bd977f6158ea
