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

namespace SGE {
    
    namespace Logics{
        
        class BasicColliderGroup : public Collide {
            std::vector<ObjectID> objs;
            
        public:

	        BasicColliderGroup(std::vector<ObjectID> objects, collisionFunc _onCollision);

	        void performLogic(ObjectID _obj);
        };
        
    }
}

#endif /* sge_logic_collide_group_h */
