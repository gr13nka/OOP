#ifndef MATRIX_H
#define MATRIX_H

#include "number.h"
class Matrix 
{
	number matrix[3][3];
public:
	void change_matrix();
	int det();
	void transpose(); //by number
	int rang();
	void show_matrix();
};

#endif 
