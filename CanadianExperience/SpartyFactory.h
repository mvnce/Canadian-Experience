/**
 * \file SpartyFactory.h
 *
 * 
 *
 * \brief Factory that builds the Sparty actor.
 */

#pragma once
#include "ActorFactory.h"


/**
 * \brief Factory that builds the Sparty actor.
 */
class CSpartyFactory :
    public CActorFactory
{
public:
    CSpartyFactory();
    virtual ~CSpartyFactory();

    std::shared_ptr<CActor> Create();

	/** \brief The TextBubbleDrawable for Sparty
	* \returns TextBubbleDrawable */
	std::shared_ptr<CTextBubbleDrawable> GetSpartyTextBubbleDrawable() { return mSpartyTextBubbleDrawable; }

private:
	/// The TextBubbleDrawable for Sparty
	std::shared_ptr<CTextBubbleDrawable> mSpartyTextBubbleDrawable;
};

