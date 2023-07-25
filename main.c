 #include <stdio.h>
 #include "main.h"
 #include <stdarg.h>

 int main(void)
 {
         char alpha = 'a';
         char *str = "Obafemi Olabayo .O";
         int counter = 0;
         int counter2 = 0;
         int counter3 = 0;

         printf("<============================>\n");
         printf("using standard library\n");
         counter = printf("%s is %c nice guy 100%%\n", str, alpha);
         printf("counter = %d\n", counter);

         _printf("<=======================================>\n");
         counter3 = str_print("using my printf\n");
         printf("counter3 = %d\n", counter3);
         counter2 = _printf("%s is %c nice guy 100%%\n", str, alpha);
         printf("counter2 = %d\n", counter2);

         return (0);
 }
