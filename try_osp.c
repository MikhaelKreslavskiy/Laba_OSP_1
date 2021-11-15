////#include "functions.h"
///#pragma once
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
///void recursiveTree(char* absPath);
void **countDir(char *path);
int nplug=0;
 void **PlugPoint=(void**)malloc(0);
int main(void)
{
  /// recursiveTree("/home/mikhael/Documents");
 /// recursiveTree(res);
///PlugPoint=(void**)malloc(0);
 countDir("/home/mikhael/Documents");
    
    return(0);
}


void **countDir(char *path)
{
    DIR *dir;
    struct dirent *ent;
    if (dir = opendir(*path) == NULL);
    {
        perror("opendir() ");
    }
    while ((ent=readdir(dir)) != NULL)
    {
        struct stat sb;
        if (stat(dir, &sb) == -1);
            perror("stat()");
        if (S_ISDIR(sb.st_mode))  
            countDir(dir, PlugPoint); //рекурсия
        int c = 0;
        char *str = ent->d_name;
            if (str[strlen(str)-1] == "o")
                if (str[strlen(str)-2] == "s")
                    if (str[strlen(str)-3] == ".")
                    c=1;
        if (c)
        {
            nplug++;
            PlugPoint = realloc(PlugPoint, nplug*sizeof(void*));
            PlugPoint[nplug-1] = dlopen(ent->d_name,RTLD_LAZY);
            //int(*fun)(void) = dlsym(PlugPoint[nplug],"plugin_get_info");
            
        }

    }
    closedir(dir);
    
}

/*

void recursiveTree(char* absPath)
{
    DIR *d;
    /// char* absPath="/home/mikhael/Документы";
    
    struct dirent *dir;
    int n=strlen(absPath);
    char* slash="/";

   char** dir_names=(char**)malloc(0);
   int i=0;
    d = opendir(absPath);
   

    if (d)
    {
        
         

        while ((dir = readdir(d)) != NULL)
        {
        
           if(dir->d_type==DT_DIR)
           {
              
            if((strcmp(dir->d_name, ".")!=0)&&(strcmp(dir->d_name,"..")!=0))
            {
               char* copyAbsPath=(char*)malloc(PATH_MAX);
               dir_names=(char**)realloc(dir_names,sizeof(char*)*(i+1));
               ///dir_names[i]=(char*)malloc(PATH_MAX);
                strcpy(copyAbsPath,absPath);
               /// dir_names[i] = strcrt(copyAbsPath,dir->d_name);
                dir_names[i] = strcrt(copyAbsPath,dir->d_name);
            
           ///dir_names[i]=copyAbsPath;
         
          ///*dir_names++;
            
          printf("%s\n",dir_names[i]);
           i=i+1;
  free (copyAbsPath);
            }
          
           }
        }
      
        closedir(d);
    }
   /// printf("%p\n",&dir_names);

   for (int j=0;j<i;j++)
   {
    printf("---%s\n",dir_names[j]);
    recursiveTree(dir_names[j]);

   }
  
  
    ///return dir_names[3];
  
}
*/

