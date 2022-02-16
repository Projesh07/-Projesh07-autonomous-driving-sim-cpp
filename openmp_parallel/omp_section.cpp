#include <stdio.h>
#include <omp.h>
#include <iostream>

/**********************************************
**......................................................
By default all variable are share except loop variable.
......................................................
** ...............................................................
Thread that come first take any of the section random and other thread take 
a another section 
...............................................................
**/

void section_main() {

    double start;
    double end;
    int number_of_threads = 4;
    omp_set_num_threads(number_of_threads);
    printf("Number of threads %d \n", number_of_threads);
    start = omp_get_wtime();
    omp_set_num_threads(number_of_threads);

    int sum = 0;
    #pragma omp parallel shared(sum)
        {

            #pragma omp sections
                    {

            #pragma omp section
                        {
                            int id = omp_get_thread_num();
                            std::cout << "1. Section thread id: " << id << std::endl;
                            sum = sum + 1;
                            std::cout << "Sum: " << sum << std::endl;
                           


                        }
            #pragma omp section
                        {
                            int id = omp_get_thread_num();
                            std::cout << "2. Section thread id: " << id << std::endl;
                            sum = sum + 1;
                            std::cout << "Sum: " << sum << std::endl;
                        }
            #pragma omp section
                        {
                            int id = omp_get_thread_num();
                            std::cout << "3. Section thread id: " << id << std::endl;
                            sum = sum + 1;
                            std::cout << "Sum: " << sum << std::endl;
                           

                        }
            #pragma omp section
                        {
                            int id = omp_get_thread_num();
                            std::cout << "4. Section thread id: " << id << std::endl;
                            sum = sum + 1;
                            std::cout << "Sum: " << sum << std::endl;

                        }
                    }
        }

        std::cout << "Total sections in a section :" << sum << std::endl;


}