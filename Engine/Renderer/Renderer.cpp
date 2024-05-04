#include "Renderer.h"

Renderer::Renderer(Context &ctx) : context(&ctx) {

}

auto Renderer::render(Scene& scene, Camera& camera) -> void {
    auto cameraPos = camera.getPos();
    context->globalPos = -cameraPos;
    context->backgroundShader = &shader;
    context->splashShader = &splashShader;
    context->frame++;

    scene.render(*context);
}