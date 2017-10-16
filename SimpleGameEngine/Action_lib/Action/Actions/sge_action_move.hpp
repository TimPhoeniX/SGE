//
//  sge_action_move.hpp
//  SimpleGameEngine
//
//  Created by Janusz Majchrzak on 06/04/16.
//  Copyright © 2016 Hamashy. All rights reserved.
//

#ifndef sge_action_move_h
#define sge_action_move_h

#include "sge_action.hpp"

namespace SGE {
    namespace ACTION {
        class Move : virtual public Action {
        
            float destX, destY;
            
        public:

	        Move(float _x, float _y, double _duration);

        private:

	        virtual void action_begin(const ObjectBind&) noexcept override;

	        virtual void action_main(const ObjectBind& bind) noexcept override;

	        virtual void action_ends(const ObjectBind&) noexcept override;
        };
    }
}

#endif /* sge_action_move_h */
