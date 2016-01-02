/**
 * \file HaroldFactory.h
 *
 * 
 *
 * \brief Factory class that builds the Harold character
 */

#pragma once
#include "ActorFactory.h"

/** 
 * \brief Factory class that builds the Harold character 
 */
class CHaroldFactory :
    public CActorFactory
{
public:
    CHaroldFactory();
    virtual ~CHaroldFactory();

    std::shared_ptr<CActor> Create(); 

	/** \brief The TextBubbleDrawable for Harold
	* \returns TextBubbleDrawable */
	std::shared_ptr<CTextBubbleDrawable> GetHaroldTextBubbleDrawable() { return mHaroldTextBubbleDrawable; }

private:
	/// The TextBubbleDrawable for Harold
	std::shared_ptr<CTextBubbleDrawable> mHaroldTextBubbleDrawable;
};

