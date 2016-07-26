uniform sampler2DRect maskTex;

void main (void)
{
	vec2 pos = gl_TexCoord[0].st;
    vec4 mask = texture2DRect(maskTex, pos);
    vec4 color = vec4(0,0,0,0);
    color.r = mask.r;
    color.g = mask.g;
    color.b = mask.b;
    gl_FragColor = color;
   }