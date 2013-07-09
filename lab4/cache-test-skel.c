/*
Coursera HW/SW Interface
Lab 4 - Mystery Caches

Mystery Cache Geometries (for you to keep notes):
mystery0:
    block size = 64
    cache size = 4096
    associativity = 32
mystery1:
    block size = 8
    cache size = 8192
    associativity = 8
mystery2:
    block size = 32
    cache size = 32768
    associativity = 2
mystery3:
    block size = 16
    cache size = 4096
    associativity = 1
*/

#include <stdlib.h>
#include <stdio.h>

#include "mystery-cache.h"

/*
 * NOTE: When using access_cache() you do not need to provide a "real"
 * memory addresses. You can use any convenient integer value as a
 * memory address, you should not be able to cause a segmentation
 * fault by providing a memory address out of your programs address
 * space as the argument to access_cache.
 */

/*
   Returns the size (in B) of each block in the cache.
*/
int get_block_size(void) {
  /* YOUR CODE GOES HERE */
	int i = 0;
	flush_cache();
	access_cache(i);	//fill initial 0 into cache
	while ( access_cache(i) )	//as soon as we find us  a miss in cache, we out of first block and i is it's size
	{
		i++;
	}
  return i;
}

/*
   Returns the size (in B) of the cache.
*/
int get_cache_size(int size) { 
  /* YOUR CODE GOES HERE */
  int i, bsize;
  
  flush_cache();
  bsize = get_block_size(); //lol calculated block size again instead of using size argument
  
  i = 0;
	while( 1  )	//filling cache untill it's full by jumping over block j times
	{		
		flush_cache();	//flush cache each time and access address 0 to start with empty cache for each iteration
		access_cache(0);
		int j = 1;
		while ( j <= i )	// fill i blocks of cache( access to each bsize*j address fills entire bsize block there)
		{
			access_cache(j*bsize);
			j++;
		}
		if ( access_cache(0) ) //continue increasing i (number of blocks to fill into cache) if 0 wasnt overwritten
		{
			i++; 
		}
		else	//if 0 was overwritten in the last iteration i would be the number of blocks in cache
		{
			break;
		}		
	}
  return i*bsize;
}

/*
   Returns the associativity of the cache.
*/
int get_cache_assoc(int size) {
  /* YOUR CODE GOES HERE */
  int i;
  
  flush_cache();  
  access_cache(0);
  
  i = 0;
  while ( access_cache(0) ) //filling set untill it's full by jumping over cache size j times
  {
  	flush_cache();
  	access_cache(0); 
  	
  	int j = 1;
		while ( j <= i+1 )		// same as cache size but jumps over entire cache instead of block to try to access
		{											//the address that should map to same set that our inintial access ( address 0 here)
			access_cache(j*size);
			j++;
		}
		
		i++;
  } 
	
  return i;
}

//// DO NOT CHANGE ANYTHING BELOW THIS POINT
int main(void) {
  int size;
  int assoc;
  int block_size;

  /* The cache needs to be initialized, but the parameters will be
     ignored by the mystery caches, as they are hard coded.  You can
     test your geometry paramter discovery routines by calling
     cache_init() w/ your own size and block size values. */
  cache_init(0,0);

  block_size=get_block_size();
  size=get_cache_size(block_size);
  assoc=get_cache_assoc(size);

  printf("Cache block size: %d bytes\n", block_size);
  printf("Cache size: %d bytes\n", size);
  printf("Cache associativity: %d\n", assoc);

  return EXIT_SUCCESS;
}
