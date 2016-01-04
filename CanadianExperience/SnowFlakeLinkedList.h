/**
 * \file SnowFlakeLinkedList.h
 *
 * \author Siyan Ma
 *
 * \brief A linked list class that creates snow flake linked list
 */

#pragma once
#include "SnowFlake.h"

/**
 * \brief A linked list class that creates snow flake linked list
 */
class CSnowFlakeLinkedList
{
public:
	CSnowFlakeLinkedList();
	virtual ~CSnowFlakeLinkedList();

	/** \brief Copy constructor disabled */
	CSnowFlakeLinkedList(const CSnowFlakeLinkedList &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CSnowFlakeLinkedList &) = delete;

	/** \brief Iterator that iterates over the linked list */
	class Iter
	{
	public:
		/** \brief Constructor
		* \param pos*/
		Iter(std::shared_ptr<CSnowFlake> pos) : mPos(pos) {}

		/** \brief Test for end of the iterator
		* \param iter
		* \returns True if we this position equals not equal to the iter position */
		bool operator!= (const Iter &iter) const { return mPos != iter.mPos; }

		/** \brief Get current position
		* \returns pos at current position */
		std::shared_ptr<CSnowFlake>  operator* () const { return mPos; }

		/** \brief Increment the iterator
		* \returns Reference to this iterator */
		const Iter& operator++ ()
		{
			mPos = mPos->GetNext();
			return *this;
		}

	private:
		std::shared_ptr<CSnowFlake> mPos;	///< Current position in linked list
	};

	/** \brief Get an iterator for the beginning of the linked list
	* \returns Iter object at beginning */
	Iter begin() const { return Iter(mBegin); }

	/** \brief Get an iterator for the end of the collection
	* \returns Iter object at nullptr for the end */
	Iter end() const { return Iter(nullptr); }

	void PushBack(std::shared_ptr<CSnowFlake> snowflake);
	void Remove(std::shared_ptr<CSnowFlake> snowflake);

	/** \brief Get the first snowflake for this linked list
	* \returns Pointer to begin snowflake */
	std::shared_ptr<CSnowFlake> GetBegin() { return mBegin; }

	/** \brief Get the last snowflake for this linked list
	* \returns Pointer to end snowflake */
	std::shared_ptr<CSnowFlake> GetEnd() { return mEnd; }

private:
	/// The first snowflake in list
	std::shared_ptr<CSnowFlake> mBegin;
	/// The last snowflake in list
	std::shared_ptr<CSnowFlake> mEnd;
};

