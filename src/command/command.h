
#ifndef command_h
#define command_h

struct command {
    char *name;
    int (function*)(char**, int);
    struct command next;
};

struct command command_new(char*);
int command_execute(char**, int);
void command_free(struct command);

#endif
