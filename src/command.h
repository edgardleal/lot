#ifndef command_h
#define command_h

typedef int (*t_command)(char *);

/**
 * /struct Command
 * /brief Store a command sended by user
 */
struct Command {
    char *name;
    char *command_line;
    t_command function;
    void (*free)(struct Command*);
    void (*load)(struct Command*, char*);
};

int show_results(char*);
int show_my(char*);
int update(char*);
struct Command* command_new(char*);
void command_free(struct Command*);
void command_load(struct Command*, char*);

#endif
