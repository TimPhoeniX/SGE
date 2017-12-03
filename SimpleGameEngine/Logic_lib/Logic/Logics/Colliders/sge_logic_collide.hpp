//
//  sge_logic_collide.hpp
//  SimpleGameEngine
//
//  Created by Janusz Majchrzak on 15/04/16.
//  Copyright © 2016 Hamashy. All rights reserved.
//

#ifndef sge_logic_collide_h
#define sge_logic_collide_h

#include "sge_logic.hpp"
#include <functional>

namespace SGE {
    class Object;
    class ObjectID;
    
    namespace Logics{
        
	    /**
         * \brief 
         */
        class Collide : public Logic{
        public:
	        /**
             * \brief 
             */
            using collisionFunc = std::function<Action*(Object*, Object*)>;

	        /**
	         * \brief 
	         * \param still 
	         * \param toMove 
	         * \return 
	         */
	        static Action* RectangleCollisionVec(Object* still, Object* toMove);

	        /**
	         * \brief 
	         * \param still 
	         * \param toMove 
	         * \return 
	         */
	        static Action* CircleCollisionVec(Object* still, Object* toMove);

	        /**
	         * \brief 
	         * \param still 
	         * \param toMove 
	         * \return 
	         */
	        static Action* CircleToRectCollisionVec(Object* still, Object* toMove);

        protected:

	        /**
	         * \brief 
	         * \param self 
	         * \param oponent 
	         * \return 
	         */
	        virtual bool collideWithSameShape(Object* self, Object* oponent);

	        /**
	         * \brief 
	         * \param self 
	         * \param oponent 
	         * \return 
	         */
	        virtual bool collideWithDifferentShape(Object* self, Object* oponent);

	        /**
	         * \brief 
	         * \param self 
	         * \param oponent 
	         * \return 
	         */
	        virtual bool collideWithEdgesDifferentShape(Object* self, Object* oponent);

	        /**
             * \brief 
             */
            collisionFunc onCollision;

	        /**
	         * \brief 
	         * \param e 
	         */
	        Collide(collisionFunc e);
        };
        
    }
}

#endif /* sge_logic_collide_h */
