#ifndef INTERFACES_H
#define INTERFACES_H

#pragma once

namespace Interface
{

	/* Interface to make a class non-copyable */
	class INonCopyable
	{
	
	protected:
		INonCopyable()
		{ }

		~INonCopyable()
		{ }

	private:
		INonCopyable(const INonCopyable& other) = delete;
		const INonCopyable& operator= (const INonCopyable& other) = delete;
	};

	class IManager
	{
	public:
		virtual void StartUp()	= 0;
		virtual void ShutDown() = 0;

	};


}



#endif