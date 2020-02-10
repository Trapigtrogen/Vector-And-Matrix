#pragma once
#include <iostream>
#include <iomanip>
#include "vectors.h"

class mat4 {
public:
	mat4(float a1,float a2,float a3,float a4,
		float b1,float b2,float b3,float b4,
		float c1,float c2,float c3,float c4,
		float d1,float d2,float d3,float d4);
	~mat4();

	float det();
	mat4 operator*(float scale);
	mat4 transpose();
	mat4 inverse();
	mat4 operator*(const mat4 & right) const;
	vec4 operator*(vec4 & vector);
	mat4 translation(const vec3 & t);
	mat4 rotationX(float a);
	mat4 rotationY(float a);
	mat4 rotationZ(float a);
	void print();
private:
	float values[4][4];
};

/*
TODO:
- mat4 translation(const vec3& t) - martiisin siirtäminen
- mat4 rotationX(float a) - matriisin pyörittäminen x-akselin ympäri
- mat4 rotationY(float a) - matriisin pyörittäminen y-akselin ympäri
- mat4 rotationZ(float a) - matriisin pyörittäminen z-akselin ympäri
*/