#include "sge_logic_collide_level.hpp"
#include "sge_shape_rectangle.hpp"
#include "sge_object_bind.hpp"

SGE::Logics::BasicLevelCollider::BasicLevelCollider(std::vector<WorldElement>& objects, const collisionFunc& _onCollision)
		: Collide(LogicPriority::Highest), onCollision(_onCollision), objs(objects)
{
}

void SGE::Logics::BasicLevelCollider::performLogic(const ObjectBind& _obj)
{
	Object* oponent = _obj[0];
	Shape* selfShape = getBaseTileShape();
	Shape* oponentShape = oponent->getShape();

	bool collision = false;

	for (unsigned int i = 0; i < this->objs.size(); ++i)
	{
		if (selfShape->getType() == oponentShape->getType())
			collision = this->collideWithSameShape(&objs[i], oponent);
		else
			collision = this->collideWithDifferentShape(&objs[i], oponent);

		if (collision)
		{
			Action* aid = this->onCollision(&objs[i], _obj[0]);
			this->sendAction(_obj[0], aid);
		}
	}
}
