#include "lcdshapes.h"
#include "lcdfonts.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>

int PANEL_SIZE = NUMBER_ROWS * NUMBER_PANELS * NUMBER_COLUMNS_PER_PANEL;
int TOTAL_NUMBER_COLUMNS = NUMBER_PANELS * NUMBER_COLUMNS_PER_PANEL;
static uint16_t count = 0;
uint8_t letters[][7] = LETTERS;

void drawPixel(int x, int y, color c, uint8_t *display){
        if(x<0 || x>=TOTAL_NUMBER_COLUMNS || y<0 || y>=NUMBER_ROWS) return; //sanity check
        int offset = y * TOTAL_NUMBER_COLUMNS + x;
        *(display + offset) = c;
}

void drawPoint(Point point, uint8_t *display){
	drawPixel(point.x, point.y, point.c, display);
}

void drawHorizontalLine(int x, int y, int width, color c, uint8_t *display){
        if(x>=TOTAL_NUMBER_COLUMNS || y<0 || y>=NUMBER_ROWS || width <=0) return; //sanity check
        int i, offset = y * TOTAL_NUMBER_COLUMNS + x;
        for(i=0;i<width;i++){
                if((offset + i) >= y*TOTAL_NUMBER_COLUMNS && (offset + i) < (y+1)*TOTAL_NUMBER_COLUMNS) // keep it in the same row
                        *(display + offset + i) = c;
        }
}

void drawVerticalLine(int x, int y, int height, color c, uint8_t *display){
        if(x<0 || x>=TOTAL_NUMBER_COLUMNS || y>=NUMBER_ROWS || height <=0) return; //sanity check
        int i, j, offset = y * TOTAL_NUMBER_COLUMNS + x;
        for(i=0;i<height;i++){
                j = offset + i * TOTAL_NUMBER_COLUMNS;
                if(j >= 0 && j < PANEL_SIZE) // safety check just in case
                        *(display + j) = c;
        }
}

/*
**  Draws a letter. Position x,y the is top left corner of the letter. Can write partial letter if x<0 or x>(TOTAL_NUMBER_COLUMNS-8)
**  Example: drawLetter('A', 0, 9, blue, canvas) draws a blue letter A at the bottom left of the Led Panel.
*/
void drawLetter( uint8_t letter, int x, int y, color c, uint8_t *display){
        if(x>=TOTAL_NUMBER_COLUMNS || y < -6 || y>=NUMBER_ROWS) return; //sanity check
        int i,j;
        uint8_t *letA = GET_ALPHA(letter);
        for(j=0;j<LETTER_HEIGHT;j++){
                int offset = (y+j) * TOTAL_NUMBER_COLUMNS + x;
                for(i=0;i<LETTER_WIDTH;i++){
                        if((letA[j] << i) & 0x80
			&& (offset + i) < PANEL_SIZE && (offset + i) >= 0 // don't write outside allocated display buffer
			&& (offset + i) >= (y+j)*TOTAL_NUMBER_COLUMNS     // make sure you don't write on previous row
			&& (offset + i) < (y+j+1)*TOTAL_NUMBER_COLUMNS )  // make sure you don't write on next row
                                *(display + offset + i) = c;
                }
        }
}

void drawLetterP( uint8_t letter, Point p, uint8_t *display){
	drawLetter(letter, p.x, p.y, p.c, display);
}

void drawSlantLine (int x, int y, bool isPositiveAngle, int length, color c, uint8_t *display){
        int i;
        for(i=0;i<length;i++){
                drawPixel(x + i,  isPositiveAngle ? (y-i): (y+i), c, display);
        }
}


void drawRectangle(int x, int y, int width, int height, color c, uint8_t *display){
        drawHorizontalLine(x, y, width, c, display);
        drawVerticalLine(x, y, height, c, display);
        drawHorizontalLine(x, y + height - 1, width, c, display);
        drawVerticalLine(x + width -1, y, height, c, display);
}


