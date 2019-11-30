/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** SystemDlLoader.hpp
*/

#ifndef SYSTEMDLLOADER_HPP__
#define SYSTEMDLLOADER_HPP__

#include <memory>
#include <string>
#include <iostream>
#include <dlfcn.h>
#include "ManagerWrapper.hpp"
#include "ECSExceptions.hpp"

namespace ecs {
    template <typename T>
    class DlLoader {
        private:
        void *_handle = nullptr;

        public:
        DlLoader() = default;
        virtual ~DlLoader() = default;
        /**
         * Load librairie
         * @param pathName
         */
        void loadInstance(const std::string &pathName) {
            std::cout << "lol4s" << std::endl;
            _handle = dlopen(pathName.c_str(), RTLD_LAZY);
            std::cout << "lol" << std::endl;
            if (_handle == NULL)
                throw ECSExceptions(dlerror(), "loadInstance");
        }

        void closeInstance() {
            std::cout << dlclose(_handle) << std::endl;
        }
        /**
         * return the entry point of a shared librarie to get a unique pointer of the class
         * @return
         */
        std::shared_ptr<T> getInstance() const {

//            typedef std::shared_ptr<T> (*entryPoint)();
            typedef T* (*entryPoint)();

            auto entry = (entryPoint) dlsym(_handle, "entryPoint");
//            return entry();
           std::shared_ptr<T> res(entry());
        //    std::make_shared<T>(res);
           return res;
        }

    };
};

#endif // SYSTEMDLLOADER_HPP__