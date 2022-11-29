#include "./iterator_factory.h"
#include<map>

std::map<std::string, IteratorFactory*> _registry;

IteratorFactory* IteratorFactory::getInstance(std::string name) {
    return _registry[name];
}

void IteratorFactory::_register(std::string name, IteratorFactory* factory) {
    _registry[name] = factory;
}
