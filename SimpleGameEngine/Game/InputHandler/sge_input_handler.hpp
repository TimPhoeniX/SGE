//
//  sge_input_handler.hpp
//  SimpleGameEngine
//
//  Created by Janusz Majchrzak on 11/04/16.
//  Copyright © 2016 Hamashy. All rights reserved.
//

#ifndef sge_input_handler_h
#define sge_input_handler_h

#include <unordered_map>
#include <glm/glm.hpp>

#include "../../IO/Key/sge_key.hpp"
#include "../ActionHandler/sge_action_handler.hpp"
#include "../../Action/sge_action.hpp"

namespace SGE
{
    class Game;
    class InputManager;
    class MouseObject;
    class InputBinder;

	/**
     * \brief 
     */
    class InputHandler {
	    /**
         * \brief 
         */
        Game* game = nullptr;
	    /**
         * \brief 
         */
        InputManager* input_manager = nullptr;
	    /**
         * \brief 
         */
        std::unordered_map <Key, Action*, KeyHashAlias<Key>> keyMap;

	    /**
         * \brief 
         * \param k 
         */
        void pressKey(Key k);

    public:
	    /**
         * \brief 
         */
        explicit InputHandler(Game* game) noexcept;

	    /**
         * \brief 
         */
        void pollEvents() noexcept;

	    /**
         * \brief 
         * \param bind 
         */
        void mapAction(const InputBinder& bind);

	    /**
         * \brief 
         * \param bind 
         */
        void unmapAction(const InputBinder& bind);

	    void clear()
	    {
		    for(auto bind : this->keyMap)
		    {
				delete bind.second;
		    }
			this->keyMap.clear();
	    }

	    /**
         * \brief 
         * \todo Move it?
         */
        class MouseHandler
        {
	        /**
             * \brief 
             */
            MouseObject* mouse = nullptr;

        public:
	        /**
             * \brief 
             */
            MouseHandler() noexcept;

	        /**
             * \brief 
             * \param coords 
             */
            void setMouseCoords(glm::vec2 coords) noexcept;

	        /**
             * \brief 
             * \return 
             */
            glm::vec2 getMouseCoords() const noexcept;

	        /**
             * \brief 
             * \return 
             */
            MouseObject *getMouseObject() noexcept;
        };

    private:
	    /**
         * \brief 
         */
        MouseHandler *mouseHandler = nullptr;
    public:
	    /**
         * \brief 
         * \return 
         */
        MouseHandler *getMouseHandler() noexcept;
    };

}

#endif /* sge_input_handler_h */
