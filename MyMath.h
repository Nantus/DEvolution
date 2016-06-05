#pragma once
#include <vector>

namespace myMath{
	template  <typename T>
	T power(T argParam,int argPower) {
		T temp = argParam;
		for (int i(0); i < argPower; i++)
			temp *= argParam;

		return temp;
	}

	struct point {
		std::vector<double> coordinates;
		int nDimentions;
	};

	class rVector {
	public:
		rVector();
		rVector(int argNDimentions);
		rVector(double* argXDimPointCoord, double* argYDimPointCoord,int argNDimentions);
		rVector(double** argDimPointsCoord,int argNDimentions);
		rVector(point* argPoints,int argNDimentions);
		~rVector();
		double length();
		point* points();
		void changeNDimns(int argNewNDimns);
		int getNDimns();
		double getCoordinate(int index);
		std::vector<double> getCoordinates();
		static rVector& vectorMultiple(rVector& argVecParamMultiple1,rVector& argVecParamMultiple2);
		static rVector& vectorMultiple(rVector* argVecParam);
		rVector& operator *(double argMultParam);
		double& operator *(rVector& argVecParam); //scalar multiplication
	 	rVector& operator =(rVector& argVecParam);
		rVector& operator +(rVector& argVecParam);
		rVector& operator -(rVector& argVecParam);
	protected:
		void updateVec();
		std::vector<double> coordinates; // counted based on myPoints
		point* myPoints; //counted based on bottom
		int nDimentions; //bottom - absolute value, other param-s will be counted by updateVec() based on bottom 
	};
}
