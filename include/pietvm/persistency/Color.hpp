/**
 * @file Color.hpp
 * @author Joshua Behrens <code@joshua-behrens.de>
 * Immutable color structure hold the values red, blue and green
 */
#ifndef _PIETVM_PERSISTENCY_COLOR_HPP
#define _PIETVM_PERSISTENCY_COLOR_HPP

#include "../Types.hpp"

namespace PietVM
{
	namespace Persistency
	{
		/**
		 * Color container for RGB values
		 */
		class Color
		{
		private:
			/**
			 * The red byte
			 */
			U8 r;

			/**
			 * The green byte
			 */
			U8 g;

			/**
			 * The blue byte
			 */
			U8 b;
		public:
			/**
			 * Default constructor
			 */
			Color() = default;

			/**
			 * Constructor using RGB values
			 * @param const PietVM::U8& red   The red value of the color
			 * @param const PietVM::U8& green The green value of the color
			 * @param const PietVM::U8& blue  The blue value of the color
			 */
			Color(const U8& red, const U8& green, const U8& blue);

			/**
			 * Default copy constructor
			 * @param const Color& copy The instance to copy
			 */
			Color(const Color& copy) = default;

			/**
			 * Default move constructor
			 * @param Color&& move The instance to move
			 */
			Color(Color&& move) = default;

			/**
			 * Default copy assignment operator
			 * @param const Color& copy The instance to copy
			 * @return Color& this
			 */
			Color& operator = (const Color& copy) = default;

			/**
			 * Default move assignment operator
			 * @param Color&& move The instance to move
			 * @return Color& this
			 */
			Color& operator = (Color&& move) = default;

			/**
			 * Equality comparison operator
			 * @param const Color& rhs
			 * @return bool True, if this' RGB values and the given Color's RGB values are equal, otherwise false
			 */
			bool operator == (const Color& rhs) const;

			/**
			 * Non-equality comparison operator
			 * @param const Color& rhs
			 * @return bool True, if one pair of this' RGB values and the given Color's RGB values are not equal, otherwise false
			 */
			bool operator != (const Color& rhs) const;

			/**
			 * Returns the red value of the color
			 * @return PietVM::U8 The red value of the color
			 */
			U8 GetRed() const;

			/**
			 * Returns the green value of the color
			 * @return PietVM::U8 The green value of the color
			 */
			U8 GetGreen() const;

			/**
			 * Returns the blue value of the color
			 * @return PietVM::U8 The blue value of the color
			 */
			U8 GetBlue() const;
		}; // Color
	} // Persistency
} // PietVM

#endif // _PIETVM_PERSISTENCY_COLOR_HPP