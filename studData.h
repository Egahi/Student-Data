#ifndef _STUDDATA_H_
#define _STUDDATA_H_ 

#define ZERO 0
#define TEN 10

struct identity
{
				char surname[1000] = {'\0'};
				char otherNames[5000] = {'\0'};
				char department[50];
				int matric;
};

struct record
{
				char code[20] = {'\0'};
				int score;
				char grade;
				int unit;
};

void welcome(void);

void getData(void);

void Validate (int *, char [], char [], int  *);

void gpCalc(void);

bool runAgain(void);

void print(void);

#endif