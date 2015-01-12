#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {

FILE* fp;
char c1, c2;
int width, height;
int maxval;
int i,j;

unsigned char *ref_im, *out_im;
char equal = 1;
int nrdiff=0, nrdiff1=0, nrdiff2=0, nrdiff3=0;

if ((fp = fopen("ref.ppm", "rb")) != NULL) {
   fscanf (fp, "%c%c%d%d%d", &c1, &c2, &width, &height, &maxval);
   ref_im = (unsigned char*) malloc(sizeof(unsigned char)*width*height*3);
   fread(ref_im, sizeof(unsigned char), width*height*3, fp);
   fclose(fp);
}

printf("%c%c\n",c1,c2);
printf("%d %d\n", width, height);
printf("%d\n", maxval);

if ((fp = fopen("out.ppm", "rb")) != NULL) {
   fscanf (fp, "%c%c%d%d%d", &c1, &c2, &width, &height, &maxval);
   out_im = (unsigned char*) malloc(sizeof(unsigned char)*width*height*3);
   fread(out_im, sizeof(unsigned char), width*height*3, fp);
   fclose(fp);
}

printf("%c%c\n",c1,c2);
printf("%d %d\n", width, height);
printf("%d\n", maxval);

for (i=0; i < (height); i++) {
   for (j=0; j < (3*width); j++) {
      int rv = *ref_im++;
      int ov = *out_im++;
      int diff = rv-ov;
      if (diff != 0) {
         if (diff < 0) diff = -diff;
         equal = 0;
         if (diff == 1) nrdiff1++;
         if (diff == 2) nrdiff2++;
         if (diff == 3) nrdiff3++;
         nrdiff++;
      }
   }
}

if (equal)
   printf ("Images are equal.\n");
else {
   printf ("%d values are different\n", nrdiff);
   printf ("%d values differ by 1\n", nrdiff1);
   printf ("%d values differ by 2\n", nrdiff2);
   printf ("%d values differ by 3\n", nrdiff3);
}

return 0;
}