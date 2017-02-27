/*
 * =====================================================================================
 *
 *       Filename:  favorite.cpp
 *
 *    Description: favorite number algorithm 
 *
 *        Version:  1.0
 *        Created:  02/26/2017 10:12:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Austin Conder (), austin.conder@outlook.com
 *   Organization:  Mr. Solo Dolo
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

int main()
{
   int n; // users favorite number

   // get users favorite number
   cout << "What is your favorite number? ";
   cin >> n;

   // compute next number
   n = n + 1;

   // write the output
   cout << " My favorite number is 1 more than that, it is "
	   << n;

   // Line break to separate code from terminal    
   cout << "\n"; 
}
