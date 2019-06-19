#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>


int main(int argc, char *argv[])
{
  struct stat sb;
  DIR *dirp;
  struct dirent *direntp;
  char filename[128];
  if ((dirp = opendir("/data")) == NULL) {
    printf("Open Directory Error%s\n");
    exit(1);
  }
  while ((direntp = readdir(dirp)) != NULL){
    sprintf(filename, "/data/%s", direntp->d_name);
    if (lstat(filename, &sb) == -1)
    {
      printf("lstat Error%s\n");
      exit(1);
    }


    printf("name : %s, mode : %d, size : %d, user id : %d\n", direntp->d_name, sb.st_mode, sb.st_size, sb.st_uid);


  }
  closedir(dirp);


  return 0;
}

