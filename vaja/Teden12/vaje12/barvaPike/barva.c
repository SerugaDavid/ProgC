#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
     unsigned char red,green,blue;
} PPMPixel;

typedef struct {
     int x, y;
     PPMPixel *data;
} PPMImage;


static PPMImage *readPPM(const char *filename)
{
    char buff[16];
    PPMImage *img;
    FILE *fp;
    int c, rgb_comp_color;

    //open PPM file for reading
    fp = fopen(filename, "rb");

    //read image format
    //to ti prebere P6
    fgets(buff, sizeof(buff), fp);

    //alloc memory form image
    //naredi novo sliko
    img = (PPMImage *)malloc(sizeof(PPMImage));

    //read image size information
    //prebere sirino in visino
    fscanf(fp, "%d %d", &img->x, &img->y);

    //read rgb component
    //prebere, kuk je max velikost
    fscanf(fp, "%d", &rgb_comp_color);

    while (fgetc(fp) != '\n') ;
    //memory allocation for pixel data
    img->data = (PPMPixel*)malloc(img->x * img->y * sizeof(PPMPixel));

    //read pixel data from file
    fread(img->data, 3 * img->x, img->y, fp);

    fclose(fp);
    return img;
}


int main(int argc, char ** argv) {
    char * datoteka = argv[1];
    int vrstica, stolpec;
    sscanf(argv[2], "%d", &vrstica);
    sscanf(argv[3], "%d", &stolpec);

    // dobimo sliko
    PPMImage * slika = readPPM(datoteka);

    int red;
    int green;
    int blue;
    
    // zracunamo index
    int pixel_index = vrstica * slika->x + stolpec;

    // dobimo piksel
    red = slika->data[pixel_index].red;
    green = slika->data[pixel_index].green;
    blue = slika->data[pixel_index].blue;
    
    // izpisemo rezultat
    printf("%d %d %d\n", red, green, blue);
    
    return 0;
}
