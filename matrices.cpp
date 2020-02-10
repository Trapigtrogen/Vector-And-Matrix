#include "pch.h"
#include "matrices.h"


mat4::mat4(float value0, float value1, float value2, float value3,
		   float value4, float value5, float value6, float value7,
		   float value8, float value9, float value10, float value11,
		   float value12, float value13, float value14, float value15) {
	values[0][0] = value0;
	values[0][1] = value1;
	values[0][2] = value2;
	values[0][3] = value3;
	values[1][0] = value4;
	values[1][1] = value5;
	values[1][2] = value6;
	values[1][3] = value7;
	values[2][0] = value8;
	values[2][1] = value9;
	values[2][2] = value10;
	values[2][3] = value11;
	values[3][0] = value12;
	values[3][1] = value13;
	values[3][2] = value14;
	values[3][3] = value15;
}
mat4::~mat4() {}

mat4 mat4::operator*(float scale) {
    float newValues[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			newValues[i][ j] = this->values[i][ j] * scale;
		}
	}
	return mat4(newValues[0][0], newValues[0][1], newValues[0][2], newValues[0][3],
		newValues[1][0], newValues[1][1], newValues[1][2], newValues[1][3],
		newValues[2][0], newValues[2][1], newValues[2][2], newValues[2][3],
		newValues[3][0], newValues[3][1], newValues[3][2], newValues[3][3]);
}

vec4 mat4::operator*(vec4& vector) {
    float newValues[4];
    float vectorX = vector.x();
    float vectorY = vector.y();
    float vectorZ = vector.z();
    float vectorW = vector.w();

    for (int i = 0; i < 4; i++) {
        newValues[i] = this->values[i][0] * vectorX + this->values[i][1] * vectorY + this->values[i][2] * vectorZ + this->values[i][3] * vectorW;
    }

    return vec4(newValues[0], newValues[1], newValues[2], newValues[3]);
}

mat4 mat4::operator*(const mat4& right) const {
    float newValues[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            newValues[i][j] = this->values[i][0] * right.values[0][j] + this->values[i][1] * right.values[1][j] + this->values[i][2] * right.values[2][j] + this->values[i][3] * right.values[3][j];
        }
    }

    return mat4(newValues[0][0], newValues[0][1], newValues[0][2], newValues[0][3],
				newValues[1][0], newValues[1][1], newValues[1][2], newValues[1][3],
				newValues[2][0], newValues[2][1], newValues[2][2], newValues[2][3],
				newValues[3][0], newValues[3][1], newValues[3][2], newValues[3][3]);
}

mat4 mat4::transpose() {
	return mat4{ this->values[0][0],  this->values[1][0],  this->values[2][0],  this->values[3][0],
				 this->values[0][1],  this->values[1][1],  this->values[2][1],  this->values[3][1],
				 this->values[0][2],  this->values[1][2],  this->values[2][2],  this->values[3][2],
				 this->values[0][3],  this->values[1][3],  this->values[2][3],  this->values[3][3]
	};
}

float mat4::det() {
	return this->values[0][3] * this->values[1][2] * this->values[2][1] * this->values[3][0] - this->values[0][2] * this->values[1][3] * this->values[2][1] * this->values[3][0] -
		   this->values[0][3] * this->values[1][1] * this->values[2][2] * this->values[3][0] + this->values[0][1] * this->values[1][3] * this->values[2][2] * this->values[3][0] +
		   this->values[0][2] * this->values[1][1] * this->values[2][3] * this->values[3][0] - this->values[0][1] * this->values[1][2] * this->values[2][3] * this->values[3][0] -
		   this->values[0][3] * this->values[1][2] * this->values[2][0] * this->values[3][1] + this->values[0][2] * this->values[1][3] * this->values[2][0] * this->values[3][1] +
		   this->values[0][3] * this->values[1][0] * this->values[2][2] * this->values[3][1] - this->values[0][0] * this->values[1][3] * this->values[2][2] * this->values[3][1] -
		   this->values[0][2] * this->values[1][0] * this->values[2][3] * this->values[3][1] + this->values[0][0] * this->values[1][2] * this->values[2][3] * this->values[3][1] +
		   this->values[0][3] * this->values[1][1] * this->values[2][0] * this->values[3][2] - this->values[0][1] * this->values[1][3] * this->values[2][0] * this->values[3][2] -
		   this->values[0][3] * this->values[1][0] * this->values[2][1] * this->values[3][2] + this->values[0][0] * this->values[1][3] * this->values[2][1] * this->values[3][2] +
		   this->values[0][1] * this->values[1][0] * this->values[2][3] * this->values[3][2] - this->values[0][0] * this->values[1][1] * this->values[2][3] * this->values[3][2] -
		   this->values[0][2] * this->values[1][1] * this->values[2][0] * this->values[3][3] + this->values[0][1] * this->values[1][2] * this->values[2][0] * this->values[3][3] +
		   this->values[0][2] * this->values[1][0] * this->values[2][1] * this->values[3][3] - this->values[0][0] * this->values[1][2] * this->values[2][1] * this->values[3][3] -
		   this->values[0][1] * this->values[1][0] * this->values[2][2] * this->values[3][3] + this->values[0][0] * this->values[1][1] * this->values[2][2] * this->values[3][3];
}

