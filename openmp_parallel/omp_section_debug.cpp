#include <stdio.h>
#include <omp.h>
#include <iostream>
#include<string.h>


void sectioon_debug_main() {
    printf("Default number of T= %d\n", omp_get_num_threads());

    // set thread only in sequential region
    omp_set_num_threads(4);

    #pragma omp parallel
        {
            printf("Changed number of T= %d\n", omp_get_num_threads());

                    //#pragma omp sections nowait
            #pragma omp sections 
                    {
            #pragma omp section
                        {
                            printf("I am From T= %d\n", omp_get_thread_num());
                        }
            #pragma omp section
                        {
                            printf("I am From T= %d\n", omp_get_thread_num());
                        }
            #pragma omp section
                        {
                            printf("I am From T= %d\n", omp_get_thread_num());
                        }
            #pragma omp section
                        {
                            printf("I am From  T= %d\n", omp_get_thread_num());
                        }
                    }
        }
}