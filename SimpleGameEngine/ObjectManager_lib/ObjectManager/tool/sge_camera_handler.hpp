//
//  sge_camera_handler.hpp
//  SimpleGameEngine
//
//  Created by Janusz Majchrzak on 11/04/16.
//  Copyright © 2016 Hamashy. All rights reserved.
//

#ifndef sge_camera_handler_h
#define sge_camera_handler_h

#include "sge_object.hpp"
#include <glm/glm.hpp>

namespace SGE {

    class Camera2d;

    class CameraHandler {
        Camera2d *camera = nullptr;
        ObjectManager *manager = nullptr;
        int x = 0, y = 0;
        double scale = .0f;

    public:
        CameraHandler(std::pair<int, int>, ObjectManager *) noexcept;

        Camera2d *getCamera();

        void setScale(double) noexcept;

        void setPosition(int, int) noexcept;

        void setPosition(glm::vec2) noexcept;

        void updateCamera(void) const noexcept;

        const glm::mat4 &getCameraMatrix(void) const noexcept;

        glm::vec2 getScreenToWorld(glm::vec2) const noexcept;

        glm::vec2 getScreenToWorld(int, int) const noexcept;

    };

}

#endif /* sge_camera_handler_h */
