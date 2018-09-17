#include<stdarg.h>
#include<stdio.h>
#include "tinyprintf.h"

char *my_itoa_base( long int n, char *s, const char *base)
{
    char const *digits = base;
    int basen = 0;
    while(*base != '\0')   // strlen of base
    {
        basen+=1;
        base++;
    }
    long int val = n;
    int len = 0;
    if(val == 0)     // special case
    {
        *s = *digits;
        *(s+1) = '\0';
    }
    while(val > 0)
    {
        len+=1;
        val/=basen;
    }
    *(s + len) = '\0';
    len-=1;
    long int number = 0;
    while(len >=0)
    {
        number = n % basen;
        *(s + len) = *(digits + number);  // 
        len--;
        n /= basen;
    }
    return s;
}
int my_strlen(const char *s)
{   
    int len=0;
    while(*s != '\0')
    {
        len+=1;
        s++;
    }
    return len;
}
void my_print(const char *s)
{
    while(s != NULL && *s!= '\0')
    {
        putchar(*s);
        s++;
    }
}
/*
int calculate_return(const char *s)
{
    int length = 0;
    if(s == NULL)
    {
        my_print("(null)");
        length = 6;
    else
    {
        my_print(s);
        length = my_strlen(s);
    }
    return length;
}
*/
int tinyprintf(const char *format , ...)
{
    int len = 0;
    va_list ap;
    va_start(ap, format);
    while(*format != '\0')
    {
        if(*format == '%')
        {
            format++;
            switch (*format)
            {
                case 's':
                    {       // semicolon to allow declaration 
                         const char *s = va_arg(ap ,char*);
                         if(s == NULL)
                         {
                             my_print("(null)");
                             break;
                         }
                         my_print(s);
                         len+=(my_strlen(s));
                         break;
                    }
                case 'c': 
                    {
                          const char c = va_arg(ap, int);
                          putchar(c);
                          len++;
                          break;
                    }
                case 'd':
                    {
                         int d = va_arg(ap , int);
                         char string_d[] ="                 ";
                         if(d<0)
                         {
                            putchar(45);
                            d*=-1;
                            len ++;
                         }
                         my_itoa_base(d , string_d, "0123456789");
                         my_print(string_d);
                         len+=(my_strlen(string_d));
                         break;
                    }
                case 'u':
                    {
                         unsigned long int u = va_arg(ap , unsigned);
                         char string_u[] = "           ";
                         my_itoa_base(u , string_u, "0123456789");
                         my_print(string_u);
                         len+=(my_strlen(string_u));
                         break;
                    }
                case 'o':
                    {
                         int o = va_arg(ap , int);
                         char string_o[] = "             ";
                         if(o<0)
                         {
                             putchar(45);
                             o*=-1;
                         }
                         my_itoa_base(o , string_o, "01234567");
                         my_print(string_o);
                         len+=(my_strlen(string_o));
                         break;
                    }             
                case 'x':
                    {
                         int h = va_arg(ap , int);
                         char string_h[] = "             ";
                         if(h<0)
                         {
                             putchar(45);
                             h*=-1;
                         }
                         my_itoa_base(h , string_h, "0123456789abcdef");
                         my_print(string_h);
                         len+=(my_strlen(string_h));
                         break;
                    }
                case '%':
                    {
                         putchar(37);
                         len+=1;
                         break;
                    }
                default:
                    {
                         putchar(37);
                         my_print(format);
                         len = len + (my_strlen(format)) + 1;
                    }
            };
        }
        else 
        {
            putchar(*format);
            len++;
        }
        format++;
    }
    va_end(ap);
    return len;
}

int main()
{
    char *c = " YUPPPP " ;
    int number = -48;
    int length = 0;
    length = tinyprintf("Does this work? %s" , c);
    printf("\n");
    printf(" %d " , length );
    printf("\n");
    length = tinyprintf("Does this work? %c", 'A');
    printf("\n");
    printf("\n");
    printf(" %d " , length );
    length = tinyprintf("Does this work? %d" , number );
    printf("\n");
    printf("\n");
    printf(" %d " , length );
    length = tinyprintf("Does this work? %u" , number);
    printf("\n");
    printf("\n");
    printf(" %d " , length );
    length = tinyprintf("Does this work? %o" , number);
    printf("\n");
    printf("\n");
    printf(" %d " , length );
    length = tinyprintf("Does this work? %x" , number);
    printf("\n");
    printf("\n");
    printf(" %d " , length );
    length = tinyprintf("Does this work? %%%%" , c , 2 , "A");
    printf("\n");
    printf("\n");
    printf(" %d " , length );
    length = tinyprintf("%s [%x] %s" ," Hello ", 42, " world! ");
    printf("\n");
    printf("\n");
    printf(" %d " , length );
    length = tinyprintf("%%s", " in your head ");
    printf("\n");
    printf("\n");
    printf("%d " , length );
    length = tinyprintf("Good morning ACU! %t Tinyprintf is cool", 12);
    printf("\n");
    printf("\n");
    printf(" %d " , length );
    length = tinyprintf("%c%c is %s... %d too.", '4', '2', "the answer", '*');
    printf("\n");
}
