#include <dirent.h>
#include <iostream>
#include <stdio.h>

void get_info_for_pid(char *name) {
	printf("%s\n", name);
}

main ()
{

  DIR *proc = opendir ("/proc");

  if (proc == 0)
    {
      std::cerr << "Error reading /proc, neede to get inode-to-pid-maping\n";
      return 0;
    }

  dirent *entry;

  while ((entry = readdir (proc)))
    {
      if (entry->d_type != DT_DIR)
	continue;

      //std::cout << "Getting info for " << entry->d_name << std::endl;
      get_info_for_pid (entry->d_name);
    }
  //std::cout << "End...\n";
  closedir (proc);

}
