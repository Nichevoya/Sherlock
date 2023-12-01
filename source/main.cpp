#include "duplicate_remover.hpp"

void run(int ac, char **av) 
{
    if (ac <= 2) 
        duplicate_remover remover(av[1] != nullptr ? av[1] : ".");
}

int main(int ac, char **av)
{
    run(ac, av);
}