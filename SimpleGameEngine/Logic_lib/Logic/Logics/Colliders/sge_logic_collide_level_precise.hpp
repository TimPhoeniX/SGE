#ifndef sge_logic_collide_level_precise_h
#define sge_logic_collide_level_precise_h

#include "sge_logic_collide.hpp"

namespace SGE {

	namespace Logics {

		class PreciseLevelCollider : public Collide {
			std::vector<WorldElement>& objs;
		protected:
			;;

		public:
			PreciseLevelCollider(std::vector<WorldElement>& objects) : Collide(nullptr), objs(objects) {}

			void performLogic(const ObjectBind& _obj) override
			{
				Object* oponent = _obj[0].getObject();
				glm::vec2 tileShape = { getBaseTileShape()->getWidth(), getBaseTileShape()->getHeight() };
				glm::vec2 move = { 0,0 };
				glm::vec2 tilePos = { 0,0 };
				glm::vec2 objPos = oponent->getPosition();
				bool collided = false;
				switch (oponent->getShape()->getType())
				{
					case ShapeType::Circle:
					{
						Circle* circle = reinterpret_cast<Circle*>(oponent->getShape());
						for (auto& tile : this->objs)
						{
							glm::vec2 halfs = tileShape*0.5f;
							tilePos = tile.getPosition();
							if (std::abs(objPos.x - tilePos.x) < circle->getRadius() + halfs.x
								&& std::abs(objPos.y - tilePos.y) < circle->getRadius() + halfs.y)
							{
								glm::vec2 difference = objPos - tilePos;
								glm::vec2 clamps = glm::clamp(difference, -halfs, halfs);
								glm::vec2 collisionPoint = tilePos + clamps;
								difference = objPos - collisionPoint;
								const float l = glm::length(difference);
								if (l < circle->getRadius())
								{
									collided = true;;
									difference *= ((circle->getRadius() - l) / l);
									if (move.x == 0.f && move.y == 0.f)
									{
										move = difference;
									}
									else if (move.x*difference.x == 0)
									{
										if (move.y*difference.y == 0)
										{
											move += difference;
										}
										else
										{
											move.x = 0;
											move.y = (std::signbit(move.y) ? -1.f : 1.f)*std::max(std::abs(move.y), std::abs(difference.y));
										}
									}
									else if (move.y*difference.y == 0)
									{
										if (move.x*difference.x == 0)
										{
											move += difference;
										}
										else
										{
											move.y = 0;
											move.x = (std::signbit(move.x) ? -1.f : 1.f)*std::max(std::abs(move.x), std::abs(difference.x));
										}
									}
									else
									{
										//TODO prevent circle from entering spot too tight
									}
								}
							}
						}
						if (collided)
						{
							this->sendAction(_obj[0], Action::ID(new ACTION::Move(move.x, move.y, 0.)));
						}
					}break;
					case ShapeType::Rectangle:
					{
						Rectangle* rect = reinterpret_cast<Rectangle*>(oponent->getShape());
						for (auto& tile : this->objs)
						{
							//TODO
						}
					}break;
					case ShapeType::None: return;
				}
			}
		};

	}
}

#endif /* sge_logic_collide_level_precise_h */
