/***********************************
Header file for matrix class

************************************/
class Matrix
{
	private:
		
		double matrix[101][101];
		int maxI;
		int maxJ;
		int iValue;
		int jValue;
		
	public:
	
	Matrix();
	Matrix(double newMatrix[][101], int,int);
	
	void readFile(char *);
	void printMatrix(char *);
	void setValue(int,int,double);
	double getValue(int,int);
	void setMaxI(int);
	int getMaxI();
	void setMaxJ(int);
	int getMaxJ();
	void setIvalue(int);
	int getIvalue();
	void setJvalue(int);
	int getJvalue();
	const Matrix operator *(const Matrix& matxB);
	void printScreen();

};

