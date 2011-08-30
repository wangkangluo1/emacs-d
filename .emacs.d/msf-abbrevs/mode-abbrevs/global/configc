
#include "config.h"
#include <stdlib.h>
#include <string.h>

G_CONFIG* G = NULL;
               /* -----  数据库根节点  ----- */ 

    void
start_CONFIG (  )
{
    G = (G_CONFIG*)malloc(sizeof(G_CONFIG));
    memset(G, 0, sizeof(G_CONFIG));

    G->p_ch_test = (char*)malloc(20);
    memset(G->p_ch_test, '1', 9);
    G->p_ch_test[9] = '\0';

    G->n_test = 10;
}		/* -----  end of function start_c  ----- */

    void
free_CONFIG (  )
{
    free(G->p_ch_test);
    free(G);
    return ;
}		/* -----  end of function free_config  ----- */
