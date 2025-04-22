#include "Serializer.hpp"

Serializer::Serializer(){};
Serializer::Serializer(const Serializer& copy){(void)copy;}
Serializer& Serializer::operator=(const Serializer& other){return *this; (void)other;}
Serializer::~Serializer(){}

/*
uintptr_t est un alias (<cstdint>) pour un entier non signé qui a la taille nécessaire 
pour stocker une adresse.
serialize: reinterpret_cast permet de “lire les bits” du pointeur comme un entier.
deserialize : fait l'inverse
*/

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
