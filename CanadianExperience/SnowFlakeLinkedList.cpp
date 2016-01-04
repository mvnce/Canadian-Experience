/**
 * \file SnowFlakeLinkedList.cpp
 *
 * \author Siyan Ma
 */

#include "stdafx.h"
#include "SnowFlakeLinkedList.h"

using namespace std;

/** 
 * \brief Constructor
 */
CSnowFlakeLinkedList::CSnowFlakeLinkedList()
{
}


/** 
 * \brief Destructor
 */
CSnowFlakeLinkedList::~CSnowFlakeLinkedList()
{
}


/** 
 * \brief Add a snowflake to the end of the linked list
 * \param snowflake The snowflake to add
 */
void CSnowFlakeLinkedList::PushBack(std::shared_ptr<CSnowFlake> snowflake)
{
	if (mEnd == nullptr)
	{
		// Empty list
		mBegin = snowflake;
		mEnd = snowflake;
	}
	else
	{
		mEnd->SetNext(snowflake);
		mEnd = snowflake;
	}
}


/**
* \brief Remove a snowflake from the linked list
* \param snowflake The snowflake to remove
*/
void CSnowFlakeLinkedList::Remove(std::shared_ptr<CSnowFlake> snowflake)
{
	shared_ptr<CSnowFlake> prev = nullptr;
	auto node = mBegin;
	while (node != nullptr)
	{
		auto nextNode = node->GetNext();

		if (node == snowflake)
		{
			if (prev == nullptr)
			{
				// This is the first node in the list. It has no previous node
				mBegin = nextNode;
			}
			else
			{
				prev->SetNext(nextNode);
			}

			snowflake->SetNext(nullptr);
			break;
		}
		else
		{
			// Previous node only changes if we do not delete
			prev = node;
		}

		node = nextNode;
	}

	if (mBegin == nullptr)
	{
		mEnd = nullptr;
	}

	if (mEnd == nullptr)
	{
		mBegin = nullptr;
	}
}