void drawBall(int x, int y, int diameter, color c,  uint8_t *display){

	if(diameter == 5){
		drawCircle(x, y, 5, c, display);
		drawRectangle(x-1, y-1, 3, 3, c, display);
		drawPixel(x, y, c, display);
	}
}

void drawCircle(int x, int y, int diameter, color c,  uint8_t *display){
	switch(diameter){
		case 5:
                	drawVerticalLine(x-2, y-1, 3, c, display);
                	drawVerticalLine(x+2, y-1, 3, c, display);
                	drawHorizontalLine(x-1, y-2, 3, c, display);
                	drawHorizontalLine(x-1, y+2, 3, c, display);
			break;
		case 7:
                	drawVerticalLine(x-3, y-2, 5, c, display);
                	drawVerticalLine(x+3, y-2, 5, c, display);
                	drawHorizontalLine(x-2, y-3, 5, c, display);
                	drawHorizontalLine(x-2, y+3, 5, c, display);
			break;
		case 9:
                	drawVerticalLine(x-4, y-2, 5, c, display);
                	drawVerticalLine(x+4, y-2, 5, c, display);
                	drawHorizontalLine(x-2, y-4, 5, c, display);
                	drawHorizontalLine(x-2, y+4, 5, c, display);
        	        drawPixel(x-3, y-3, c, display);
        	        drawPixel(x+3, y-3, c, display);
        	        drawPixel(x-3, y+3, c, display);
        	        drawPixel(x+3, y+3, c, display);
			break;
		case 11:
	                drawSlantLine (x-6, y-2, true, 5, c, display);
	                drawSlantLine (x-6, y+2, false, 5, c, display);
                	drawVerticalLine(x-6, y-2, 5, c, display);
                	drawVerticalLine(x+6, y-2, 5, c, display);
                	drawHorizontalLine(x-2, y-6, 5, c, display);
                	drawHorizontalLine(x-2, y+6, 5, c, display);
	                drawSlantLine (x+2, y+6, true, 5, c, display);
	                drawSlantLine (x+2, y-6, false, 5, c, display);
			break;
		case 15:
                	drawVerticalLine(x-7, y-2, 5, c, display);
                	drawVerticalLine(x+7, y-2, 5, c, display);
                	drawHorizontalLine(x-2, y-7, 5, c, display);
                	drawHorizontalLine(x-2, y+7, 5, c, display);
	                drawSlantLine (x-6, y-4, true, 3, c, display);
        	        drawSlantLine (x+4, y+6, true, 3, c, display);
                	drawSlantLine (x+4, y-6, false, 3, c, display);
	                drawSlantLine (x-6, y+4, false, 3, c, display);
        	        drawPixel(x-6, y-3, c, display);
                	drawPixel(x-3, y-6, c, display);
	                drawPixel(x+3, y-6, c, display);
        	        drawPixel(x+6, y-3, c, display);
                	drawPixel(x-6, y+3, c, display);
	                drawPixel(x-3, y+6, c, display);
        	        drawPixel(x+3, y+6, c, display);
                	drawPixel(x+6, y+3, c, display);
        }
}

void drawSmileyFace(int x, int y, int diameter, uint8_t *display){
	switch(diameter){
		case 15:
		        drawCircle(x, y, diameter, yellow, display);
        		//mouth
	        	drawHorizontalLine(x-2, y+4, 5, red, display);
	        	drawPixel(x-3,y+3,red, display);
		        drawPixel(x+3,y+3,red, display);
        		//eyes
		        drawHorizontalLine(x-3, y-3, 2, blue, display);
        		drawHorizontalLine(x+2, y-3, 2, blue, display);
	        	//nose
	        	drawPixel(x, y-1, green, display);
		        drawHorizontalLine(x-1, y, 3, green, display);
			break;
	}
}

