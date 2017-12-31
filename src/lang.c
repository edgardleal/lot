/** \file 
 * 
 * \brief Description 
 * @author Edgard Leal <edgardleal@gmail.com> 
 *
 **/
#ifndef lang_c
#define lang_c

extern char* iff(int condition, char* iftrue, char* iffalse)
{
    if ( condition ) {
        return iftrue;
    } else {
        return iffalse;
    }
}
#endif
/* vim: set expandtab tabstop=4 shiftwidth=4 :*/
