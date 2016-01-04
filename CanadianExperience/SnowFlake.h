/**
 * \file SnowFlake.h
 *
 * \author Siyan Ma
 *
 * \brief a snow flake drawable based on polygons drawable
 */

#pragma once
#include "PolyDrawable.h"
#include <memory>


/**
 * \brief a snow flake drawable based on polygons drawable
 */
class CSnowFlake : public CPolyDrawable
{
public:
	CSnowFlake(double posX, double posY, double velocityX, double velecityY, std::wstring name);
	virtual ~CSnowFlake();

	/** \brief Default constructor disabled */
	CSnowFlake() = delete;
	/** \brief Copy constructor disabled */
	CSnowFlake(const CSnowFlake &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CSnowFlake &) = delete;

	void SetNext(std::shared_ptr<CSnowFlake> next);

	/** \brief Get the pointer to next snowflake
	* \returns The pointer to next snowflake */
	std::shared_ptr<CSnowFlake> GetNext() { return mNext; }

	void Draw(Gdiplus::Graphics *graphics, Gdiplus::SolidBrush *brush);

	/** \brief Set X position for the snowflake
	* \param posX The new X position */
	void SetPositionX(double posX) { mPositionX = posX; }

	/** \brief Set Y position for the snowflake
	* \param posY The new Y position */
	void SetPositionY(double posY) { mPositionY = posY; }
	 
	/** \brief Set X velocity for the snowflake
	* \param velocityX The new velocity in X direction */
	void SetVelocityX(double velocityX) { mVelocityX = velocityX; }

	/** \brief Set Y velocity for the snowflake
	* \param velocityY The new velocity in Y direction */
	void SetVelocityY(double velocityY) { mVelocityY = velocityY; }

	/** \brief Get the X position for the snowflake
	* \returns The X position */
	double GetPositionX() { return mPositionX; }

	/** \brief Get the Y position for the snowflake
	* \returns The Y position */
	double GetPositionY() { return mPositionY; }

	/** \brief Get the X velocity for the snowflake
	* \returns The X velocity */
	double GetVelocityX() { return mVelocityX; }

	/** \brief Get the Y velocity for the snowflake
	* \returns The Y velocity */
	double GetVelocityY() { return mVelocityY; }

private:
	/// flake initial x position
	double mPositionX = 0;

	/// flake initial y position
	double mPositionY = 0;

	/// flake initial speed in x axis
	double mVelocityX = 0;

	/// flake initial speed in y axis
	double mVelocityY = 0;

	/// point to next snow flake
	std::shared_ptr<CSnowFlake> mNext = nullptr;
};

