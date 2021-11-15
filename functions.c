/*
void treeJumper (char** source, char* path)
{
    int len, lenSOURCE;
    while (path[len]=!'/0') len++;
    char** temp = (char**)malloc()

} while (path[len]=!'/0') len++;
    char** temp = (char**)malloc()

}
*/
char* strcrt(char* source, char* addable)
{
    
    int pathLen=0;
    int  addLen = 0;
    while (source[pathLen] !='\0') pathLen++;
    while (addable[addLen] !='\0') addLen++;
    char* temp = (char*)malloc(pathLen+1+addLen);
    
    for (int i=0; i<pathLen; i++) temp[i]=source[i];
    temp[pathLen]='/';
    for (int i=0; i<addLen; i++) temp[i+pathLen+1]=addable[i];
    
    return temp;
}