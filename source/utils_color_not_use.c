#include "miniRT.h"

t_vec3	rgb_to_Yxy(t_vec3 color)
{
	t_vec3	tmp;

	color = vec3_mulS(color, 1 / 255.0);
	if (color.x > 0.04045)
		color.x = powf(((color.x + 0.055) / 1.055), 2.4);
	else
		color.x /= 12.92;
	if (color.y > 0.04045)
		color.y = powf(((color.y + 0.055) / 1.055), 2.4);
	else
		color.y /= 12.92;
	if (color.z > 0.04045)
		color.z = powf(((color.z + 0.055) / 1.055), 2.4);
	else
		color.z /= 12.92;
	color = vec3_mulS(color, 100.0);
	tmp.x = color.x * 0.649926 + color.y * 0.103455 + color.z * 0.197109;
	tmp.y = color.x * 0.234327 + color.y * 0.743075 + color.z * 0.022598;
	tmp.z = color.x * 0.000000 + color.y * 0.053077 + color.z * 1.035763;
	color = tmp;
	// printf("X = %f Y = %f, Z = %f\n", color.x, color.y, color.z);
	tmp.z = tmp.y;
	tmp.x = color.x / (color.x + color.y + color.z);
	tmp.y = color.y / (color.x + color.y + color.z);
	// printf("x= %f y = %f, Y = %f\n", tmp.x, tmp.y, tmp.z);
	return (tmp);
}

t_vec3	Yxy_to_rgb(t_vec3 color)
{
	t_vec3	tmp;

	tmp.x = color.x * (color.z / color.y);
	tmp.y = color.z;
	tmp.z = (1 - color.x - color.y) * (color.z / color.y);
	color = vec3_mulS(tmp, 1 / 100.0);
	tmp.x = color.x * 1.4628067 + color.y * -0.1840623 + color.z * -0.2743606;
	tmp.y = color.x * -0.5217933 + color.y * 1.4472381 + color.z * 0.0677227;
	tmp.z = color.x * 0.0349342 + color.y * -0.0968930 + color.z * 1.2884099;
	if (tmp.x > 0.0031308)
		color.x = 1.055 * powf(tmp.x, 1 / 2.4) - 0.055;
	else
		color.x = tmp.x * 12.92;
	if (tmp.y > 0.0031308)
		color.y = 1.055 * powf(tmp.y, 1 / 2.4) - 0.055;
	else
		color.y = tmp.y * 12.92;
	if (tmp.z > 0.0031308)
		color.z = 1.055 * powf(tmp.z, 1 / 2.4) - 0.055;
	else
		color.z = tmp.z * 12.92;
	color = vec3_mulS(color, 255.0);
	if (color.x > 255.0)
		color.x = 255.0;
	if (color.x < 0)
		color.x = 0.0;
	if (color.y > 255.0)
		color.y = 255.0;
	if (color.y < 0)
		color.y = 0.0;
	if (color.z > 255.0)
		color.z = 255.0;
	if (color.z < 0)
		color.z = 0.0;
	// printf("r = %f g = %f, b = %f\n", color.x, color.y, color.z);
	return (color);
}

//	tmp.x = color.x * 0.649926 + color.y * 0.103455 + color.z * 0.197109;
// 	tmp.y = color.x * 0.234327 + color.y * 0.743075 + color.z * 0.022598;
// 	tmp.z = color.x * 0.000000 + color.y * 0.053077 + color.z * 1.035763;

	// tmp.x = color.x * 1.4628067 + color.y * -0.1840623 + color.z * -0.2743606;
	// tmp.y = color.x * -0.5217933 + color.y * 1.4472381 + color.z * 0.0677227;
	// tmp.z = color.x * 0.0349342 + color.y * -0.0968930 + color.z * 1.2884099;

t_vec3	rgb_to_xyz(t_vec3 color)
{
	t_vec3	tmp;

	color = vec3_mulS(color, 1 / 255.0);
	if (color.x > 0.04045)
		color.x = powf(((color.x + 0.055) / 1.055), 2.4);
	else
		color.x /= 12.92;
	if (color.y > 0.04045)
		color.y = powf(((color.y + 0.055) / 1.055), 2.4);
	else
		color.y /= 12.92;
	if (color.z > 0.04045)
		color.z = powf(((color.z + 0.055) / 1.055), 2.4);
	else
		color.z /= 12.92;
	// color = vec3_mulS(color, 100.0);
	// tmp.x = color.x * 0.649926 + color.y * 0.103455 + color.z * 0.197109;
	// tmp.y = color.x * 0.234327 + color.y * 0.743075 + color.z * 0.022598;
	// tmp.z = color.x * 0.000000 + color.y * 0.053077 + color.z * 1.035763;
	// color = tmp;
	return (color);
}

t_vec3	xyz_to_rgb(t_vec3 color)
{
	t_vec3	tmp;

	color = vec3_mulS(tmp, 1 / 100.0);
	tmp.x = color.x * 1.4628067 + color.y * -0.1840623 + color.z * -0.2743606;
	tmp.y = color.x * -0.5217933 + color.y * 1.4472381 + color.z * 0.0677227;
	tmp.z = color.x * 0.0349342 + color.y * -0.0968930 + color.z * 1.2884099;
	if (tmp.x > 0.0031308)
		color.x = 1.055 * powf(tmp.x, 1 / 2.4) - 0.055;
	else
		color.x = tmp.x * 12.92;
	if (tmp.y > 0.0031308)
		color.y = 1.055 * powf(tmp.y, 1 / 2.4) - 0.055;
	else
		color.y = tmp.y * 12.92;
	if (tmp.z > 0.0031308)
		color.z = 1.055 * powf(tmp.z, 1 / 2.4) - 0.055;
	else
		color.z = tmp.z * 12.92;
	color = vec3_mulS(color, 255.0);
	if (color.x > 255.0)
		color.x = 255.0;
	if (color.x < 0)
		color.x = 0.0;
	if (color.y > 255.0)
		color.y = 255.0;
	if (color.y < 0)
		color.y = 0.0;
	if (color.z > 255.0)
		color.z = 255.0;
	if (color.z < 0)
		color.z = 0.0;
	return (color);
}

// mixcolor
	// printf("r = %f g = %f, b = %f\n", color1.x, color1.y, color1.z);

	// color1_mko = rgb_to_Yxy(color1);
	// color2_mko = rgb_to_Yxy(color2);
	// mix.x = (color1_mko.x * color1_mko.z / color1_mko.y + \
	// 		color2_mko.x * color2_mko.z / color2_mko.y) / \
	// 		(color1_mko.z / color1_mko.y + color2_mko.z / color2_mko.y);
	// mix.y = (color1_mko.y * color1_mko.z / color1_mko.y + \
	// 		color2_mko.y * color2_mko.z / color2_mko.y) / \
	// 		(color1_mko.z / color1_mko.y + color2_mko.z / color2_mko.y);
	// mix.z = color1_mko.z + color2_mko.z;
	
	// inter.x = (mix.x - 0.735) * (0.265 - 0.717) - (mix.y - 0.265) * (0.735 - 0.274);
	// inter.y = (mix.x - 0.274) * (0.717 - 0.009) - (mix.y - 0.717) * (0.274 - 0.167);
	// inter.z = (mix.x - 0.167) * (0.009 - 0.265) - (mix.y - 0.009) * (0.167 - 0.735);
	// if (inter.x >= 0 && inter.y >= 0 && inter.z >= 0)
	// 	;
	// else
	// 	return(new_vec3(1.0, 1.0, 1.0));
	//mix = Yxy_to_rgb(mix);