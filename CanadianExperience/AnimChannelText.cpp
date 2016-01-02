/**
 * \file AnimChannelText.cpp
 *
 * \author Siyan Ma
 */

#include "stdafx.h"
#include "AnimChannelText.h"

using namespace std;

CAnimChannelText::CAnimChannelText()
{
}


CAnimChannelText::~CAnimChannelText()
{
}


/**
* \brief Set a keyframe
*
* This function allocates a new keyframe and sends it to
* CAnimChannel, which will insert it into the collection of keyframes.
* \param text Text for the keyframe.
* \param mirror Mirror for the keyframe
*/
void CAnimChannelText::SetKeyframe(std::wstring text, bool mirror)
{
	// Create a keyframe of the appropriate type
	// Telling it this channel and the text
	shared_ptr<KeyframeText> keyframe = make_shared<KeyframeText>(this, text, mirror);

	// Insert it into the collection
	InsertKeyframe(keyframe);
}


/**
* \brief Tween between two text keyframes
* \param t The t value between the frames
*/
void CAnimChannelText::Tween(double t)
{
	if (t = 1)
		mText = mKeyframe1->GetText();
	else if (t > 1)
		mText = mKeyframe2->GetText();
}

/** \brief Save this keyframe to an XML node
* \param node The node we are going to be a child of
* \returns Allocated XML node.
*/
std::shared_ptr<xmlnode::CXmlNode> CAnimChannelText::KeyframeText::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CAnimChannel::Keyframe::XmlSave(node);
	itemNode->SetAttribute(L"text", mText);
	itemNode->SetAttribute(L"mirror", mMirror? L"yes":L"no");

	return itemNode;
}



/**
* \brief Handle loading this channel's keyframe type
* \param node keyframe tag node
*/
void CAnimChannelText::XmlLoadKeyframe(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	std::wstring text = node->GetAttributeValue(L"text", wstring(L""));
	bool mirror = node->GetAttributeValue(L"mirror", wstring(L"")) == L"yes";

	// Set a keyframe there
	SetKeyframe(text, mirror);
}


CAnimChannelText::KeyframeText::~KeyframeText()
{

}

