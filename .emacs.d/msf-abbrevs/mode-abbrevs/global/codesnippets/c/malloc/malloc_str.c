char* desStr = (char*)malloc(10);
memset(desStr, '1', 9);    
desStr[9] = '\0';

free(desStr);
desStr = NULL;
