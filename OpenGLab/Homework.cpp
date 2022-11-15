#include "Homework.h"
#include <windows.h>
#include <gl\gl.h>
#include <cmath>

const float DEPTH = -25;

void Homework::DrawLine(Point startPoint, Point endPoint)
{
	glBegin(GL_LINES);
	glVertex2f(startPoint.x, startPoint.y);
	glVertex2f(endPoint.x, endPoint.y);
	glEnd();
}

void Homework::DrawTriangle(Point pRight, Point pLeft, Point pTop)
{
	glBegin(GL_TRIANGLES);
	glVertex3f(pRight.x, pRight.y, pRight.z);
	glVertex3f(pLeft.x, pLeft.y, pLeft.z);
	glVertex3f(pTop.x, pTop.y, pTop.z);
	glEnd();
}

void Homework::DrawRectangle(Point pUpperRight, Point pUpperLeft,
	Point pLowerLeft, Point pLowerRight)
{
	glBegin(GL_QUADS);
	glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z);
	glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
	glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
	glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
	glEnd();
}

void Homework::DrawCircle(Point center, float radius)
{
	glBegin(GL_POINTS);

	for (float angle = 0; angle < (2 * 3.14); angle += 0.001)
	{

		float xPoint = radius * cos(angle);
		float yPoint = radius * sin(angle);
		glVertex3f(center.x + xPoint, center.y + yPoint, DEPTH);
	}

	glEnd();
}

void Homework::DrawSolidCircle(Point center, float radius)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	for (float angle = 0; angle < (2 * 3.14); angle += 0.001)
	{

		float xPoint = radius * cos(angle);
		float yPoint = radius * sin(angle);
		glVertex3f(center.x + xPoint, center.y + yPoint, DEPTH);
	}

	glEnd();
}

void Homework::DrawArc(Point center, float radius,
	float startAngle, float endAngle)
{
	glBegin(GL_POINTS);

	for (float angle = startAngle; angle < endAngle; angle += 0.005)
	{
		float xPoint = radius * cos(angle);
		float yPoint = radius * sin(angle);
		glVertex3f(center.x + xPoint, center.y + yPoint, DEPTH);
	}

	glEnd();
}

void Homework::DrawCircleFill(float cx, float cy, float r, int num_segments)
{

}

void Homework::DrawSineWave(float xStart, float xEnd)
{
	glBegin(GL_POINTS);

	for (xStart = 0; xStart < xEnd; xStart += 0.01)
	{
		float y = sin(2 * xStart);
		glVertex3f(xStart, y - 10, DEPTH);
	}

	glEnd();
}

void Homework::DrawCosineWave(float xStart, float xEnd)
{
	glBegin(GL_POINTS);

	for (; xStart < xEnd; xStart += 0.01)
	{
		float y = cos(2 * xStart);
		glVertex3f(xStart, y - 5, -25);
	}

	glEnd();
}

void Homework::DrawCharacter(Point nose, float bodyLength,
	float headRadius, float handLength,
	float legLength)
{

	Point headPoint(nose.x, nose.y + 0.25, DEPTH);
	Point eye1Point(nose.x + 0.5, nose.y + 0.75, DEPTH);
	Point eye2Point(nose.x - 0.5, nose.y + 0.75, DEPTH);
	Point mouthPoint(nose.x, nose.y - 0.35, DEPTH);
	Point eyebrow1Point(nose.x + 0.5, nose.y + 1.05, DEPTH);
	Point eyebrow2Point(nose.x - 0.5, nose.y + 1.05, DEPTH);

	// Draw charecter face
	// head
	DrawCircle(headPoint, headRadius);
	// nose
	DrawCircle(nose, 0.1);
	// eyes
	DrawCircle(eye1Point, 0.2);
	DrawCircle(eye2Point, 0.2);
	// mouth
	DrawArc(mouthPoint, 0.3, 3.14, 6.28);
	// eyeborws
	DrawArc(eyebrow1Point, 0.3, 1, 2.14);
	DrawArc(eyebrow2Point, 0.3, 1, 2.14);

	// Draw charecter body

	// body
	glBegin(GL_LINES);
	glVertex3f(nose.x, nose.y - headRadius + 0.2, DEPTH);
	glVertex3f(nose.x, nose.y - headRadius - bodyLength, DEPTH);

	// left hand
	glVertex3f(nose.x, nose.y - headRadius - 1, DEPTH);
	glVertex3f(nose.x - handLength, nose.y - headRadius - handLength - 1, DEPTH);

	// right hand
	glVertex3f(nose.x, nose.y - headRadius - 1, DEPTH);
	glVertex3f(nose.x + handLength, nose.y - headRadius - handLength - 1, DEPTH);

	// left leg
	glVertex3f(nose.x, nose.y - headRadius - bodyLength, DEPTH);
	glVertex3f(nose.x - legLength, nose.y - bodyLength - headRadius * legLength - 1, DEPTH);

	// right leg
	glVertex3f(nose.x, nose.y - headRadius - bodyLength, DEPTH);
	glVertex3f(nose.x + legLength, nose.y - bodyLength - headRadius * legLength - 1, DEPTH);

	glEnd();
}
