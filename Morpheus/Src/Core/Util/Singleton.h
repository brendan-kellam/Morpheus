#ifndef SINGLETON_H
#define SINGLETON_H

#pragma 

#include "Engine.h"

#include "Core/Util/Interfaces.h"

template <typename T>
class CSingleton : Interface::INonCopyable
{

public:
	static T& Instance()
	{
		static T instance;
		return instance;
	}

protected:

	explicit CSingleton<T>() { }

};



//template <typename T>
//class CSingleton
//{
//public:
//	
//	static T& Instance()
//	{
//		if (CSingleton::ms_instance == nullptr)
//		{
//			CSingleton::ms_instance = CreateInstance();
//		}
//		return *(CSingleton::ms_instance);
//	}
//
//	inline static void Destroy()
//	{
//
//	}
//
//protected:
//
//	inline ~CSingleton()
//	{
//		if (CSingleton::ms_instance != nullptr)
//		{
//			delete CSingleton::ms_instance;
//		}
//		CSingleton::ms_instance = nullptr;
//	}
//
//	inline explicit CSingleton()
//	{
//		MORPH_TRAP(CSingleton::ms_instance == nullptr);
//		CSingleton::ms_instance = static_cast<T*>(this);
//	}
//
//private:
//	static T* ms_instance;
//	
//	inline static T* CreateInstance()
//	{
//		return new T();
//	}
//
//	inline static void DestroyInstance(T* p)
//	{
//		delete p;
//	}
//
//
//	inline explicit CSingleton(CSingleton const &) {}
//
//	inline CSingleton& operator=(CSingleton const &) {
//		return *this;
//	}
//};



#endif /* SINGLETON_H */