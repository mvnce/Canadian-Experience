/**
 * \file AnimChannelText.h
 *
 * \author Siyan Ma
 *
 * \brief Animation channel for text
 */

#pragma once
#include "AnimChannel.h"

/**
* \brief Animation channel for text
*/
class CAnimChannelText :
	public CAnimChannel
{
public:
	CAnimChannelText();
	virtual ~CAnimChannelText();

	/** \brief Get the current text
	* \return text */
	std::wstring GetText() { return mText; }

	/** \brief Get the current mirror
	* \return mirror */
	bool GetMirror() { return mMirror; }

	/// \brief A keyframe for an text channel
	class KeyframeText : public Keyframe
	{
	public:
		/** \brief Constructor
		* \param channel The channel we are for
		* \param text The text for the keyframe
		* \param mirror The mirror for the keyframe */
		KeyframeText(CAnimChannelText *channel, std::wstring text, bool mirror) :
			Keyframe(channel), mChannel(channel), mText(text), mMirror(mirror) {}

		/** \brief Destructor */
		~KeyframeText();

		/** \brief Default constructor disabled */
		KeyframeText() = delete;
		/** \brief Copy constructor disabled */
		KeyframeText(const KeyframeText &) = delete;
		/** \brief Assignment operator disabled */
		void operator=(const KeyframeText &) = delete;

		/** \brief Get the text at this keyframe
		* \returns text in wstring */
		std::wstring GetText() { return mText; }
		
		/** \brief Get the text at this keyframe
		* \returns text in wstring */
		bool GetMirror() { return mMirror; }

		/** \brief Use this keyframe as keyframe 1 */
		virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

		/** \brief Use this keyframe as keyfraem 2 */
		virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

		/** \brief Use this keyframe as the text and mirror*/
		virtual void UseOnly() override
		{ 
			mChannel->mText = mText; 
			mChannel->mMirror = mMirror;
		}

		virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node);


	private:
		std::wstring mText;  ///< The text for this keyframe
		bool mMirror;  ///< The mirror status for this keyframe

		/// The channel this keyframe is associated with
		CAnimChannelText *mChannel;
	};

	void SetKeyframe(std::wstring text, bool mirror);
	void Tween(double t);

protected:
	virtual void XmlLoadKeyframe(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

private:
	/// The text in text bubble
	std::wstring mText = L"";

	/// The mirror for the text bubble
	bool mMirror = false;

	/// The first text keyframe
	KeyframeText *mKeyframe1 = nullptr;

	/// The second text keyframe
	KeyframeText *mKeyframe2 = nullptr;
};

