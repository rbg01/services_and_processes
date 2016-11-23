//
//  sem_common.h
//  
//
//  Created by Roberto Betés on 16/11/16.
//
//

#ifndef _SEM_COMMON_H_
#define _SEM_COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#ifdef __cplusplus
extern "C" {
#endif
    extern void CHECK_ARGS(count, msg) {
        
        if(argc != count){
            fprintf(stderr,"usage: %s" msg "\n", PROGNAME);
            exit(1);
        }

#ifdef __cplusplus
}

#endif
    
#endif
