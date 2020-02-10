#pragma once

// VECTOR 2
class vec2 {
public:
	vec2(float x, float y);
	~vec2();

	float Len(); // Returns the length of the vector
	vec2 operator+(const vec2& right); // Adds two vectors together
	vec2 operator-(const vec2& right); // substracts last vector from the first
	vec2 operator*(float scale); // Scales vector by the number provided

	float x(); // Returns the value of the vector's x component
	float y();// Returns the value of the vector's y component
private:
	float values[2];
};

// VECTOR 3
class vec3 {
public:
	vec3(float x, float y, float z);
	~vec3();

	float Len(); // Returns the length of the vector
	vec3 operator+(const vec3& right); // Adds two vectors together
	vec3 operator-(const vec3& right); // substracts last vector from the first
	vec3 operator*(float scale); // Scales vector by the number provided
	vec3 operator*(const vec3& right); // Cross product of two vectors

	float x(); // Returns the value of the vector's x component
	float y();// Returns the value of the vector's y component
	float z();// Returns the value of the vector's z component
	float values[3];
private:
	
};

// VECTOR 4
class vec4 {
public:
	vec4(float x, float y, float z, float w);
	~vec4();

	float Len(); // Returns the length of the vector
	vec4 operator+(const vec4& right); // Adds two vectors together
	vec4 operator-(const vec4& right); // substracts last vector from the first
	vec4 operator*(float scale); // Scales vector by the number provided

	float x(); // Returns the value of the vector's x component
	float y();// Returns the value of the vector's y component
	float z();// Returns the value of the vector's z component
	float w();// Returns the value of the vector's z component
private:
	float values[4];
};