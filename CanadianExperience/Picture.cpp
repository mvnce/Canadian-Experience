/**
 * \file Picture.cpp
 *
 * 
 */

#include "stdafx.h"
#include "Picture.h"
#include "Actor.h"

using namespace Gdiplus;

/**
 * \brief Constructor
 */
CPicture::CPicture()
{
}


/**
 * \brief Destructor
 */
CPicture::~CPicture()
{
}

/** \brief Set the current animation time
*
* This forces the animation of all
* objects to the current animation location.
* \param time The new time.
*/
void CPicture::SetAnimationTime(double time)
{
    mTimeline.SetCurrentTime(time);
    UpdateObservers();

    for (auto actor : mActors)
    {
        actor->GetKeyframe();
    }
}

/** \brief Add an observer to this picture.
* \param observer The observer to add
*/
void CPicture::AddObserver(CPictureObserver *observer)
{
    mObservers.push_back(observer);
}

/** \brief Remove an observer from this picture
* \param observer The observer to remove
*/
void CPicture::RemoveObserver(CPictureObserver *observer)
{
    auto loc = find(std::begin(mObservers), std::end(mObservers), observer);
    if (loc != std::end(mObservers))
    {
        mObservers.erase(loc);
    }
}

/** \brief Update all observers to indicate the picture has changed.
*/
void CPicture::UpdateObservers()
{
    for (auto observer : mObservers)
    {
        observer->UpdateObserver();
    }
}

/** \brief Draw this picture on a device context
* \param graphics The device context to draw on
*/
void CPicture::Draw(Gdiplus::Graphics *graphics)
{
    for (auto actor : mActors)
    {
        actor->Draw(graphics);
    }
}


/** Add an actor to this picture.
* \param actor The actor to add
*/
void CPicture::AddActor(std::shared_ptr<CActor> actor)
{
    mActors.push_back(actor);
    actor->SetPicture(this);
}

/** \brief Get the current animation time.
* \returns The current animation time
*/
double CPicture::GetAnimationTime()
{
    return mTimeline.GetCurrentTime();
}