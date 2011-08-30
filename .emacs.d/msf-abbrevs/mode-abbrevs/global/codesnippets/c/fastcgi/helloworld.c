
#include <stdio.h>  
#include <stdlib.h>  
#include <fcgiapp.h>  
  
#define printf(...) FCGX_FPrintF(request->out, __VA_ARGS__)  
#define get_param(KEY) FCGX_GetParam(KEY, request->envp)  
  
void handle_request(FCGX_Request *request) {  
    char *value;  
  
    printf("Content-Type: text/plain\r\n\r\n");  
    if ((value = get_param("REQUEST_METHOD")) != NULL) {  
        printf("%s ", value);  
    }  
    if ((value = get_param("REQUEST_URI")) != NULL) {  
        printf("%s", value);  
    }  
    if ((value = get_param("QUERY_STRING")) != NULL) {  
        printf("?%s", value);  
    }  
    if ((value = get_param("SERVER_PROTOCOL")) != NULL) {  
        printf(" %s", value);  
    }  
    printf("\n");  
}  
  
int main(void) {  
    //int sock;  
    FCGX_Request request;  
  
    FCGX_Init();   
    //sock = FCGX_OpenSocket(":2005", 5);  
    FCGX_InitRequest(&request, 0, 0);  
  
    while (FCGX_Accept_r(&request) >= 0) {  
        handle_request(&request);  
        FCGX_Finish_r(&request);  
    }  
  
    return EXIT_SUCCESS;  
} 
