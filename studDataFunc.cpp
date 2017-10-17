#include <iostream>
#include <cmath>
#include <iomanip>

#include "studData.h"

using namespace std;

// struct to hold user names
identity personal;

// variable to hold number of courses
int nC;

// struct to hold academic record
record *acada = new record[nC];

// total attempted units
int aUnit;

// total units passed
int pUnit;

// weighted score
int wScore;

// G.P.A
float gpa;

/**
 * Welcomes user and explains purpose of program.
 */
void welcome(void)
{
				cout << "\nHello and welcome!"
				     << "\n\nstudData.cpp gets user details "
				     << "(name, registered courses and scores) "
				     << "\nthen prints out the detais as well as their cgpa."
				     << "\n\nThis is studData!" 
				     << "\n\nplease enter your details to get started..." << endl;
}

/**
 * gets name, matriculation number, number of registered courses,
 * course codes, course units and grade of user 
 * and stores them in identity and record structs
 */
void getData(void)
{
				// initialise variables for fresh data
				aUnit = 0;
				pUnit = 0;
				wScore = 0;
				
				cout << "\nSurname: ";
				cin.getline(personal.surname, 1000);

				cout << "\nOther names: ";
				cin.getline(personal.otherNames, 5000);
			
				// arrays to pass prompt text and error messages to validate function
				char promptText[25] = {'\0'};
				char errorText[70] = {'\0'};
				int range;
				
				// get and validate matriculation number limit input to range 0 - 169999999
				strcpy(promptText, "Matriculation number: ");
				strcpy(errorText, "INVALID RESPONSE! please enter a number in the range of 0 to 169999999");
				range = 169999999;
				
				Validate(&personal.matric, promptText, errorText, &range);
								
				// get and valodate Number of registered courses limit input to range 0 - 25
				strcpy(promptText, "No of registered courses: ");
				strcpy(errorText, "INVALID RESPONSE! please enter a number in the range of 0 to 25");
				range = 25;
								
				Validate(&nC, promptText, errorText, &range);
				
				cout << "\nEnter course code, corresponding units"
				     << " and your grade for each course" << endl;
				
				// get and validate course code, units and grade for each course
				for (int i = 0; i < nC; i++)
				{
								cout << "\nCourse " << i + 1 << " code: ";
								cin.getline(acada[i].code, 20);
							
							// get and validate units limit input to range 0 - 10
				    strcpy(promptText, "Units: ");
						  strcpy(errorText, "INVALID RESPONSE! please enter a number between 0 and 10");
							range = 10;
															
				    Validate(&acada[i].unit, promptText, errorText, &range);
								
								// get and validate score limit input to range 0 - 100
								strcpy(promptText, "Score: ");
								strcpy(errorText, "INVALID RESPONSE! please enter a number between 0 and 100");
								range = 100;
								
								Validate(&acada[i].score, promptText, errorText, &range);
      }
}

/**
 * validates input and enforces valid response.
 */
void Validate (int *variable, char promptText[], char errorText[],int  *range)
{
				// returns true for valid input and false otherwise
				bool validate;
				
				do
				{				
				     cout << endl << promptText;
								
								// can only be a positive integer
								if (!(cin >> *variable))
								{
								     cout << endl << errorText;
												cin.clear();
												validate = false;
				      }
								
								else if (*variable < ZERO || *variable > *range)
								{
						 		     cout << endl << errorText;
												validate = false;
								}
								
				      else
								     validate = true;
								
				     	cin.ignore(50, '\n');
				} while (validate == false);
}

/**
 * calculate user's GPA
 */
void gpCalc(void)
{
				for (int i = 0; i < nC; i++)
				{
								// pick tens digit of score
								int score = acada[i].score / TEN;
								
								switch(score)
				     {
												case 10:
												case 9:
												case 8:
												case 7:
												        acada[i].grade = 'A';
												        wScore += (acada[i].unit * 5);
												        break;
												
												case 6:
												        acada[i].grade = 'B';
																	 wScore += (acada[i].unit * 4);
												        break;
												
												case 5:
												        acada[i].grade = 'C';
																	 wScore += (acada[i].unit * 3);
												        break;
												
												case 4:
											         break;
												
												default:
												        acada[i].grade = 'F';
												        wScore += (acada[i].unit * ZERO);
           }
								
								// grades 'D' and 'E' both lie in range 40 - 50
								if (acada[i].score >= 45 && acada[i].score <= 49)
								{
								      acada[i].grade = 'D';
												wScore += (acada[i].unit * 2);
				      }
								
								if (acada[i].score >= 40 && acada[i].score < 45)
								{
								      acada[i].grade = 'E';
												wScore += (acada[i].unit * 1);
				      }

								// attempted unit is sum of total units
								aUnit += acada[i].unit;
								
								// grade 'F' is failure
				      if (acada[i].grade != 'F')
								      pUnit += acada[i].unit;
      }
				
				// calculate gpa, cast weighted score and units as float to preserve decimals 
      gpa = (float) wScore / (float) aUnit;
				
				// round off to 2 decimal places
      gpa = floor ((gpa * 100 ) + 0.5) / 100;
}

/**
 * prints out details and calculated results
 */
void print(void)
{
      cout << "\n\nSurname:\t" << personal.surname
           << "\nOther names:\t" << personal.otherNames
				     << "\nMatric Number:\t" << personal.matric
				     << "\nNo of courses:\t" << nC << endl
				     << "\nCOURSES\t\t" << "UNITS\t\t" << "SCORE\t\t" << "GRADE"
				     << endl;
				
				// print out all courses, units and grades in tabular form
				for (int i = 0; i < nC; i++)
				{
				     cout << acada[i].code << "\t\t" << acada[i].unit << "\t\t" << acada[i].score << "\t\t" << acada[i].grade << endl;
				}
								
      cout << "\nUnits Attempted:\t" << aUnit
           << "\nUnits Passed:\t\t" << pUnit
           << "\nGPA:\t\t\t" << gpa << endl;
}

/**
 * prompt to run again,
 * returns true for yes and false for no
 */
bool runAgain(void)
{
				bool validate;
				char ans;
				
				// prompt repeatedly until valid input is entered
				do
				{
								cout << "\nWant to perform another operation?"
								     << "\nEnter y for yes or n for no." << endl;
								cin >> ans;
								cin.ignore(5000, '\n');
								
								// only y or n in either upper or lowercase is valid
								if (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n')
								{
												cout << "\nINVALID RESOPONSE! "
												     << "\nEnter y for yes or n for no." << endl;
												validate = false;
								}
								
								else
												validate = true;
				} while (validate == false);
				
				if (ans == 'Y' || ans == 'y')
           return true;
				else
				{
           cout << "\n\nAll done, goodbyeeee (-_-)" << endl;
								
								// delete dynamically allocated memory
								delete[] acada;
           return false;
      }
}