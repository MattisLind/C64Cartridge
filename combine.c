#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int
main (int argc, char **argv)
{
  int aflag = 0;
  int bflag = 0;
  char *cvalue = NULL;
  int index;
  int c;
  int verbosity=0;
  int dst_address;
  int src_address=0;
  char output_filename [256];
  FILE * in, * out;
  unsigned char src_buffer[16384];
  unsigned char dst_buffer[262144];
  opterr = 0;
  while ((c = getopt (argc, argv, "vh:l:uf:o:")) != -1)
    switch (c)
      {
      case 'o':
	strcpy(output_filename,optarg);	
      case 'v':
	verbosity++;
	printf ("Verbosity: %d\n", verbosity);
	break;
      case 'h':
	printf ("High index: %d\n", atoi(optarg));
	dst_address = atoi(optarg)*8192;
        break;
      case 'l':
	printf ("Low index: %d\n", atoi(optarg));
	dst_address = atoi(optarg)*8192+131072;
        break;
      case 'u':
	printf ("Read from upper 8k\n");
	src_address=8192;
        break;
      case 'f':
	printf ("Read from file %s\n", optarg);
	in = fopen(optarg, "rb");
	if (in!=NULL) {
	  fread(src_buffer, 16384,1, in);
	}
	memcpy(dst_buffer+dst_address, src_buffer+src_address,8192);
	src_address=0;
	break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }
  out = fopen (output_filename, "wb");
  if (out != NULL) {
    fwrite(dst_buffer, 262144,1,out);
  }
  return 0;
}
