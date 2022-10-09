#include <stdio.h>
#include <stdlib.h>
#include <config.h>

#ifdef USE_MYMATH
  #include <math_function.h>
#else
  #include <math.h>
#endif

int main(int argc, char *argv[])
{
    if (argc < 3){
        // print version info，必须在.h.in配置文件中增加宏定义
        printf("%s Version %d.%d\n",
            argv[0],
            my_math_VERSION_MAJOR,
            my_math_VERSION_MINOR);
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);
    
#ifdef USE_MYMATH
    printf("Now we use our own Math library. \n");
    double result = power(base, exponent);
#else
    printf("Now we use the standard library. \n");
    double result = pow(base, exponent);
#endif
    
    printf("%g ^ %d is %g\n", base, exponent, result);
    return 0;
}