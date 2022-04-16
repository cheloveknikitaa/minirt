#all source for minirt

MAIN	:=	main.c

FIGURE	:=	cone.c plane.c cylinder.c sphere.c

UTILS	:=	utils_vec3.c utils_vec3_1.c utils_vec3_2.c utils_color.c \
			utils_math.c utils_hook.c utils.c utils_vec2.c utils_vec2_1.c

PARSER	:=	utils_protect.c parser.c 

SOURCE	:=	$(MAIN) $(FIGURE) $(UTILS) $(PARSER)

OBJECT	:=	$(SOURCE:.c=.o)