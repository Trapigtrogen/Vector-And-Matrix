#include "pch.h"
#include <iostream>
#include "vectors.h"
#include "matrices.h"

int main() {
	mat4 matrix(1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
	);
	
	mat4 matrix2(4.0f, 3.0f, 0.0f, 1.0f,
				1.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 1.0f,
				1.0f, 0.0f, 1.0f, 1.0f
	);

	vec4 vector1(2.0f, 1.0f, 7.0f, 1.0f);
	vec4 vector2(1.0f, 2.0f, 3.0f, 4.0f);

	std::cout << "Matrix 1:\n";
	matrix.print();
	std::cout << std::endl;
	std::cout << "determinant: " << matrix.det() << std::endl << std::endl;

	std::cout << "Matrix 2:\n";
	matrix2.print();
	std::cout << std::endl;
	std::cout << "determinant: " << matrix2.det() << std::endl << std::endl;
	
	std::cout << "Matrix 1 transposed:\n";
	mat4 matrixTransposed = matrix.transpose();
	matrixTransposed.print();
	std::cout << std::endl;

	std::cout << "Matrix 1 scaled:\n";
	mat4 matrixScaled = matrix * 2;
	matrixScaled.print();
	std::cout << std::endl;

	std::cout << "Matrix 1 inverted:\n";
	mat4 matrixInverted = matrix.inverse();
	matrixInverted.print();
	std::cout << std::endl;

	std::cout << "Matrix 1 multiplied by matrix 2:\n";
	mat4 newMatrix = matrix * matrix2;
	newMatrix.print();
	std::cout << std::endl;

	std::cout << "Vector 1: ( " << vector1.x() << " " << vector1.y() << " " << vector1.z() << " " << vector1.w() << " )\n";

	std::cout << "Matrix 2 multiplied by vector 1:\n";
	vec4 newVector = matrix2 * vector1;
	std::cout << "( " << newVector.x() << " " << newVector.y() << " " << newVector.z() << " " << newVector.w() << " )\n";
	std::cout << std::endl;

	std::cout << "Matrix 1 rotated X by 45 degrees:\n";
	mat4 matrixRotatedX = matrix.rotationX((45 * 3.141529) / 180);
	matrixRotatedX.print();
	std::cout << std::endl;

	std::cout << "Matrix 1 rotated Y by 180 degrees:\n";
	mat4 matrixRotatedY = matrix.rotationY((180 * 3.141529) / 180);
	matrixRotatedY.print();
	std::cout << std::endl;

	std::cout << "Matrix 1 rotated Z by 90 degrees:\n";
	mat4 matrixRotatedZ = matrix.rotationZ((90 * 3.141529) / 180);
	matrixRotatedZ.print();
	std::cout << std::endl;
	
	std::cout << "Matrix 1 translated by (10, 5, 10):\n";
	mat4 matrixTranslated = matrix.translation(vec3(10, 5, 10));
	matrixTranslated.print();
	std::cout << std::endl;
}