#include "Client.h"


Client::Client() : num(0), nom("NOM"), rue("RUE") {}

Client::~Client() {};

string Client::getNom() { return this->nom; }