/**
 * @file ColorPalette.hpp
 * @author Joshua Behrens <code@joshua-behrens.de>
 * Helper-class for indexing colors
 */
#ifndef _PIETVM_PERSISTENCY_COLORPALETTE_HPP
#define _PIETVM_PERSISTENCY_COLORPALETTE_HPP

#include <map>
#include <list>

#include "Color.hpp"

namespace PietVM
{
	namespace Persistency
	{
		/**
		 * Helper class for indexing colors
		 */
		class ColorPalette
		{
		private:
			/**
			 * Map with all colors
			 */
			std::map<U32, Color> colorIndex;

			/**
			 * Index counter
			 */
			U32 nextIndex;
		public:
			/**
			 * Iterator type is always const to prohibit changes
			 */
			typedef std::map<U32, Color>::const_iterator iterator;

			/**
			 * Iterator access to the start of the index list
			 * @return iterator Iterator to the start
			 */
			iterator begin() const;

			/**
			 * Iterator access to the end of the index list
			 * @return iterator Iterator to the end
			 */
			iterator end() const;

			/**
             * Returns the amount of indexed elements
             * @return std::size_t Amount of indexed elements
			 */
			std::size_t size() const;

			/**
			 * Clears the list of indexed elements and resets the index counter
			 */
			void clear();

			/**
			 * List type for the color only functions
			 */
			typedef std::list<Color> ColorList;

			/**
			 * Returns all indexed colors without their indices
			 * @return ColorList All indexed colors
			 */
			ColorList GetColors() const;

			/**
			 * Tries to add the color and assigns the given index to param2. If color is already indexed the given indexed is of the already existing element
			 * @param const Color& color         The color to add
			 * @param PietVM::U32& assignedIndex The index that was assigned to the color
			 * @return True if the color was not indexed before, otherwise false
			 */
			bool TryAdd(const Color& color, U32& assignedIndex);

			/**
			 * Adds a color to the index and returns the given index
			 * Throws exception if color already exists
			 * @param const Color& color The color to add
			 * @return PietVM::U32 The new assigned index
			 * TODO throw error if entry already exists
			 */
			U32 Add(const Color& color);

			/**
			 * Checks whether a given color is already indexed
			 * @param const Color& color The color to check
			 * @return bool True if the given color is already indexed, otherwise false
			 */
			bool Contains(const Color& color) const;

			/**
			 * Returns the given index of the color in question.
			 * Throws error if color is not indexed
			 * @param const Color& color The color to check
			 * @return PietVM::U32 The given index of the color
			 * TODO throw error if no index if assigned to the color
			 */
			U32 IndexOf(const Color& color) const;
		}; // ColorPalette
	} // Persistency
} // PietVM

#endif // _PIETVM_PERSISTENCY_COLORPALETTE_HPP