#include "pietvm/persistency/ColorPalette.hpp"

PietVM::Persistency::ColorPalette::iterator PietVM::Persistency::ColorPalette::begin() const
{
	return colorIndex.begin();
}

PietVM::Persistency::ColorPalette::iterator PietVM::Persistency::ColorPalette::end() const
{
	return colorIndex.end();
}

std::size_t PietVM::Persistency::ColorPalette::size() const
{
	return colorIndex.size();
}

void PietVM::Persistency::ColorPalette::clear()
{
	colorIndex.clear();
	nextIndex = 0;
}

PietVM::Persistency::ColorPalette::ColorList PietVM::Persistency::ColorPalette::GetColors() const
{
	PietVM::Persistency::ColorPalette::ColorList result;

	for (auto&& indexColorPair : colorIndex)
	{
		result.push_back(indexColorPair.second);
	}

	return result;
}

bool PietVM::Persistency::ColorPalette::TryAdd(const PietVM::Persistency::Color& color, PietVM::U32& assignedIndex)
{
	if (Contains(color))
	{
		assignedIndex = IndexOf(color);
		return false;
	}

	assignedIndex = Add(color);

	return true;
}

PietVM::U32 PietVM::Persistency::ColorPalette::Add(const PietVM::Persistency::Color& color)
{
	PietVM::U32 result = ++nextIndex;
	colorIndex.emplace(std::make_pair(result, color));
	return result;
}

bool PietVM::Persistency::ColorPalette::Contains(const PietVM::Persistency::Color& color) const
{
	for (auto&& indexColorPair : colorIndex)
	{
		if (indexColorPair.second == color)
		{
			return true;
		}
	}

	return false;
}

PietVM::U32 PietVM::Persistency::ColorPalette::IndexOf(const PietVM::Persistency::Color& color) const
{
	for (auto&& indexColorPair : colorIndex)
	{
		if (indexColorPair.second == color)
		{
			return indexColorPair.first;
		}
	}
}