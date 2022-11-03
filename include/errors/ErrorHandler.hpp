/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Error handler
*/

#pragma once

#include <stdexcept>

#include "IndieStudio.hpp"

class ids::ErrorHandler : public std::exception {
    public:
        ErrorHandler(std::string const &message) : _message(message) {};

        const char *what() const noexcept
            { return _message.data(); };

    private:
        std::string _message;
};
