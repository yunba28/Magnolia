#pragma once

#include <Magnolia/CoreMinimal.hpp>

namespace magnolia
{
	struct ClassPackage
	{
		template<class T>
		ClassPackage(std::type_identity<T>)
			: typeIndex(typeid(T))
			, size(sizeof(T))
		{

		}

		const TypeIndex typeIndex;

		const size_t size;

	};

	struct Reference
	{
		static void AddRegister(const char32_t* _className, ClassPackage _classPackage);

		static ClassPackage FindReference(const char32_t* _className);
	};
}

#define DECLARE_CLASS(Class)\
namespace backend\
{\
	struct Reference_##Class\
	{\
		Reference_##Class()\
		{\
			magnolia::Reference::AddRegister(UTEXT(#Class), magnolia::ClassPackage{std::type_identity<Class>{}});\
		}\
	};\
	inline Reference_##Class Class##Reference{};\
}
