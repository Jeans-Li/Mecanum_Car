
/*************************************************************************************
 *
 *  gui.c
 *
 *************************************************************************************/


#include "bsp_u8g2.h"
#include "main.h"


int16_t offset;				// current offset for the scrolling text
u8g2_uint_t width;			// pixel width of the scrolling text (must be lesser than 128 unless U8G2_16BIT is defined
const char *text = "U8g2";	// scroll this text from right to left

const uint8_t tile_area_x_pos = 1;	// Update area left position (in tiles)
const uint8_t tile_area_y_pos = 2;	// Update area upper position (distance from top in tiles)
const uint8_t tile_area_width = 14;
const uint8_t tile_area_height =5;	// this will allow cour18 chars to fit into the area

const u8g2_uint_t pixel_area_x_pos = tile_area_x_pos*8;
const u8g2_uint_t pixel_area_y_pos = tile_area_y_pos*8;
const u8g2_uint_t pixel_area_width = tile_area_width*8;
const u8g2_uint_t pixel_area_height = tile_area_height*8;

void gui_init(void) {
  u8g2_init();
    
  u8g2_ClearBuffer(&u8g2);					// clear the internal memory
  u8g2_SetFont(&u8g2,u8g2_font_helvR10_tr);	// choose a suitable font
//  u8g2_DrawStr(&u8g2,0,12,"UpdateDisplayArea");	// write something to the internal memory
  
  // draw a frame, only the content within the frame will be updated
  // the frame is never drawn again, but will stay on the display
  u8g2_DrawBox(&u8g2,pixel_area_x_pos-1, pixel_area_y_pos-1, pixel_area_width+2, pixel_area_height+2);
  
  u8g2_SendBuffer(&u8g2);					// transfer internal memory to the display
  
  u8g2_SetFont(&u8g2,u8g2_font_courB18_tr);	// set the target font for the text width calculation
  width = u8g2_GetUTF8Width(&u8g2,text);		// calculate the pixel width of the text
  offset = width+pixel_area_width;
  

}

void gui_update(void) {
  u8g2_ClearBuffer(&u8g2);						// clear the complete internal memory

  // draw the scrolling text at current offset
  u8g2_SetFont(&u8g2,u8g2_font_courB14_tr);		// set the target font
//  u8g2_DrawUTF8(&u8g2,
//    pixel_area_x_pos-width+offset,
//    pixel_area_y_pos+pixel_area_height+u8g2_GetDescent(&u8g2)-1,
//    text);								// draw the scolling text

  u8g2_DrawUTF8(&u8g2,
    pixel_area_x_pos-width+62,
    pixel_area_y_pos+pixel_area_height+u8g2_GetDescent(&u8g2)-1,
    "hello world");

//  u8g2_DrawStr(&u8g2, 2, 15, "hello world");
  // now only update the selected area, the rest of the display content is not changed
  u8g2_UpdateDisplayArea(&u8g2,tile_area_x_pos, tile_area_y_pos, tile_area_width, tile_area_height);
      
  offset--;								// scroll by one pixel
  if ( offset == 0 )	
    offset = width+pixel_area_width;			// start over again
    
  HAL_Delay(10);							// do some small delay
}
