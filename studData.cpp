/**
 * studData.cpp
 * 
 * this program gets user details 
 * (name, registered courses and scores)
 * then prints out the detais as well as their cgpa.
 *
 * @s__egahi
 *
 * this is studData
 */

#include <iostream>

#include "studData.h"

using namespace std;

int main (void)
{
    do
    {
					 // welcome user
			    welcome();
								
						// get detials of user
			    getData();

					// perform all calculations
        gpCalc();

					 // print details of user and calculated results
        print();

				// prompt to run again
    } while (runAgain());

    return 0;
}