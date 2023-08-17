#include <Magnolia/Core/Reference.hpp>

#include <Siv3D.hpp>

namespace magnolia::backend
{
	static HashTable<String, ClassPackage> TypeReferences{};
}

namespace magnolia
{
	void Reference::AddRegister(const char32_t* _className, ClassPackage _classPackage)
	{
		auto [element, result] = backend::TypeReferences.try_emplace(String{ _className }, _classPackage);
		assert(result);
	}

	ClassPackage Reference::FindReference(const char32_t* _className)
	{
		auto found = backend::TypeReferences.find(String{ _className });
		if (found != backend::TypeReferences.end())
		{
			return found->second;
		}
		return ClassPackage{ std::type_identity<void*>{} };
	}
}
