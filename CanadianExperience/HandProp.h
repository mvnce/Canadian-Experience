/**
 * \file HandProp.h
 *
 * \author Siyan Ma
 *
 * \brief Implements the hand prop of a characters,
 * which has special functionality.
 */

#pragma once
#include "ImageDrawable.h"
#include "AnimChannelPoint.h"

/** \brief Implements the hand prop of a characters,
* which has special functionality.
*/
class CHandProp :
	public CImageDrawable
{
public:
	CHandProp(const std::wstring &name, const std::wstring &filename);
	~CHandProp();

	/** \brief Default constructor disabled */
	CHandProp() = delete;
	/** \brief Copy constructor disabled */
	CHandProp(const CHandProp &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CHandProp &) = delete;

	/// \brief Is this drawable moveable?
	/// \returns true
	virtual bool IsMovable() { return true; }

	void Draw(Gdiplus::Graphics *graphics);

	virtual void SetActor(CActor *actor) override;
	virtual void SetTimeline(CTimeline *timeline) override;
	virtual void SetKeyframe() override;
	virtual void GetKeyframe() override;

private:
	Gdiplus::Point TransformPoint(Gdiplus::Point p);

	/// Channel for the hand prop position
	CAnimChannelPoint mPositionChannel;
};

