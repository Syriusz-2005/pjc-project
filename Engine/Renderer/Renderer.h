
#include "../Scene/Scene.h"
#include "../Camera/Camera.h"

#ifndef PJC_PROJECT_RENDERER_H
#define PJC_PROJECT_RENDERER_H

class Renderer {
private:
    Scene* scene;
    Camera* camera;
    Context* context;
public:
    explicit Renderer(Scene& scene, Camera& camera, Context& ctx);

    auto render() -> void;
};


#endif //PJC_PROJECT_RENDERER_H
