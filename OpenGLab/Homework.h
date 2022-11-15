#pragma once
#include "Point.h"

class Homework
{
public:
	static void DrawLine(Point startPoint, Point endPoint);

	static void DrawTriangle(Point pRight, Point pLeft, Point pTop);

	static void DrawRectangle(Point pUpperRight, Point pUpperLeft,
		Point pLowerLeft, Point pLowerRight);
	static void DrawCircleFill(float cx, float cy, float r, int num_segments);

	static void DrawSolidCircle(Point center, float radius);

	static void DrawCircle(Point center, float radius);

	static void DrawArc(Point startPoint, Point endPoint, float radius);

	static void DrawArc(Point center, float radius,
		float startAngle, float endAngle);
	static void DrawSineWave(float xStart, float xEnd);

	static void DrawCosineWave(float xStart, float xEnd);

	static void DrawCharacter(Point nose, float bodyLength,
		float headRadius, float handLength,
		float legLength);

};
