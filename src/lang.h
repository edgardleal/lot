
#ifndef lang_h
#define lang_h
#define ERR_IF(x) if(x) { \
        rc2 = __LINE__; \
        printf("Error (%s: %d)! Exiting\n", \
                           __FUNCTION__, rc2); exit(-1); }
extern char* iff(int, char*, char*);

#endif
