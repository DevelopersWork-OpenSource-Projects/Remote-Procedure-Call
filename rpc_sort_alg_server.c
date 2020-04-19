/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "rpc_sort_alg.h"

ascii_chars *
bubble_sort_1_svc(ascii_chars *argp, struct svc_req *rqstp)
{
	static ascii_chars  result;
	int c,d,swap;
	for (c = 0 ; c < argp->n - 1; c++)
		for (d = 0 ; d < argp->n - c - 1; d++)
    		if (argp->buf[d] > argp->buf[d+1])
      		{
        		swap=argp->buf[d];
        		argp->buf[d]=argp->buf[d+1];
        		argp->buf[d+1]=swap;
      		} 
  	printf("Sorting with Bubble sort is completed.\n");

	for(c=0;c<argp->n;c++){
		result.buf[c]=argp->buf[c];
	}
	result.n=argp->n;
	return &result;
}

ascii_chars *
merge_sort_1_svc(ascii_chars *argp, struct svc_req *rqstp)
{
	static ascii_chars  result;

	int n,low_1,low_2,high_1,high_2,e,c,d,temp[n];
	n=1;
	while(n<argp->n){
		low_1=0;
		e=0;
		while( low_1+n < argp->n)
		{
			high_1=low_1+n-1;
			low_2=high_1+1;
			high_2=low_2+n-1;
			if( high_2>=argp->n ) 
				high_2=argp->n-1;
			
			c=low_1;
			d=low_2;
			
			while(c<=high_1 && d<=high_2 )
			{
				if( argp->buf[c] <= argp->buf[d] )
					temp[e++]=argp->buf[c++];
				else
					temp[e++]=argp->buf[d++];
			}
			
			while(c<=high_1)
				temp[e++]=argp->buf[c++];
			while(d<=high_2)
				temp[e++]=argp->buf[d++];
			low_1=high_2+1; 
		}
		c = low_1;
		while(e<argp->n){ 
			temp[e++]=argp->buf[c];
			c++;
		}
		c=0;
		while(c<argp->n){
			argp->buf[c]=temp[c];
			c++;
		}
		n*=2;
	}

	printf("Sorting with Merge sort is completed.\n");

	for(c=0;c<argp->n;c++)
		result.buf[c]=argp->buf[c];
	result.n = argp->n;
	return &result;
}
