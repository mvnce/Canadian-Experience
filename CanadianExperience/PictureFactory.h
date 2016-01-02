/**
 * \file PictureFactory.h
 *
 * 
 *
 * \brief A factory class that builds our picture.
 */

#pragma once

#include <memory>

#include "Picture.h"
#include "TextBubbleDrawable.h"


/**
 * \brief A factory class that builds our picture.
 */
class CPictureFactory
{
public:
    CPictureFactory();
    virtual ~CPictureFactory();

    std::shared_ptr<CPicture> Create();

	/** \brief The TextBubbleDrawable for Harold
	* \returns TextBubbleDrawable */
	std::shared_ptr<CTextBubbleDrawable> GetHaroldTextBubbleDrawable() { return mHaroldTextBubbleDrawable; }

	/** \brief The TextBubbleDrawable for Sparty
	* \returns TextBubbleDrawable */
	std::shared_ptr<CTextBubbleDrawable> GetSpartyTextBubbleDrawable() { return mSpartyTextBubbleDrawable; }

private:
	/// The TextBubbleDrawable for Harold
	std::shared_ptr<CTextBubbleDrawable> mHaroldTextBubbleDrawable;

	/// The TextBubbleDrawable for Sparty
	std::shared_ptr<CTextBubbleDrawable> mSpartyTextBubbleDrawable;

};

