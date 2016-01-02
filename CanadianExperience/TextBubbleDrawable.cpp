/**
 * \file TextBubbleDrawable.cpp
 *
 * \author Siyan Ma
 */

#include "stdafx.h"
#include "TextBubbleDrawable.h"
#include "TextBubbleDlg.h"
#include "Actor.h"
#include "Timeline.h"

using namespace std;

/** \brief Constructor for a text bubble object
* \param name The drawable name */
CTextBubbleDrawable::CTextBubbleDrawable(const std::wstring &name) : CDrawable(name), CTextBubble()
{

}

/**
* \brief Destructor
*/
CTextBubbleDrawable::~CTextBubbleDrawable()
{
}


/**
* \brief Set the actor. This is where we set the channel name
* \param actor Actor to set
*/
void CTextBubbleDrawable::SetActor(CActor *actor)
{
	// Set the channel name
	mPositionChannel.SetName(actor->GetName() + L":" + GetName() + L":position");
	mTextChannel.SetName(actor->GetName() + L":" + GetName() + L":text");

}


/**
* \brief Set the timeline. The tells the channel the timeline
* \param timeline Timeline to set
*/
void CTextBubbleDrawable::SetTimeline(CTimeline *timeline)
{
	timeline->AddChannel(&mPositionChannel);
	timeline->AddChannel(&mTextChannel);
}


/** \brief Set the keyframe based on the current status.
*/
void CTextBubbleDrawable::SetKeyframe()
{
	mPositionChannel.SetKeyframe(GetPosition());
	mTextChannel.SetKeyframe(this->GetText(), this->GetMirror());
}

/** \brief Get the current channel from the animation system.
*/
void CTextBubbleDrawable::GetKeyframe()
{
	if (mPositionChannel.IsValid())
		SetPosition(mPositionChannel.GetPoint());
	if (mTextChannel.IsValid())
	{
		SetText(mTextChannel.GetText());
		SetMirror(mTextChannel.GetMirror());
	}
		
}


/*! \brief Draw our text bubble.
* \param  graphics The graphics context to draw on
*/
void CTextBubbleDrawable::Draw(Gdiplus::Graphics *graphics)
{
	CTextBubble::SetBubblePosition(mPlacedPosition.X, mPlacedPosition.Y);
	CTextBubble::DrawMe(graphics);
}


/** \brief Test to see if we hit this object with a mouse click
* \param pos Click position
* \returns true it hit
*/
bool CTextBubbleDrawable::HitTest(Gdiplus::Point pos)
{
	return CTextBubble::IsPointInside(pos.X, pos.Y);
}


/** \brief Implamentation of Edit/TextBubble properties menu option
*/
void CTextBubbleDrawable::SetTextBubbleProperties()
{
	// Create the dialog box object
	CTextBubbleDlg dlg;

	// Tell it about the text bubble
	dlg.SetTextBubble(this);

	if (dlg.DoModal() == IDOK)
	{
		// Take the changes to the text bubble
		dlg.Take();
	}
}

