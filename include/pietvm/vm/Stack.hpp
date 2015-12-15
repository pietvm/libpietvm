/**
 * @file Stack.hpp
 * @author Joshua Behrens <code@joshua-behrens.de>
 * Stack of a virtual machine instance
 */
#ifndef _PIETVM_VM_STACK_HPP
#define _PIETVM_VM_STACK_HPP

#include <stack>

#include "../Types.hpp"

namespace PietVM
{
	namespace VM
	{
		/**
		 * Stack class for the virtual machine
		 * TODO add maximum number of entries
		 */
		template <typename TInteger, typename = typename std::enable_if<std::is_arithmetic<TInteger>::value, TInteger>::type>
		class Stack
		{
		private:
			/**
			 * Internal number stack
			 */
			std::stack<TInteger> stack;
		public:
			/**
			 * Type of the values stored in the stack
			 */
			typedef TInteger value_type;

			/**
			 * Default constructor
			 */
			Stack() = default;

			/**
			 * Initializes the stack n times with the given value
			 * @param const value_type&  value The value to initializes the stack with
			 * @param const std::size_t& n     The times the value should be added to the stack
			 */
			Stack(const value_type& value, const std::size_t& n)
			{
				Push(value, n);
			}

			/**
			 * The default copy constructor
			 * @param const Stack<TInteger>& copy The instance to copy
			 */
			Stack(const Stack<TInteger>& copy) = default;

			/**
			 * The default move constructor
			 * @param Stack<TInteger>&& move The instance to move
			 */
			Stack(Stack<TInteger>&& move) = default;

			/**
			 * The default copy assignment operator
			 * @param const Stack<TInteger>& copy The instance to copy
			 * @return Stack<TInteger>& this
			 */
			Stack<TInteger>& operator = (const Stack<TInteger>& copy) = default;

			/**
			 * The default move assignment operator
			 * @param Stack<TInteger>&& move The instance to move
			 * @return Stack<TInteger>& this
			 */
			Stack<TInteger>& operator = (Stack<TInteger>&& move) = default;

			/**
			 * Pops the top value of the stack
			 * @return value_type Top value
			 * TODO throw error if no elements are on the stack
			 */
			value_type Pop()
			{
				return stack.pop();
			}

			/**
			 * Returns the top value of the stack
			 * @return value_type Top value
			 * TODO throw error if no elements are on the stack
			 */
			value_type Peek() const
			{
				return stack.top();
			}

			/**
			 * Adds the given value on top of the stack
			 * @param const value_type& value The value to add
			 */
			void Push(const value_type& value)
			{
				stack.push(value);
			}

			/**
			 * Adds the give value n times on top of the stack
			 * @param const value_type&  value The value to add
			 * @param const std::size_t& n     The times the value should be added to the stack
			 */
			void Push(const value_type& value, std::size_t n)
			{
				while (n --> 0)
				{
					stack.push(value);
				}
			}

			/**
			 * Returns the amount of elements on the stack
			 * @return std::size_t Amount of elements on the stack
			 */
			std::size_t size() const
			{
				return stack.size();
			}
		}; // Stack<TInteger>

		/**
		 * Stack of signed 32 bit integers
		 */
		typedef Stack<PietVM::S32> StackS32;

		/**
		 * Stack of signed 16 bit integers
		 */
		typedef Stack<PietVM::S16> StackS16;

		/**
		 * Stack of signed 8 bit integers
		 */
		typedef Stack<PietVM::S8> StackS8;
	} // VM
} // PietVM

#endif // _PIETVM_VM_STACK_HPP