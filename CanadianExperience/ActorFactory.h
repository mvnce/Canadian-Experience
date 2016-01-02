/**
 * \file ActorFactory.h
 *
 * 
 *
 * \brief Abstract base class for actor factories.
 */

#pragma once

#include <memory>
#include "Actor.h"
#include "TextBubbleDrawable.h"

/** 
 * \brief Abstract base class for actor factories. 
 */
class CActorFactory
{
public:
    virtual ~CActorFactory();

    /** \brief Create the actor 
     * \returns New actor object */
    virtual std::shared_ptr<CActor> Create() = 0;

protected:
    CActorFactory();

};

