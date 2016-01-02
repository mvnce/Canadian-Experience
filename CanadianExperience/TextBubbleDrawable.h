/**
 * \file TextBubbleDrawable.h
 *
 * \author Siyan Ma
 *
 * \brief A drawable based on text bubble.
 */

#pragma once
#include "Drawable.h"
#include "TextBubble.h"
#include "AnimChannelPoint.h"
#include "AnimChannelText.h"

/**
* \brief A drawable based on text bubble.
*
* This class has a list of points and draws a text bubble
* drawable based on those points.
*/
class CTextBubbleDrawable :
	public CDrawable, private CTextBubble
{
public:
	CTextBubbleDrawable(const std::wstring &name);
	virtual ~CTextBubbleDrawable();

	/** \brief Default constructor disabled */
	CTextBubbleDrawable() = delete;
	/** \brief Copy constructor disabled */
	CTextBubbleDrawable(const CTextBubbleDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CTextBubbleDrawable &) = delete;

	virtual void Draw(Gdiplus::Graphics *graphics) override;
	virtual bool HitTest(Gdiplus::Point pos) override;

	/** \brief Is this a movable drawable?
	* \returns true if movable */
	virtual bool IsMovable() override { return true; }

	/** \brief Set the text which is in text bubble
	* \param str The text which is in text bubble*/
	void SetText(std::wstring &str) { CTextBubble::SetText(str); }

	/** \brief Get the text which is in text bubble
	* \returns The text which is in text bubble*/
	std::wstring GetText() { return CTextBubble::GetText(); }

	/** \brief Set the text bubble mirror
	* \param m The text bubble mirror status*/
	void SetMirror(bool m) { CTextBubble::SetMirrored(m); }

	/** \brief Get the text bubble mirror
	* \returns The text bubble mirror status*/
	bool GetMirror() { return CTextBubble::GetMirror(); }

	virtual void SetActor(CActor *actor) override;
	virtual void SetTimeline(CTimeline *timeline) override;
	virtual void SetKeyframe() override;
	virtual void GetKeyframe() override;

	void SetTextBubbleProperties();

private:
	/// The animation channel for animating the point of this drawable
	CAnimChannelPoint mPositionChannel;

	/// The animation channel for animating the text of this drawable
	CAnimChannelText mTextChannel;
};

