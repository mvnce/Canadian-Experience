/**
 * \file ParticleSystem.h
 *
 * \author Siyan Ma
 *
 * \brief A system class that can operate snow.
 */

#pragma once
#include <string>
#include <memory>
#include "SnowFlakeLinkedList.h"

class CTimeline;

/**
 * \brief A system class that can operate snow.
 */
class CParticleSystem
{
public:
	CParticleSystem();
	virtual ~CParticleSystem();

	/** \brief Copy constructor disabled */
	CParticleSystem(const CParticleSystem &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CParticleSystem &) = delete;

	void CreatePool();
	void MoveSnowToActive(std::shared_ptr<CSnowFlake> snowflake);
	void MoveSnowToPool(std::shared_ptr<CSnowFlake> snowflake);
	void Draw(Gdiplus::Graphics *graphics, Gdiplus::SolidBrush *brush);
	void Update(double epalsed);

	void SetTimeline(CTimeline *timeline);

	void SetPictureSize(Gdiplus::Size size);

	void Reset();

private:
	/// The height of window picture
	int mWindowHeight = 0;

	/// The width of window picuture
	int mWindowWidth = 0;

	/// The Active snow linked list
	std::shared_ptr<CSnowFlakeLinkedList> mActiveSnow;

	/// The snow pool that contains inactive snow
	std::shared_ptr<CSnowFlakeLinkedList> mSnowPool ;

	/// The animation timeline
	CTimeline *mTimeline = nullptr;

};

