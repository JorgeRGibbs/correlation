#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Ramírez Gibbs Jorge Alberto
//BAUTISTA BARROSO LUIS ALBERTO

int main(){

	int auto_c = 0;
	int x = 0, y = 0,h = 0,g = 0,a = 0;
	FILE * xdata;
	FILE * hdata;

	xdata = fopen("xdata.dat","w");
	hdata = fopen("hdata.dat","w");

	printf("Size of x1:\n");
	scanf("%d",&x);
	printf("Size of x2:\n");
	scanf("%d",&h);
	int idx,idh;
	int size = h+x-1;
	int sz;
	if (x > h){
		sz  = x;
		printf("x\n");
	} else{
		sz = h;
		printf("h\n");
	}

	printf("X Index:\n");
	scanf("%d",&idx);
	printf("H Index:\n");
	scanf("%d",&idh);

	int xarray[x];
	int harray[h];
	
	for (int i = 0; i < sz +1; i++)
	{
		xarray[i] = 0;
		harray[i] = 0;
	}
	
    fprintf (xdata, "%d %d %d \n",0 - idx,0 - idx,0);
    fprintf (xdata, "%d %d %d \n",x-idx+1,x-idx+1,0);
	fprintf (hdata, "%d %d %d \n",0 - idh,0 - idh,0);
    fprintf (hdata, "%d %d %d \n",h-idh+1,h-idh+1,0);
	
	for(int i=0;i<x;i++){
		printf("\n x[%d]",i-idx+1);
		scanf("%d",&y);
        fprintf (xdata, "%d %d %d \n",i - idx + 1 ,i - idx + 1 , y);
	    //fprintf (xdata, "%d %d %d \n",0 - idx,0 - idx,0);
		xarray[i] = y;
	}
	
	int shift_array[sz]; //= (int*) malloc(h * sizeof(int));
	int rarray[size]; //= (int*) malloc((h+x-1) * sizeof(int));
	int sum; //[h+x-1];
	
	//if (auto_c = 0){
		for(int i=0;i<h;i++){
			printf("\nh[%d]",i-idh+1);
			scanf("%d",&g);
			harray[i] = g;
	        fprintf (hdata, "%d %d %d \n",i - idh +1 ,i - idh +1 , g);

		}

		/*for (int s = 0; s < sz; s++)
		{
			printf("h[%d]: %d\n",s,harray[s] );
			printf("x[%d]: %d\n",s,xarray[s] );
		}*/

	/*	}
	} else{
		for (int i = 0; i < x; i++)
		{
			harray[i] = xarray[i];
		}
	}
	*/

	int l,k; 
	printf("opening file ...\n");
	FILE * fp;
	fp = fopen("data.dat","w");
	//printf("%d\n",&fp );
	printf("File opened \n");
    fprintf (fp, "%d %d %d \n",0,0,0);
	for (k = 0 ; k < sz ; k++)
	{	
		int temp = harray[0];
		a = 0;
		/*for (int s = 0; s < sz; s++)
		{
			printf("h[%d]: %d\n",s,harray[s] );
			printf("x[%d]: %d\n",s,xarray[s] );
		}*/
		for (int i = 0; i < sz; i++)
		{
			a += harray[i] * xarray[i] ;
			//printf("a: %d\n",a );
		}
		rarray[k] = a;
		printf("r[%d]: %d\n",k - idx + 1 ,rarray[k]);
        fprintf (fp, "%d %d %d \n",k - idx + 1 ,k - idx + 1 ,rarray[k]);
		//harray = shift(harray,size,1,idx);
		for (l = 0; l < sz -1; l++){ 
		harray[l] = harray[l + 1];
		} 
		harray[l] = temp; 

	} 
    fprintf (fp, "%d %d %d \n",0 - idx,0 - idx,0);
    fprintf (fp, "%d %d %d \n",size-idx+1,size-idx+1,0);
 	//system("gnuplot commands.txt");
    //system("eog graph.png &> /dev/null");
   //int* freer = rarray;

   //free(freex);
   //free(freeh);
   //free(freer);
   fclose(fp);
   fclose(xdata);
   fclose(hdata);
}


