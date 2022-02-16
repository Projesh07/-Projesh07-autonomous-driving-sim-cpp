# autonomous-driving-simulator-cpp

# Table of content:
  * C to C++code conversiton
  * GLUT to OpenGL converstion
  * Using Intel openmp parallel programming 

  For my bottom-up implementation I am starting with parallel programing 

## Using Intel OpenMP parallel programming 
  * What is parallel computing 
  * - In parallel programming, tasks are parallelized so that they can be run at the same time by using multiple computers or multiple cores within a CPU. 
  * - Parallel programming is critical for large-scale projects in which speed and accuracy are needed. 
  * - It is a complex task but allows developers, researchers, and users to accomplish research and analysis quicker than with a program that can only process one task at a time
  * - Each thread instruction is independent from other threads ( for example, value of A depends on another variable or previous value of A)
  
  * Multiprocessing means: 
  * - Having a processor with multiple cores or sub-processor in a package 
  * - Where every single core can execute multiple threads
  * - Each thread contains one or more CPU instructions (for instance # MOV  or AND instruction) 
  * Let’s understand your computer: 
  *  - My one is Amd ryzen 7 5800x
  *  - Power up your computing experience with the AMD Ryzen 7 5800X 3.8 GHz Eight-Core AM4 Processor,
  *  - Which features eight cores and 16 threads for each core to help quickly load and multitask demanding applications at a single time.
  *  - For better understanding please have a look at the image where I have marked my computer configuration 
  *  - You can do yours by going to Task manager -> To perfromance -> select CPU
  *   ![Task-Manager-2022-02-15-21-33-40_Trim](https://user-images.githubusercontent.com/8930208/154147802-146864c8-a397-4d40-ab79-38642d34b079.gif)
  *   - For more knowledge please visit 
  *  [OpenMP tutorials by Tim Mattson] https://www.youtube.com/channel/UC7jgpE3sllixozoA4GzVRqQ  




## Basics of Intel OpenMP parallel programming 
  **  pragma omp parallel: 

```
 #include <stdio.h>
 #include <omp.h>
 #include <iostream>

 int main() {
  const int n = 100000;
  int array[n];
  double start;
  double end;
  int number_of_threads = 8;
  omp_set_num_threads(number_of_threads);
  printf("Number of threads %d \n", number_of_threads);
  start = omp_get_wtime();
  #pragma omp parallel
  { 
   // each thread is executing (concurently)
   int thread_id = omp_get_thread_num();
   printf("Now executing thread: %d\n", thread_id);
  }
  end = omp_get_wtime();
  printf("Work took %f seconds\n", end - start);

 }
```
<img width="418" alt="image" src="https://user-images.githubusercontent.com/8930208/154274397-98a237e0-72bc-42fe-b6a4-f361812e6e7f.png">

```
 #include <stdio.h>
 #include <omp.h>
 #include <iostream>


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
                         std::cout << "Section thread id: " << id << std::endl;
                         sum = sum + 1;

                     }
         #pragma omp section
                     {
                         int id = omp_get_thread_num();
                         std::cout << "Section thread id: " << id << std::endl;
                         sum = sum + 1;
                     }
         #pragma omp section
                     {
                         int id = omp_get_thread_num();
                         std::cout << "Section thread id: " << id << std::endl;
                         sum = sum + 1;
                     }
         #pragma omp section
                     {
                         int id = omp_get_thread_num();
                         std::cout << "Section thread id: " << id << std::endl;
                         sum = sum + 1;
                     }
                 }
         }

         std::cout << "Total sections in a section :" << sum << std::endl;


 }
```
<img width="587" alt="image" src="https://user-images.githubusercontent.com/8930208/154298800-f7d55def-4e03-49b9-b315-63070eae0df5.png">




![Atuo-driving-simulation](https://user-images.githubusercontent.com/8930208/153515218-fe22adc0-15c6-4c91-9600-054bcbf25890.gif)
