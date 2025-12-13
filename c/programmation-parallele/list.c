#include <stdio.h>
#include <omp.h>

List ml;
Element *e;

#pragma omp parallel
#pragma omp single
{
    for (e = ml->first; e; e = e->next)
    #pragma omp task
    process(e);
}
