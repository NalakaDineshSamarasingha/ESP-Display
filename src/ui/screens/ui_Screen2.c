// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: Bun & Run_New

#include "ui.h"
#include <stdio.h>


// Declare labels for displaying arrays
lv_obj_t *dine_label;
lv_obj_t *takeaway_label;

void update_labels() {
    char dine_str[32];
    char takeaway_str[32];
    
    snprintf(dine_str, sizeof(dine_str), "Dine: %d, %d, %d", dine[0], dine[1], dine[2]);
    snprintf(takeaway_str, sizeof(takeaway_str), "Takeaway: %d, %d, %d", takeaway[0], takeaway[1], takeaway[2]);
    
    lv_label_set_text(dine_label, dine_str);
    lv_label_set_text(takeaway_label, takeaway_str);
    updateQr();
    update_labels2();
}

void dropdown_event_handler(lv_event_t * e)
{
    lv_obj_t * dropdown = lv_event_get_target(e);
    int index = (int)lv_event_get_user_data(e);
    
    uint16_t selected = lv_dropdown_get_selected(dropdown);
    char buffer[4];
    lv_dropdown_get_selected_str(dropdown, buffer, sizeof(buffer));
    
    // Update the corresponding array
    if (index < 3) {
        dine[index] = atoi(buffer);  // Convert selected string to integer
    } else {
        takeaway[index - 3] = atoi(buffer);  // Convert selected string to integer
    }
    
    // Update the labels
    update_labels();
}

