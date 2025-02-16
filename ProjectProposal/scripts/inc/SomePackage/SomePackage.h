#ifndef SOME_PACKAGE_H
#define SOME_PACKAGE_H 1

#include "./../shared.h" /* Importing the dependencies */


/*
    @author This function was made by ME!
    
    @brief This function prints "Hello Wolrd!" and the number insert!
    
    @param someNumber int: the number you want print.
    
    @return
        - true: if everything correctly

        - false: this will never happen, it's just here to demonstrate that the bool type is being pulled from Semantic.h correctly 
*/
bool printHelloWolrd(int someNumber);


#endif