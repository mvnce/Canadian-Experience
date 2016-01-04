/**
 * \file ParticleSystem.cpp
 *
 * \author Siyan Ma
 */

#include "stdafx.h"
#include "ParticleSystem.h"

using namespace std;
using namespace Gdiplus;

/** \brief Constructor for particle system
 * initialize ActiveSnow linked list and 
 * Inactive snow(SnowPool) linked list
 */
CParticleSystem::CParticleSystem()
{
	Gdiplus::SolidBrush brush(Color::White);
	mActiveSnow = make_shared <CSnowFlakeLinkedList>();
	mSnowPool = make_shared <CSnowFlakeLinkedList>();
}


/**
 * \brief Destructor
 */
CParticleSystem::~CParticleSystem()
{
}


/**
 * \brief Set the timeline. This is where we make connect with timeline
 * \param timeline Timeline to set
 */
void CParticleSystem::SetTimeline(CTimeline *timeline)
{
	mTimeline = timeline;
}


/**
 * \brief Create the snow pool. It initializes 1000 snow flake and ready to use
 */
void CParticleSystem::CreatePool()
{
	for (int i = 0; i < 1000; i++)
	{
		auto snowflake = make_shared<CSnowFlake>(0, 0, 0, 0, L"snowflake");
		mSnowPool->PushBack(snowflake);
	}
}


/**
 * \brief Draw the snow flake
 * \param graphics Graphics context to draw on
 * \param brush The GDI+ brush
 */
void CParticleSystem::Draw(Gdiplus::Graphics *graphics, Gdiplus::SolidBrush *brush)
{
	std::shared_ptr<CSnowFlake> snowflake = mActiveSnow->GetBegin();
	while (snowflake != nullptr)
	{
		snowflake->Draw(graphics, brush);
		snowflake = snowflake->GetNext();
	}
}


/** \brief Handle updates for snow flake animation
 * \param elapsed The time since the last update
 */
void CParticleSystem::Update(double elapsed)
{
	auto snowflake = mSnowPool->GetBegin();

	// counter for counting amount of added snowflake
	int cnt = 0;
	// control amount of snow flake, make variations
	int maxMove = 10 + (rand() / RAND_MAX) * 50;

	while (snowflake != nullptr && cnt < maxMove)
	{
		MoveSnowToActive(snowflake);

		snowflake->SetPositionX(-200 + ((double)rand() / RAND_MAX) * (mWindowWidth+200));
		snowflake->SetPositionY(((double)rand() / RAND_MAX) * -5);

		snowflake->SetVelocityX(10 + ((double)rand() / RAND_MAX) * 30);
		snowflake->SetVelocityY(20 + ((double)rand() / RAND_MAX) * 70);

		snowflake = snowflake->GetNext();
		cnt++;
	}

	snowflake = mActiveSnow->GetBegin();

	while (snowflake != nullptr)
	{
		// Set snow flake position
		snowflake->SetPositionX(snowflake->GetPositionX() + elapsed*snowflake->GetVelocityX());
		snowflake->SetPositionY(snowflake->GetPositionY() + elapsed*snowflake->GetVelocityY());

		auto next = snowflake->GetNext();
		
		if (next == nullptr)
		{
			break;
		}

		// move off-screen snow flake back to snow pool
		if (snowflake->GetPositionY() > mWindowHeight || snowflake->GetPositionX() > mWindowWidth)
		{
			MoveSnowToPool(snowflake);
			snowflake = next;
		}

		snowflake = snowflake->GetNext();
	}
}


/** \brief Move snow flake to active snow linked list
 * \param snowflake The snowflake which is needed to move
 */
void CParticleSystem::MoveSnowToActive(std::shared_ptr<CSnowFlake> snowflake)
{
	mActiveSnow->PushBack(snowflake);
	mSnowPool->Remove(snowflake);
}


/** \brief Move snow flake to snow pool(inactive snow) linked list
 * \param snowflake The snowflake which is needed to move
 */
void CParticleSystem::MoveSnowToPool(std::shared_ptr<CSnowFlake> snowflake)
{
	mSnowPool->PushBack(snowflake);
	mActiveSnow->Remove(snowflake);
}


/** \brief Reset partical system.
 *  move active snowflakes out-off screen
 *  then it will be moved all snowfalke to inactive pool
 */
void CParticleSystem::Reset()
{
	auto snowflake = mActiveSnow->GetBegin();

	while (snowflake != nullptr)
	{	
		snowflake->SetPositionX(900);
		snowflake->SetPositionY(800);

		snowflake = snowflake->GetNext();
	}
}


/** \brief Se the Height and Width for window size
 * the picture size is a contant value (800,600)
 * set the values as window height and width
 * \param size The window size to set
 */
void CParticleSystem::SetPictureSize(Gdiplus::Size size)
{
	mWindowHeight = size.Height;
	mWindowWidth = size.Width;
}