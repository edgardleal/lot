//
// Created by Edgard Leal on 29/12/17.
//

#ifndef LOT_APP_H
#define LOT_APP_H
#define die(text, args...) do { fprintf(stderr, text, ##args); exit(1); } while(0)
#define error(text, args...) do { fprintf(stderr, text, ##args); } while(0)
#define out(text, args...) do { printf(text, ##args); } while(0)
#define debug(text, args...) do { if(IS_DEBUG) out(text, ##args); } while(0)

int IS_DEBUG;
#endif //LOT_APP_H
