/**
 * \file HandProp.cpp
 *
 * \author Siyan Ma
 */

#include "stdafx.h"
#include "HandProp.h"
#include "Actor.h"
#include "Timeline.h"

using namespace Gdiplus;
using namespace std;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

/** \brief Constructor for a prop of the hand object
* \param name The drawable name to use
* \param filename The filename for the image to use
*/
CHandProp::CHandProp(const std::wstring &name, const std::wstring &filename) : CImageDrawable(name, filename)
{
}


/**
* \brief Destructor
*/
CHandProp::~CHandProp()
{
}


/**
* \brief Set the actor. This is where we set the channel name
* \param actor Actor to set
*/
void CHandProp::SetActor(CActor *actor)
{
	CImageDrawable::SetActor(actor);

	// Set the channel name
	mPositionChannel.SetName(actor->GetName() + L":" + GetName() + L":position");

}


/**
* \brief Set the timeline. The tells the channel the timeline
* \param timeline Timeline to set
*/
void CHandProp::SetTimeline(CTimeline *timeline)
{
	CImageDrawable::SetTimeline(timeline);

	timeline->AddChannel(&mPositionChannel);
}


/** \brief Set the keyframe based on the current status.
*/
void CHandProp::SetKeyframe()
{
	CImageDrawable::SetKeyframe();

	mPositionChannel.SetKeyframe(GetPosition());
}

/** \brief Get the current channel from the animation system.
*/
void CHandProp::GetKeyframe()
{
	CImageDrawable::GetKeyframe();

	if (mPositionChannel.IsValid())
		SetPosition(mPositionChannel.GetPoint());
}


/**
* \brief Draw the head
* \param graphics Graphics context to draw on
*/
void CHandProp::Draw(Gdiplus::Graphics *graphics)
{
	CImageDrawable::Draw(graphics);
}


/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CHandProp::TransformPoint(Gdiplus::Point p)
{
	// Make p relative to the image center
	p = p - GetCenter();

	// Rotate as needed and offset
	return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

