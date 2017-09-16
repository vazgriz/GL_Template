#version 330

// Input: UV coordinates
in INTERFACE {
	vec2 uv;
} In ;

// Uniforms: the textures.
uniform sampler2D texture0;
uniform sampler2D texture1;

// Output: the fragment color
out vec3 fragColor;


void main(){
	vec3 col = texture(texture0, In.uv).rgb;
	col += texture(texture1, In.uv).rgb;
	fragColor = col / 2.0;
}