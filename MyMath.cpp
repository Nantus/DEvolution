#include <vector>
#include "MyMath.h"

namespace myMath {

	rVector::rVector() {
		myPoints = new point[2];
		nDimentions = 0;
		myPoints[0].coordinates.reserve(nDimentions);
		myPoints[1].coordinates.reserve(nDimentions);
		updateVec();
	}

	rVector::rVector(int argNDimentions) {
		myPoints = new point[2];
		nDimentions = argNDimentions;
		myPoints[0].coordinates.reserve(nDimentions);
		myPoints[1].coordinates.reserve(nDimentions);
		updateVec();
	}

	rVector::rVector(double** argDimPointsCoord, int argNDimentions) {
		myPoints = new point[2];
		nDimentions = argNDimentions;
		myPoints[0].coordinates.reserve(nDimentions);
		myPoints[1].coordinates.reserve(nDimentions);

		for (int i(0); i < 2; i++)
			for (int j(0); j < nDimentions; j++)
				myPoints[i].coordinates[j] = argDimPointsCoord[i][j];
		updateVec();
	}

	rVector::rVector(double* argXDimPointCoord, double* argYDimPointCoord, int argNDimentions) {
		myPoints = new point[2];
		nDimentions = argNDimentions;
		myPoints[0].coordinates.reserve(nDimentions);
		myPoints[1].coordinates.reserve(nDimentions);

		for (int i(0); i < nDimentions; i++)
		{
			myPoints[0].coordinates[i] = argXDimPointCoord[i];
			myPoints[1].coordinates[i] = argYDimPointCoord[i];
		}
		updateVec();		
	}

	rVector::rVector(point* argPoints, int argNDimentions) {
		myPoints = new point[2];
		nDimentions = argNDimentions;
		
		myPoints[0] = argPoints[0];
		myPoints[1] = argPoints[1];
		updateVec();
	}

	rVector::~rVector() {
		delete []myPoints;
	}

	double rVector::length() {
		return sqrt(*this*(*this));
	}

	point* rVector::points() {
		return myPoints;
	}

	void rVector::changeNDimns(int argNewNDimns) {
		nDimentions = argNewNDimns;
		updateVec();
	}

	int rVector::getNDimns() {
		return nDimentions;
	}

	double rVector::getCoordinate(int index) {
		return coordinates[index];
	}

	std::vector<double> rVector::getCoordinates() {
		return coordinates;
	}

	double& rVector::operator *(rVector& argVecParam) {
		double result = 0;
		if (nDimentions == argVecParam.getNDimns())
			for (int i(0); i < nDimentions; i++)
				result += coordinates[i] * argVecParam.getCoordinate(i);
		return result;
	}

	rVector& rVector::operator *(double argMultParam) 
	{
		rVector* result = new rVector(nDimentions);

		for (int i(0); i < nDimentions; i++)
			result->getCoordinates[i] = coordinates[i] * argMultParam;

		return *result;
	}

	rVector& rVector::operator =(rVector& argVecParam) {
		
	}
}