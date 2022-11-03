/*
** EPITECH PROJECT, 2022
** indie_studio
** File description:
** Ground
*/

#ifndef GROUND_HPP_
#define GROUND_HPP_

#include "IndieStudio.hpp"

#include "AStaticObject.hpp"
#include <vector>


class ids::Ground : public AStaticObject {
	public:
		Ground(std::vector<float> pos);
		~Ground();
		std::string const getType() const;
	protected:
	private:
};

#endif /* !GROUND_HPP_ */
