#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  if(argc != 3 && (argc != 4 || (argc == 4 && !strcmp(argv[2], "-s")))){  // too few arguments for symbolic links or a command without '-s'
    printf(2, "Usage: ln old new\n");
    printf(2, "or- Usage for symbolic links: ln -s old new!\n");
    exit();
  }
  if(argc == 3){
    if(link(argv[1], argv[2]) < 0)
      printf(2, "link %s %s: failed\n", argv[1], argv[2]);
  }
  else{
    if(symlink(argv[2], argv[3]) < 0)  // creation of symlink failed!
      printf(2, "symlink %s %s: failed\n", argv[2], argv[3]);
  }

  exit();
}
