
#include "../Scene/Scene.h"
#include "../Camera/Camera.h"
#include "../../Game/BackgroundShader/BackgroundShader.h"

#ifndef PJC_PROJECT_RENDERER_H
#define PJC_PROJECT_RENDERER_H

class Renderer {
private:
    Context* context;
    BackgroundShader shader{};
    SplashShader splashShader{};
public:
    explicit Renderer(Context& ctx);

    auto render(Scene& scene, Camera& camera) -> void;
};


#endif //PJC_PROJECT_RENDERER_H
