[vertex]
#version 460 core
layout(location = 0) in vec3 a_Position;


uniform mat4 lp_Transform;

layout(std140, binding = 0) uniform Matrices 
{
    mat4 lp_Projection;
    mat4 lp_View;
};

out vec4 v_Color;

void main()
{
    gl_Position = lp_Projection * lp_View * lp_Transform * vec4(a_Position, 1.0);
    v_Color = a_Color; 
}

[fragment]
#version 460 core
in vec4 v_Color;
out vec4 o_Color;

uniform vec4 u_Color;

void main()
{
    o_Color = u_Color; 
}

