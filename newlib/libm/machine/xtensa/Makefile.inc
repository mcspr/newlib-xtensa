%C%_src = \
	%D%/feclearexcept.c %D%/fegetenv.c %D%/fegetexcept.c \
	%D%/fegetexceptflag.c %D%/fegetround.c %D%/feholdexcept.c \
	%D%/feraiseexcept.c %D%/fetestexcept.c %D%/feupdateenv.c

libm_a_SOURCES += $(%C%_src)