mat4 mat4::inverse() {
	float determinant = this->det();
    if (determinant != 0) {
        float inv[4][4];

        inv[0][0] = (values[1][1] * values[2][2] * values[3][3] -
            values[1][1] * values[2][3] * values[3][2] -
            values[2][1] * values[1][2] * values[3][3] +
            values[2][1] * values[1][3] * values[3][2] +
            values[3][1] * values[1][2] * values[2][3] -
            values[3][1] * values[1][3] * values[2][2]) / determinant;

        inv[1][0] = (-values[1][0] * values[2][2] * values[3][3] +
            values[1][0] * values[2][3] * values[3][2] +
            values[2][0] * values[1][2] * values[3][3] -
            values[2][0] * values[1][3] * values[3][2] -
            values[3][0] * values[1][2] * values[2][3] +
            values[3][0] * values[1][3] * values[2][2]) / determinant;

        inv[2][0] = (values[1][0] * values[2][1] * values[3][3] -
            values[1][0] * values[2][3] * values[3][1] -
            values[2][0] * values[1][1] * values[3][3] +
            values[2][0] * values[1][3] * values[3][1] +
            values[3][0] * values[1][1] * values[2][3] -
            values[3][0] * values[1][3] * values[2][1]) / determinant;

        inv[3][0] = (-values[1][0] * values[2][1] * values[3][2] +
            values[1][0] * values[2][2] * values[3][1] +
            values[2][0] * values[1][1] * values[3][2] -
            values[2][0] * values[1][2] * values[3][1] -
            values[3][0] * values[1][1] * values[2][2] +
            values[3][0] * values[1][2] * values[2][1]) / determinant;

        inv[0][1] = (-values[0][1] * values[2][2] * values[3][3] +
            values[0][1] * values[2][3] * values[3][2] +
            values[2][1] * values[0][2] * values[3][3] -
            values[2][1] * values[0][3] * values[3][2] -
            values[3][1] * values[0][2] * values[2][3] +
            values[3][1] * values[0][3] * values[2][2]) / determinant;

        inv[1][1] = (values[0][0] * values[2][2] * values[3][3] -
            values[0][0] * values[2][3] * values[3][2] -
            values[2][0] * values[0][2] * values[3][3] +
            values[2][0] * values[0][3] * values[3][2] +
            values[3][0] * values[0][2] * values[2][3] -
            values[3][0] * values[0][3] * values[2][2]) / determinant;

        inv[2][1] = (-values[0][0] * values[2][1] * values[3][3] +
            values[0][0] * values[2][3] * values[3][1] +
            values[2][0] * values[0][1] * values[3][3] -
            values[2][0] * values[0][3] * values[3][1] -
            values[3][0] * values[0][1] * values[2][3] +
            values[3][0] * values[0][3] * values[2][1]) / determinant;

        inv[3][1] = (values[0][0] * values[2][1] * values[3][2] -
            values[0][0] * values[2][2] * values[3][1] -
            values[2][0] * values[0][1] * values[3][2] +
            values[2][0] * values[0][2] * values[3][1] +
            values[3][0] * values[0][1] * values[2][2] -
            values[3][0] * values[0][2] * values[2][1]) / determinant;

        inv[0][2] = (values[0][1] * values[1][2] * values[3][3] -
            values[0][1] * values[1][3] * values[3][2] -
            values[1][1] * values[0][2] * values[3][3] +
            values[1][1] * values[0][3] * values[3][2] +
            values[3][1] * values[0][2] * values[1][3] -
            values[3][1] * values[0][3] * values[1][2]) / determinant;

        inv[1][2] = (-values[0][0] * values[1][2] * values[3][3] +
            values[0][0] * values[1][3] * values[3][2] +
            values[1][0] * values[0][2] * values[3][3] -
            values[1][0] * values[0][3] * values[3][2] -
            values[3][0] * values[0][2] * values[1][3] +
            values[3][0] * values[0][3] * values[1][2]) / determinant;

        inv[2][2] = (values[0][0] * values[1][1] * values[3][3] -
            values[0][0] * values[1][3] * values[3][1] -
            values[1][0] * values[0][1] * values[3][3] +
            values[1][0] * values[0][3] * values[3][1] +
            values[3][0] * values[0][1] * values[1][3] -
            values[3][0] * values[0][3] * values[1][1]) / determinant;

        inv[3][2] = (-values[0][0] * values[1][1] * values[3][2] +
            values[0][0] * values[1][2] * values[3][1] +
            values[1][0] * values[0][1] * values[3][2] -
            values[1][0] * values[0][2] * values[3][1] -
            values[3][0] * values[0][1] * values[1][2] +
            values[3][0] * values[0][2] * values[1][1]) / determinant;

        inv[0][3] = (-values[0][1] * values[1][2] * values[2][3] +
            values[0][1] * values[1][3] * values[2][2] +
            values[1][1] * values[0][2] * values[2][3] -
            values[1][1] * values[0][3] * values[2][2] -
            values[2][1] * values[0][2] * values[1][3] +
            values[2][1] * values[0][3] * values[1][2]) / determinant;

        inv[1][3] = (values[0][0] * values[1][2] * values[2][3] -
            values[0][0] * values[1][3] * values[2][2] -
            values[1][0] * values[0][2] * values[2][3] +
            values[1][0] * values[0][3] * values[2][2] +
            values[2][0] * values[0][2] * values[1][3] -
            values[2][0] * values[0][3] * values[1][2]) / determinant;

        inv[2][3] = (-values[0][0] * values[1][1] * values[2][3] +
            values[0][0] * values[1][3] * values[2][1] +
            values[1][0] * values[0][1] * values[2][3] -
            values[1][0] * values[0][3] * values[2][1] -
            values[2][0] * values[0][1] * values[1][3] +
            values[2][0] * values[0][3] * values[1][1]) / determinant;

        inv[3][3] = (values[0][0] * values[1][1] * values[2][2] -
            values[0][0] * values[1][2] * values[2][1] -
            values[1][0] * values[0][1] * values[2][2] +
            values[1][0] * values[0][2] * values[2][1] +
            values[2][0] * values[0][1] * values[1][2] -
            values[2][0] * values[0][2] * values[1][1]) / determinant;

        return mat4{ inv[0][0], inv[0][1], inv[0][2], inv[0][3],
                     inv[1][0], inv[1][1], inv[1][2], inv[1][3],
                     inv[2][0], inv[2][1], inv[2][2], inv[2][3],
                     inv[3][0], inv[3][1], inv[3][2], inv[3][3]
        };
	}

	else {
		std::cout << "\n!!!Determinant = 0, inverse matrix doesn't exist, returning 0-matrix instead!!!\n";
		return mat4{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	}
}

mat4 mat4::translation(const vec3 & t) {
	mat4 translationMatrix(1, 0, 0, t.values[0],
						   0, 1, 0, t.values[1],
						   0, 0, 1, t.values[2],
						   0, 0, 0, 1);

	mat4 originalMatrix(values[0][0], values[0][1], values[0][2], values[0][3],
						values[1][0], values[1][1], values[1][2], values[1][3],
						values[2][0], values[2][1], values[2][2], values[2][3],
						values[3][0], values[3][1], values[3][2], values[3][3]);

	mat4 newValues = translationMatrix * originalMatrix;
	return newValues;
};

mat4 mat4::rotationX(float a) {
	mat4 translationMatrix(1, 0, 0, 0,
						   0, cos(a), -sin(a), 0,
						   0, sin(a), cos(a), 0,
						   0, 0, 0, 1);

	mat4 originalMatrix(values[0][0], values[0][1], values[0][2], values[0][3],
						values[1][0], values[1][1], values[1][2], values[1][3],
						values[2][0], values[2][1], values[2][2], values[2][3],
						values[3][0], values[3][1], values[3][2], values[3][3]);

	mat4 newValues = translationMatrix * originalMatrix;
	return newValues;
}

mat4 mat4::rotationY(float a) {
	mat4 translationMatrix(cos(a), 0, sin(a), 0,
						   0, 1, 0, 0,
						   -sin(a), 0, cos(a), 0,
						   0, 0, 0, 1);

	mat4 originalMatrix(values[0][0], values[0][1], values[0][2], values[0][3],
						values[1][0], values[1][1], values[1][2], values[1][3],
						values[2][0], values[2][1], values[2][2], values[2][3],
						values[3][0], values[3][1], values[3][2], values[3][3]);

	mat4 newValues = translationMatrix * originalMatrix;
	return newValues;
}

mat4 mat4::rotationZ(float a) {
	mat4 translationMatrix(cos(a), -sin(a), 0, 0,
						   sin(a), cos(a), 0, 0,
						   0, 0, 1, 0,
						   0, 0, 0, 1);

	mat4 originalMatrix(values[0][0], values[0][1], values[0][2], values[0][3],
						values[1][0], values[1][1], values[1][2], values[1][3],
						values[2][0], values[2][1], values[2][2], values[2][3],
						values[3][0], values[3][1], values[3][2], values[3][3]);

	mat4 newValues = translationMatrix * originalMatrix;
	return newValues;
}

void mat4::print() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << std::setw(13) << std::left << this->values[i][j];
		}
		std::cout << std::endl;
	}
}
