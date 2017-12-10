#include "sge_logic.hpp"
#include "sge_object.hpp"
#include "sge_action_handler.hpp"
#include "sge_action_bind.hpp"

SGE::Logic::~Logic() {}


SGE::ActionHandler* SGE::Logic::action_handler = nullptr;

SGE::Logic::Logic(Priority _p): priority(_p)
{
}

void SGE::Logic::sendAction(Object* obj, Action* action) const
{
	action_handler->performSingleAction(ActionBind(obj, action), this->priority);
}

SGE::Logic::Priority SGE::Logic::getPriority() const
{
	return this->priority;
}

void SGE::Logic::setOn(bool e)
{
	this->isOn = e;
}

bool SGE::Logic::getOn()
{
	return this->isOn;
}

void SGE::Logic::toggleOn()
{
	this->isOn = !this->isOn;
}
