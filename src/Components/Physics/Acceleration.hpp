/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** Acceleration.hpp
*/

#ifndef ACCELERATION_HPP
#define ACCELERATION_HPP

#include "Motion.hpp"

namespace ecs {
	namespace components
	{
		/**
		 * @brief Acceleration describes the Acceleration of an Entity
		 *
		 */
		class Acceleration : public Motion
		{
		private:
			float _value;
		public:
			Acceleration();
			Acceleration(const Acceleration &oldAcceleration);
			~Acceleration();
			bool operator==(Acceleration const&) const;


			/**
			 * @brief Set the Value object
			 *
			 */
			void setValue(const float&);

			/**
			 * @brief Get the Value object
			 *
			 * @return float
			 */
			float getValue()const;
			/**
			 * @brief Get the Type object
			 *
			 * @return const std::type_index
			 */
			const std::type_index getType() const override;
		};
	}
}
#endif