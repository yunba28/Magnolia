#pragma once

#if __has_include(<Siv3D/Types.hpp>)

#include <Siv3D/Types.hpp>

namespace magnolia
{
	using int8 = s3d::int8;
	using int16 = s3d::int16;
	using int32 = s3d::int32;
	using int64 = s3d::int64;

	using uint8 = s3d::uint8;
	using uint16 = s3d::uint16;
	using uint32 = s3d::uint32;
	using uint64 = s3d::uint64;
}

#else

#include <cstdint>
#include <cstddef>

namespace magnolia
{
	using int8 = std::int8_t;
	using int16 = std::int16_t;
	using int32 = std::int32_t;
	using int64 = std::int64_t;

	using uint8 = std::uint8_t;
	using uint16 = std::uint16_t;
	using uint32 = std::uint32_t;
	using uint64 = std::uint64_t;
}

#endif

#include <type_traits>

static_assert(
	sizeof(std::uintptr_t) == sizeof(magnolia::uint64) &&
	std::is_unsigned<std::uintptr_t>::value,
	"error: uintptr_t must be the same standard as uint64.");

#include <typeindex>

namespace magnolia
{
	using TypeIndex = std::type_index;
}

#define UTEXT(Text) U##Text
