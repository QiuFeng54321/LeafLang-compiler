/*
 * Copyright (C) 2019 Qiufeng54321
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   Exceptions.hpp
 * Author: Qiufeng54321
 *
 * Created on 2019年4月21日, 上午11:06
 */

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

namespace Erable {
    namespace Exceptions {

        class Exception : std::runtime_error {
        public:

            explicit Exception(const std::string &title, const std::string& s) : std::runtime_error(title + ":" + s) {
            };
        };

        class UnsupportedOpException : Exception {
        public:

            explicit UnsupportedOpException(const std::string& s) : Exception("Unsupported Operation", s) {
            };
        };

        class IOException : Exception {
        public:

            explicit IOException(const std::string& s) : Exception("IO Exception", s) {
            };
        };
        class ValidateException : Exception {
        public:

            explicit ValidateException(const std::string& s) : Exception("Validate Exception", s) {
            };
        };
    }
}

#endif /* EXCEPTIONS_HPP */

