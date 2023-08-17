#pragma once

#include <Magnolia/CoreMinimal.hpp>
#include <Magnolia/Core/Reference.hpp>

namespace magnolia
{
	class Object
	{
	public:

		Object() = default;

		virtual ~Object() = 0;

		uint64 instanceID() const noexcept
		{
			return reinterpret_cast<uint64>(this);
		}

		friend bool operator==(const Object& _left, const Object& _right) noexcept
		{
			return _left.instanceID() == _right.instanceID();
		}

		friend bool operator!=(const Object& _left, const Object& _right) noexcept
		{
			return _left.instanceID() != _right.instanceID();
		}

	};
	DECLARE_CLASS(Object);

	inline Object::~Object() {}
}