void updateRows(uint8_t *displayArray){
//	static bool change_color = false;
        uint8_t *row1 = displayArray + (count%8 * TOTAL_NUMBER_COLUMNS);
        uint8_t *row2 = displayArray + ((count%8 + 8) * TOTAL_NUMBER_COLUMNS);
//        if(count%8 == 0) change_color = !change_color;
        int i;
        uint8_t val;
        for(i=0;i<TOTAL_NUMBER_COLUMNS;i++){
//		if(change_color){ // if odd
                	val = *(row1+i);
                	bcm2835_gpio_write(R1, ((val & 4)? HIGH : LOW));
	                bcm2835_gpio_write(G1, ((val & 2)? HIGH : LOW));
        	        bcm2835_gpio_write(B1, ((val & 1)? HIGH : LOW));
                	val = *(row2+i);

	                bcm2835_gpio_write(R2, ((val & 4)? HIGH : LOW));
        	        bcm2835_gpio_write(G2, ((val & 2)? HIGH : LOW));
                	bcm2835_gpio_write(B2, ((val & 1 )? HIGH : LOW));
/*		}else{ // if even
        	        val = *(row1+i);

                        bcm2835_gpio_write(R1, ((val & 32)? HIGH : LOW));
                        bcm2835_gpio_write(G1, ((val & 16)? HIGH : LOW));
                        bcm2835_gpio_write(B1, ((val & 8)? HIGH : LOW));
	                val = *(row2+i);
                        bcm2835_gpio_write(R2, ((val & 32)? HIGH : LOW));
                        bcm2835_gpio_write(G2, ((val & 16)? HIGH : LOW));
                        bcm2835_gpio_write(B2, ((val & 8 )? HIGH : LOW));
		}*/
                toggleClock(); // negative edge clock pulse
        }
	displayRowEnd();
	count++;
}

int gpio_init(){

        if (!bcm2835_init())
                return 1;

        // Set the pin to be an output
        bcm2835_gpio_fsel(AA, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_fsel(BB, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_fsel(CC, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_fsel(R1, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_fsel(G1, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_fsel(B1, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_fsel(R2, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_fsel(G2, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_fsel(B2, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_fsel(CLK, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_fsel(OE, BCM2835_GPIO_FSEL_OUTP);
        bcm2835_gpio_fsel(LAT, BCM2835_GPIO_FSEL_OUTP);

        bcm2835_gpio_write(R1, LOW);
        bcm2835_gpio_write(B1, LOW);
        bcm2835_gpio_write(G1, LOW);
        bcm2835_gpio_write(R2, LOW);
        bcm2835_gpio_write(B2, LOW);
        bcm2835_gpio_write(G2, LOW);

        bcm2835_gpio_write(CLK, HIGH);
        bcm2835_gpio_write(LAT, LOW);

        return 0;
}

void toggleClock(){
        bcm2835_gpio_write(CLK, LOW);
        bcm2835_gpio_write(CLK, HIGH);
        //delay(1);
}

void displayRowInit(){
        bcm2835_gpio_write(OE, HIGH); //disable output with a high value
	uint8_t a, b, c;
        a = (count & 1)? HIGH : LOW; // change the row
        b = (count & 2)? HIGH : LOW;
        c = (count & 4)? HIGH : LOW;
        bcm2835_gpio_write(AA, a);
        bcm2835_gpio_write(BB, b);
        bcm2835_gpio_write(CC, c);
}

static void displayRowEnd(){
        // once all bits are done shifting, this LAT control transfers the data bits to the LED drivers (a la D-FlipFlop)
        bcm2835_gpio_write(LAT, HIGH);
        bcm2835_gpio_write(LAT, LOW);

        bcm2835_gpio_write(OE, LOW); //enable output

        // give it a little time to display
        delay(1);
}

// couple of timing functions
long int getTimeDiff(struct timeval a, struct timeval b){
        long int before = b.tv_sec * 1000000 + b.tv_usec;
        long int after  = a.tv_sec * 1000000 + a.tv_usec;
        return (after - before) / 1000; //in milliseconds
}

void timevalCopy(struct timeval *dest, struct timeval *source){
        memcpy (dest, source, sizeof (struct timeval));
}

