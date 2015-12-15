#include "pietvm/persistency/Color.hpp"

PietVM::Persistency::Color::Color(const PietVM::U8& red, const PietVM::U8& green, const PietVM::U8& blue)
	: r(red), g(green), b(blue)
{
}

bool PietVM::Persistency::Color::operator == (const PietVM::Persistency::Color& rhs) const
{
	return r == rhs.r && g == rhs.g && b == rhs.b;
}

bool PietVM::Persistency::Color::operator != (const PietVM::Persistency::Color& rhs) const
{
	return r != rhs.r || g != rhs.g || b != rhs.b;
}

PietVM::U8 PietVM::Persistency::Color::GetRed() const
{
	return r;
}

PietVM::U8 PietVM::Persistency::Color::GetGreen() const
{
	return g;
}

PietVM::U8 PietVM::Persistency::Color::GetBlue() const
{
	return b;
}