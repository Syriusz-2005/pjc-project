#include "Renderer.h"

Renderer::Renderer(Scene &scene, Camera &camera, Context &ctx) : scene(&scene), camera(&camera), context(&ctx) {

}

auto Renderer::render() -> void {
    auto cameraPos = camera->getPos();
    context->globalPos = -cameraPos;

    scene->render(*context);
}