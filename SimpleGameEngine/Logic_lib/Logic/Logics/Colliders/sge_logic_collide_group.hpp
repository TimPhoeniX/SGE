//
//  sge_logic_collide_group.hpp
//  SimpleGameEngine
//
//  Created by Janusz Majchrzak on 01/05/16.
//  Copyright © 2016 Hamashy. All rights reserved.
//

#ifndef sge_logic_collide_group_h
#define sge_logic_collide_group_h

#include "sge_logic_collide.hpp"
#include <vector>

namespace SGE
{
	class Object;
	class Action;

    namespace Logics
	{
	    /**
         * \brief 
         */
        class BasicColliderGroup : public Collide
		{
		public:
			/**
			 * \brief
			 */
			using collisionFunc = std::function<Action*(Object*, Object*)>;

		private:
	        /**
             * \brief 
             */
			collisionFunc onCollision;

            std::vector<Object*> objs;

        public:

	        /**
	         * \brief 
	         * \param objects 
	         * \param _onCollision 
	         */
	        BasicColliderGroup(std::vector<Object*> objects, const collisionFunc& _onCollision);

	        /**
	         * \brief 
	         * \param _obj 
	         */
	        void performLogic(Object* _obj);
        };
        
    }
}

#endif /* sge_logic_collide_group_h */
