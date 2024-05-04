#version 120



// The sfml does not provide normalized uv coordinates, so we have to do it manually
// My source: https://en.sfml-dev.org/forums/index.php?topic=21635.0
uniform vec2 size;

varying vec2 vUvs;

void main() {
    vec4 vertex = gl_ModelViewMatrix * gl_Vertex;

    gl_Position = gl_ProjectionMatrix * vertex;
    vUvs = gl_Vertex.xy / size;
}