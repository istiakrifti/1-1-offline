#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "utils.h"

#define RGB 255


Image *img;

Image *read_PPM(char *filename)
{
    /* opens a PPM file, constructs an Image object and returns a pointer to it.
    Use fopen(), fscanf(), fprintf(), and fclose().*/
    FILE *fp;

    char s[10],line[80];
    int rgb,i,j;

    img=(Image *)malloc(sizeof(Image));
    fp=fopen(filename,"r");
    fgets(s,10,fp);

    fgets(line,80,fp);
    sscanf(line,"%d %d",&img->cols,&img->rows);

    fscanf(fp,"%d",&rgb);
    img->image=(Color **)malloc(img->rows*sizeof(Color *));
    for(i=0; i<img->rows; i++)
    {

        img->image[i]=(Color *)malloc(img->cols*sizeof(Color));
    }
    for(i=0; i<img->rows; i++)
    {
        for(j=0; j<img->cols; j++)
        {
            Color p;
            fscanf(fp,"%d %d %d",&p.R,&p.G,&p.B);
            img->image[i][j]=p;
        }
    }

    fclose(fp);

    return img;

}

void write_PPM(Image *image, char *filename)
{
    /* takes an Image object and writes to filename in PPM format.*/
    FILE *fp;
    int i,j;

    fp = fopen(filename, "w");
    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n",img->cols,img->rows);
    fprintf(fp, "%d\n",RGB);
    for(i=0; i<img->rows; i++)
    {
        for(j=0; j<img->cols; j++)
        {

            fprintf(fp,"%3d %3d %3d   ",img->image[i][j].R,img->image[i][j].G,img->image[i][j].B);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}

void free_image(Image *image)
{
    /* takes an Image object and frees all the memory associated with it.
    This involves not only calling free on image but also on the appropriate
    members of it.
    */
    int i;
    for(i=0; i<img->rows; i++)
    {
        free(img->image[i]);
    }
    free(img->image);
}


Color *evaluate_one_pixel(Image *image, int row, int col)
{
    /* Takes an Image object and returns what color the pixel at the given row/col
    should be in the secret image. This function should not change image*/
    Color *y;
    y=(Color*)malloc(sizeof(Color));

    y->R=image->image[row][col].R;
    y->G=image->image[row][col].G;
    y->B=image->image[row][col].B;

    if((y->B)%2==0)
    {
        y->R=0;
        y->G=0;
        y->B=0;
    }
    else
    {
        y->R=255;
        y->G=255;
        y->B=255;
    }

    return y;
}

Image *get_secret_image(Image *image)
{
    /* takes an Image object, and constructs the secret image from it by extracting
    the LSB of the B channel. You should call evaluate_one_pixel() here. */
    int i,j;
    for(i=0; i<image->rows; i++)
    {
        for(j=0; j<image->cols; j++)
        {
            Color *z;
            z=evaluate_one_pixel(image,i,j);
            image->image[i][j]=*z;
        }
    }
    return image;

}

int main()
{
    /* Call read_PPM(), write_PPM(), free_image(), get_secret_image() in some order
    to obtain the hidden message.*/
    //char filename[]="DennisRitchie.ppm";
    Image *x,*p;
    char filename[]="DennisRitchie.ppm",filename1[]="secret message.ppm";
    x=read_PPM(filename);
    p=get_secret_image(x);
    write_PPM(p,filename1);
    free_image(p);

    return 0;
}


