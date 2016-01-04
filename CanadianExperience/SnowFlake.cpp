/**
 * \file SnowFlake.cpp
 *
 * \author Siyan Ma
 */

#include "stdafx.h"
#include "SnowFlake.h"

using namespace Gdiplus;
using namespace std;

/** \brief Constructor for snow flake
 * \param posX The X position to use
 * \param posY The Y position to use
 * \param velocityX The X velocity to use
 * \param velocityY The Y velocity to use
 * \param name The Polydrawable name to use
 */
CSnowFlake::CSnowFlake(double posX, double posY, double velocityX, double velocityY, std::wstring name) 
	: CPolyDrawable(name)
{
	mPositionX = posX;
	mPositionY = posY;
	mVelocityX = velocityX;
	mVelocityY = velocityY;
}


/**
 * \brief Destructor
 */
CSnowFlake::~CSnowFlake()
{
}


/**
 * \brief Set the next snowflake
 * \param next The pointer to next snowflake
 */
void CSnowFlake::SetNext(std::shared_ptr<CSnowFlake> next)
{
	mNext = next;
	assert(mNext.get() != this);
}


/** \brief Draw the snowflake
 * \param graphics The GDI+ graphics context to draw on
 * \param brush The GDI+ brush
 */
void CSnowFlake::Draw(Gdiplus::Graphics *graphics, Gdiplus::SolidBrush *brush)
{
	graphics->FillEllipse(brush, mPositionX, mPositionY, 8, 8);
}