void ui_Screen2_screen_init(void)
{
    ui_Screen2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container2 = lv_obj_create(ui_Screen2);
    lv_obj_remove_style_all(ui_Container2);
    lv_obj_set_width(ui_Container2, 803);
    lv_obj_set_height(ui_Container2, 500);
    lv_obj_set_x(ui_Container2, 0);
    lv_obj_set_y(ui_Container2, 1);
    lv_obj_set_align(ui_Container2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Container2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Container2, lv_color_hex(0xCD6D18), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Container2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Container2, lv_color_hex(0xCD6D18), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Container2, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    // Create the labels for arrays
    dine_label = lv_label_create(ui_Screen2);
    lv_obj_set_width(dine_label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(dine_label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(dine_label, 0);
    lv_obj_set_y(dine_label, 200);
    lv_obj_set_align(dine_label, LV_ALIGN_CENTER);
    lv_label_set_text(dine_label, "Dine: 0, 0, 0");
    lv_obj_set_style_text_color(dine_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(dine_label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    takeaway_label = lv_label_create(ui_Screen2);
    lv_obj_set_width(takeaway_label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(takeaway_label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(takeaway_label, 0);
    lv_obj_set_y(takeaway_label, 220);
    lv_obj_set_align(takeaway_label, LV_ALIGN_CENTER);
    lv_label_set_text(takeaway_label, "Takeaway: 0, 0, 0");
    lv_obj_set_style_text_color(takeaway_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(takeaway_label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label7 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label7, -6);
    lv_obj_set_y(ui_Label7, -184);
    lv_obj_set_align(ui_Label7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label7, "BUN & RUN");
    lv_obj_set_style_text_color(ui_Label7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(ui_Label7, &lv_font_montserrat_42, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label8 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label8, -6);
    lv_obj_set_y(ui_Label8, -153);
    lv_obj_set_align(ui_Label8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label8, "WHEREVER YOU GO");
    lv_obj_set_style_text_color(ui_Label8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_Label8, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Label8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label8, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label9 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label9, -251);
    lv_obj_set_y(ui_Label9, -84);
    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label9, "Food Item");
    lv_obj_set_style_text_color(ui_Label9, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(ui_Label9, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, -1);
    lv_obj_set_y(ui_Label1, -83);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "Dine");
    lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, 225);
    lv_obj_set_y(ui_Label3, -84);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "Take Away");
    lv_obj_set_style_text_color(ui_Label3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(ui_Label3, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label10 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label10, -250);
    lv_obj_set_y(ui_Label10, -16);
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text_fmt(ui_Label10, "Gal Banis(Rs.%d)",GalBanis);
    lv_obj_set_style_text_color(ui_Label10, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(ui_Label10, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, -251);
    lv_obj_set_y(ui_Label2, 33);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text_fmt(ui_Label2, "Cream Bun(Rs.%d)",CreamBun);
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(ui_Label2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label4 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, -252);
    lv_obj_set_y(ui_Label4, 83);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text_fmt(ui_Label4, "Fish Bun(Rs.%d)",FishBun);
    lv_obj_set_style_text_color(ui_Label4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(ui_Label4, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Dropdown1 = lv_dropdown_create(ui_Screen2);
    lv_dropdown_set_options(ui_Dropdown1, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10");
    lv_obj_set_width(ui_Dropdown1, 100);
    lv_obj_set_height(ui_Dropdown1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Dropdown1, -1);
    lv_obj_set_y(ui_Dropdown1, -19);
    lv_obj_set_align(ui_Dropdown1, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_Dropdown1, dropdown_event_handler, LV_EVENT_VALUE_CHANGED, (void *)0);
    lv_obj_set_style_text_color(ui_Dropdown1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Dropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Dropdown1, lv_color_hex(0xA66506), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Dropdown1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Dropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dropdown1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Dropdown2 = lv_dropdown_create(ui_Screen2);
    lv_dropdown_set_options(ui_Dropdown2, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10");
    lv_obj_set_width(ui_Dropdown2, 100);
    lv_obj_set_height(ui_Dropdown2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Dropdown2, -1);
    lv_obj_set_y(ui_Dropdown2, 31);
    lv_obj_set_align(ui_Dropdown2, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_Dropdown2, dropdown_event_handler, LV_EVENT_VALUE_CHANGED, (void *)1);
    lv_obj_set_style_text_color(ui_Dropdown2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Dropdown2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Dropdown2, lv_color_hex(0xA66506), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dropdown2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Dropdown2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Dropdown2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dropdown2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Dropdown3 = lv_dropdown_create(ui_Screen2);
    lv_dropdown_set_options(ui_Dropdown3, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10");
    lv_obj_set_width(ui_Dropdown3, 100);
    lv_obj_set_height(ui_Dropdown3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Dropdown3, -1);
    lv_obj_set_y(ui_Dropdown3, 82);
    lv_obj_set_align(ui_Dropdown3, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_Dropdown3, dropdown_event_handler, LV_EVENT_VALUE_CHANGED, (void *)2);
    lv_obj_set_style_text_color(ui_Dropdown3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Dropdown3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Dropdown3, lv_color_hex(0xA66506), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dropdown3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Dropdown3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Dropdown3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dropdown3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Dropdown4 = lv_dropdown_create(ui_Screen2);
    lv_dropdown_set_options(ui_Dropdown4, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10");
    lv_obj_set_width(ui_Dropdown4, 100);
    lv_obj_set_height(ui_Dropdown4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Dropdown4, 228);
    lv_obj_set_y(ui_Dropdown4, -18);
    lv_obj_set_align(ui_Dropdown4, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_Dropdown4, dropdown_event_handler, LV_EVENT_VALUE_CHANGED, (void *)3);
    lv_obj_set_style_text_color(ui_Dropdown4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Dropdown4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Dropdown4, lv_color_hex(0xA66506), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dropdown4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Dropdown4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Dropdown4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dropdown4, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Dropdown5 = lv_dropdown_create(ui_Screen2);
    lv_dropdown_set_options(ui_Dropdown5, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10");
    lv_obj_set_width(ui_Dropdown5, 100);
    lv_obj_set_height(ui_Dropdown5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Dropdown5, 229);
    lv_obj_set_y(ui_Dropdown5, 32);
    lv_obj_set_align(ui_Dropdown5, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_Dropdown5, dropdown_event_handler, LV_EVENT_VALUE_CHANGED, (void *)4);
    lv_obj_set_style_text_color(ui_Dropdown5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Dropdown5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Dropdown5, lv_color_hex(0xA66506), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dropdown5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Dropdown5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Dropdown5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dropdown5, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Dropdown6 = lv_dropdown_create(ui_Screen2);
    lv_dropdown_set_options(ui_Dropdown6, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10");
    lv_obj_set_width(ui_Dropdown6, 100);
    lv_obj_set_height(ui_Dropdown6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Dropdown6, 229);
    lv_obj_set_y(ui_Dropdown6, 80);
    lv_obj_set_align(ui_Dropdown6, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_Dropdown6, dropdown_event_handler, LV_EVENT_VALUE_CHANGED, (void *)5);
    lv_obj_set_style_text_color(ui_Dropdown6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Dropdown6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Dropdown6, lv_color_hex(0xA66506), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dropdown6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Dropdown6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Dropdown6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dropdown6, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button2 = lv_btn_create(ui_Screen2);
    lv_obj_set_width(ui_Button2, 193);
    lv_obj_set_height(ui_Button2, 50);
    lv_obj_set_x(ui_Button2, 213);
    lv_obj_set_y(ui_Button2, 167);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel1 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel1, 653);
    lv_obj_set_height(ui_Panel1, 1);
    lv_obj_set_x(ui_Panel1, -2);
    lv_obj_set_y(ui_Panel1, -56);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel2 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel2, 653);
    lv_obj_set_height(ui_Panel2, 1);
    lv_obj_set_x(ui_Panel2, -3);
    lv_obj_set_y(ui_Panel2, -114);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label12 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label12, 213);
    lv_obj_set_y(ui_Label12, 167);
    lv_obj_set_align(ui_Label12, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label12, "CONFIRM");
    lv_obj_set_style_text_color(ui_Label12, lv_color_hex(0xCD6D18), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(ui_Label12, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label13 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label13, 700);
    lv_obj_set_y(ui_Label13, -88);
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label13, "BUN &  RUN");
    lv_obj_set_style_text_color(ui_Label13, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(ui_Label13, &lv_font_montserrat_42, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label14 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_Label14, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label14, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label14, 700);
    lv_obj_set_y(ui_Label14, -88);
    lv_obj_set_align(ui_Label14, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label14, "BUN &  RUN");
    lv_obj_set_style_text_color(ui_Label14, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(ui_Label14, &lv_font_montserrat_42, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_CLICKED, NULL);
}

