#include "pch.h"
#include "vectors.h"
#include <math.h>
#include <iostream>

// VECTOR 2

vec2::vec2(float x, float y) {
	values[0] = x;
	values[1] = y;
}
vec2::~vec2() {}

float vec2::Len() {
	float length = hypot(this->values[0], this->values[1]);
	return length;
}

vec2 vec2::operator+(const vec2& right){
	float x = this->values[0] + right.values[0];
	float y = this->values[1] + right.values[1];
	return vec2(x,y);
}

vec2 vec2::operator-(const vec2& right){
	float x = this->values[0] - right.values[0];
	float y = this->values[1] - right.values[1];
	return vec2(x, y);
}

vec2 vec2::operator*(float scale){
	float x = this->values[0] * scale;
	float y = this->values[1] * scale;
	return vec2(x, y);
}

float vec2::x() {
	return values[0];
}

float vec2::y() {
	return values[1];
}


// VECTOR3-------------------------------------------------------------------------------

vec3::vec3(float x, float y, float z) {
	values[0] = x;
	values[1] = y;
	values[2] = z;
}
vec3::~vec3() {}

float vec3::Len() {
	float length = sqrt(this->values[0] * this->values[0] + this->values[1] * this->values[1] + this->values[2] * this->values[2]);
	return length;
}

vec3 vec3::operator+(const vec3& right) {
	float newValues[3];
	for (int i = 0; i < 3; i++) {
		newValues[i] = this->values[i] + right.values[i];
	}
	return vec3(newValues[0], newValues[1], newValues[2]);
}

vec3 vec3::operator-(const vec3& right) {
	float newValues[3];
	for (int i = 0; i < 3; i++) {
		newValues[i] = this->values[i] - right.values[i];
	}
	return vec3(newValues[0], newValues[1], newValues[2]);
}

vec3 vec3::operator*(float scale) {
	float newValues[3];
	for (int i = 0; i < 3; i++) {
		newValues[i] = this->values[i] * scale;
	}
	return vec3(newValues[0], newValues[1], newValues[2]);
}

vec3 vec3::operator*(const vec3& right) {
	float newValues[3];
	newValues[0] = this->values[1] * right.values[2] - this->values[2] * right.values[1];
	newValues[1] = this->values[0] * right.values[2] - this->values[2] * right.values[0];
	newValues[2] = this->values[0] * right.values[1] - this->values[0] * right.values[1];
	return vec3(newValues[0], newValues[1], newValues[2]);
}

float vec3::x() {
	return values[0];
}

float vec3::y() {
	return values[1];
}

float vec3::z() {
	return values[2];
}

// VECTOR4-------------------------------------------------------------------------------

vec4::vec4(float x, float y, float z, float w) {
	values[0] = x;
	values[1] = y;
	values[2] = z;
	values[3] = w;
}
vec4::~vec4() {}

float vec4::Len() {
	float length = sqrt(this->values[0] * this->values[0] + this->values[1] * this->values[1] + this->values[2] * this->values[2] + this->values[3] * this->values[3]);
	return length;
}

vec4 vec4::operator+(const vec4& right) {
	float newValues[4];
	for (int i = 0; i < 4; i++) {
		newValues[i] = this->values[i] + right.values[i];
	}
	return vec4(newValues[0], newValues[1], newValues[2], newValues[3]);
}

vec4 vec4::operator-(const vec4& right) {
	float newValues[4];
	for (int i = 0; i < 4; i++) {
		newValues[i] = this->values[i] - right.values[i];
	}
	return vec4(newValues[0], newValues[1], newValues[2], newValues[3]);
}

vec4 vec4::operator*(float scale) {
	float newValues[4];
	for (int i = 0; i < 4; i++) {
		newValues[i] = this->values[i] * scale;
	}
	return vec4(newValues[0], newValues[1], newValues[2], newValues[3]);
}

float vec4::x() {
	return values[0];
}

float vec4::y() {
	return values[1];
}

float vec4::z() {
	return values[2];
}

float vec4::w() {
	return values[3];
}