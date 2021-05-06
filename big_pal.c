#include <unistd.h>

int slen(char *str)
{
        int i = 0;
        int count = 0;
        while (str[i] != '\0')
        {
                i++;
                count++;
        }
        return (count);
}

int is_pal(char *s, int len)
{
        int i = len / 2;

        char *start = s;
        char *end = s + (len - 1);

        if (len > 3)
        {
                while (i--)
                {
                        if (*start != *end)
                                return (0);
                        start++;
                        end--;
                }
        }
        return (*start == *end);
}

int find_biggest_pal(char *s)
{
        int len = slen(s);
        int k = len;
        char *last_pal = s;

        while (k > 3)
        {
                last_pal = s + (len - k);
                while (1)
                {
                        if (is_pal(last_pal, k))
                                return (write(1, last_pal, k));
                        if (last_pal == s)
                                break;
                        last_pal--;
                }
                k--;
        }
        return (0);
}

int main(int ac, char **av)
{
        if (ac == 2)
        {
        find_biggest_pal(av[1]);

        }
        write(1, "\n", 1);
}