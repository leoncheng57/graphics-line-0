#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
/*************************************/
/* *_Algorithm_* (Octant 1)	     */
/*   (x_o, y_o) -> (x_1, y_1)  	     */
/*   x=x_o, y=y_o		     */
/*   A = y_1 - y_o, B = -(x_1 - x_o) */
/*   d = 2A + B			     */
/*   while(x \leq x_1)		     */
/*     plot (x, y)		     */
/*     if (d>0)			     */
/*       y+=1			     */
/*       d+=2B			     */
/*     x+=1			     */
/*     d+=2A			     */
/*************************************/
  
  int x, y, A, B, d, m;  
  
  if (!(x1>x0)) return;

  //OCTANT I
  m = (y1-y0)/(x1-x0); if (!(m <= 1 && m >= 0)) return;
  x = x0; y = y0;
  A = y1-y0; B = -(x1-x0);
  d = 2*A + B;
  while(x <= x1){
    plot(s, c, x, y);
    if (d>0){
      y+=1;
      d+=2*B;
    }
    x+=1;
    d+=2*A;
  }
  
  //OCTANT II
  m = (y1-y0)/(x1-x0); 
  if (!(m >= 1)) return;
  x = x0;
  y = y0;
  A = y1-y0;
  B = -(x1-x0);
  d = A+2*B;
  while(y <= y1){
    plot(s,c,x,y);
    if (d<0){
      x+=1;
      d+=2*A;
    }
    y+=1;
    d+=2*B;
  }

}
