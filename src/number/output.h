#ifndef output_h
#define output_h

void (*print)(struct Num*);
void output_num_graph(struct Num *, char* text);
void output_num_binary(struct Num *, char* text);
void output_num_csv(struct Num *, char* text);
void output_num_simple(struct Num *, char*);

#endif
