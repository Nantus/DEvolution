#pragma once

template <typename T>
T power(T argParam,int argPower) {
	T temp = argParam;
	for (int i(1); i < argPower; i++)
		temp *= argParam;
	return temp;
}