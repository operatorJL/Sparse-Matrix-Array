/***********************************
	Sparse Matrix Class w/ Arrays
************************************/
#include <iostream>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "Matrix.h"
using namespace std;

ifstream in;
ofstream fout;

/***********************************
	default constructor to initialize 
	matrix values
************************************/
Matrix::Matrix()
{
	for(int i=0; i<101; i++)
	{
		for(int j=0; i<101; j++)
		{
			matrix[i][j]=0.0;
		}
	}
	
	matrix[101][101];
	maxI=1;
	maxJ=1;
	iValue=1;
	jValue=1;
	
}

/***********************************
	constructor that is called
	after overloaded operator 
************************************/
Matrix::Matrix(double newMatrix[][101], int newI, int newJ)
{
	maxI=newI;
	maxJ=newJ;
	for(int r=1; r<=newI; r++)
	{
		for(int c=1; c<=newJ; c++)
			matrix[r][c]=newMatrix[r][c];
	}
	
}

/***********************************
	takes the input file that was
	parsed from clp.cpp, opens it
	and does error checking on inputs 
	and assigns them in the matrix
************************************/
void Matrix::readFile(char *file)
{
	char input[50];
	char* row;
	char *column;
	char *tempval;
	int linenum=0;
	char *tempdub=NULL;
	int i=1;
	int j=1;
	double value=0.0;
	
	in.open(file);
	
	if(in.fail()||in.bad())
	{
		cout<<"could not open the file\n";
		cout<<"please retry with a new file\n";
	}
		
		
	while(!in.eof())
	{
			++linenum;
			
			in.getline(input[50]);
		
		
			if(input[0]=='#')
				continue;
			else	
			{
				
			
				row = strtok(input," ");
		
				column = strtok(NULL, " ");
				
				tempval= strtok(NULL, " ");
				
				
				i=atoi(row);
				if(i<0)
				{
					cout<<"line "<<linenum<< " has negative i entry \n";
					continue;
				}
				
				j=atoi(column);
				if(j<0)
				{
					cout<<"line "<<linenum<< " has negative j entry \n";
					continue;
				}
				
				value=strtod(stringValue,&tempdub);
				
				
				if(maxI<i)
					maxI=i;
					
				
				if(maxJ<j)
					maxJ=j;
					
				
					
				matrix[i][j]=value;	
			}
	
	}
	
	in.close();
	
	
}

void Matrix::setValue(int i, int j, double value)
{
	matrix[i][j]=value;
}

double Matrix::getValue(int i, int j)
{

	return matrix[i][j];
	
}
void Matrix::setMaxI(int newMaxI)
{
	maxI=newMaxI;
}
int Matrix::getMaxI()
{
	return maxI;
}

void Matrix::setMaxJ(int newMaxJ)
{
	maxJ=newMaxJ;
}

int Matrix::getMaxJ()
{
	return maxJ;
}

void Matrix::setIvalue(int newIvalue)
{
	iValue=newIvalue;
}

int Matrix::getIvalue()
{
	return iValue;
}

void Matrix::setJvalue(int newJvalue)
{
	jValue=newJvalue;
}

int Matrix::getJvalue()
{
	return jValue;
}

/*************************************
	printing the result matrix in
	sparse list form.  finds a value
	in matrix < or > 0 and prints
	the i and j values then the value

*************************************/
void Matrix::printMatrix(char *file)
{	
	fout.open(file);
	
	fout<<"#Result\n";
	fout<<"#Matrix C\n";
	
	for(int i=1; i<=maxI; i++)
	{	
		for(int j=1; j<=maxJ+1; j++)
			{
				if(matrix[i][j]<0 || matrix[i][j]>0)
					{
						fout<<i<<" "<<j<<" "<<matrix[i][j]<<endl;
					
					}
					
				
			}
	}		
	fout<<endl;	
	
	fout.close();
	
	
}
/*************************************
overloaded operator to do matrix
multiplication.  returns an anonymous
object 
**************************************/

const Matrix Matrix::operator *(const Matrix& matxB)
{
	double cMatrix[101][101]= {0.0};
	int newMaxI=1;
	int newMaxJ=1;
	
	if(maxJ != matxB.maxI)
		{
			cout<<"Invalid matrix dimensions\n";
			cout<<"cannot multiply matrices\n";
		}
	else
	{
		for (int i = 1 ; i <= maxI; i++)
		{	
			for (int j = 1;  j <= matxB.maxJ; j++)
			{	
				for (int k = 0; k <= maxI; k++)
				{	
					cMatrix[i][j] += matrix[i][k] * matxB.matrix[k][j];
				}
			}
		}
	
		newMaxI=maxI;
		newMaxJ=matxB.maxJ;
	
		return Matrix(cMatrix, newMaxI, newMaxJ);
	
	}
	
	
}
/*******************************
	printing to the screen 
	for error checking

********************************/
void Matrix::printScreen()
{

for(int i=1; i<=maxI; i++)
	{	
		for(int j=1; j<=maxJ; j++)
			{
				if(matrix[i][j]<0 || matrix[i][j]>0)
					{
						cout<<i<<" "<<j<<" "<<matrix[i][j]<<endl;
					
					}
					
				
			}
	}	



}