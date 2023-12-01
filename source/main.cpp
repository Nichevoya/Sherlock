#include "sherlock.hpp"

void run(int ac, char **av) 
{
    if (ac <= 2) 
        sherlock(av[1] != nullptr ? av[1] : ".");
}

int main(int ac, char **av)
{
    run(ac, av);
}