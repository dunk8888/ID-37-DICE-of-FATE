#ifndef MENU_H
#define MENU_H

#include "inputs.h"
#include "game.h"


const unsigned char PROGMEM TEAMarg[] = //128,48
{
  //         ########                                                                                       ########
  //         ###########                                                                                   ##      ##
  //         ####    ##################                                                                   ##  #### ###
  //         #### ##    ################ ####################           #############         ######     ##  ##  # ####
  //         #### #####                #######################       ##################      ########   ##  ###  # #####
  //         #### ##  ######  ######## ##                   ###     ####            ####     ##     ## ##  ####### #  ###
  // ####### ####  #  ####### #####  #  # #################  ##    ###   ##########   ###   ##  ###  ###  ###  ### #   ### ##########
  //         ##### ##########  ####  ## #  ################# ##   ###  ##############   ##  ## #####  #  ###    ## ##  ###
  //         ##### ########### ######## #   ################  #   ##  #################  ####  ######   ####    ## ########
  // ##### # #####             ########     ################# #  ##  #######    ######## #### ######## ######  ### ########  # # ####
  // #  #    ###### ####################    ################# #  ## #######      #######  ##  #################### ########      #  #
  // #  # #  ###### ####################     #######          # ##  ######       ####  ## ## #################  ## ######## # #  #  #
  // ####    ######  #  ################     ##############   # ## #######       ####  ## #  #################  ## ########      ####
  // ####  # ####### #  #################  # ##############   ###  ######       ######### # ###################### ########  # # ####
  // ####    ####### ####################  # ###############  ### #######       ########    #####################  ########      ####
  // #### #   ######        #########      # ###############  ##  ######       #########   ###################### ######### # #  ####
  // ####     #####          ########     ##  ############## ### ######################    ###################### #########     #####
  // ##### #  #####          #########    ### ########        #  ######################   ####################### ########   #  #####
  // #####     ###            ########    ### ###############   ######################    ####################### ########      #####
  // ###### #  ###         #  #########  #### ################  #######      #########   ######## ############### ########  # # #####
  // ######    ##          #   ########  ####  ################  ######      ########    #######  ############### ########      #####
  // ####### #  #         ###  ######### ##### ################# #####       ########   ########   ###### ####### ######## # # ######
  // #######    #         ###   ########  #### #  ############## #####      ########    #######    #####  ####### ########     ######
  // ######## # ######## #####  ##  ##### #### #  ########                  ###  ###    #######     ###   ######  ########  #  ######
  // ########          # #####   #  ##### #### #####             #         ####  ##                 ##    ###  # #########     ######
  // #  ###### # # # # ########  #####    ####                ## #         ########           ##          ###  # ######### # # ###  #
  // #  ######          #######           ####                ## #     ###                     #            #### #########     ###  #
  // ########## # # # # #########         # ##                   #     ###             ##      ##             ## #########  # #######
  //                    ########         ## ##                   #    ####             ##       #                ########
  //         ###         #######         #  ##              ######    ####            ####      ##  #    #       ########
  // ######### ######    ######         ##   #       #####################            # ##       #  ##  ####      #######   #########
  //       ##   ##       ######         #    ################            ############## ######################     ######
  //      ##     ##   ## #####         ## ## #########                   ############    #######################    #####
  //     ## ##    ##  ##  ####         #  ##                                                  ##     #############   #### ##
  //     #  ##     #      ###         ##          ########    ##########      #########       ##     ##### #########  ### ##
  //     ##       ##      ###     #####          ##########   ###########    ###########           ######      ##########
  //      ##   # ##       #############         ############  ############   ###########          ####            #######   ###
  //       ##   ##   ###  ########  ####        ############  #####  #####  #####   ####       ## ####    ###               # #
  //        ## ##    # #            ####        #####   ####  #####   ####  ####               ##  ##     # #               ###
  //         ###     ###             ##         #####   ####  #####   ###   ####   ######                 ###
  //                                            ############  ##########    #####  ######
  //                                            ###########      ########      ########
  //                                            ########### #### ## ##### #### ######## ####
  //                                            #####   ### #  # ##  #### #  # ######## #  #
  //                                            #####   ### #### ##   ### #### ######## ####
  //
  //
  //
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x83, 0x3B, 0xFB, 0x93, 0x96, 0xF6, 0xE6, 0xEC, 0xEC, 0xEC, 0xEC, 0xCC, 0x0C, 0x6C, 0xEC, 0xEC, 0xEC, 0xEC, 0x2C, 0x2C, 0xEC, 0x8C, 0x38, 0xF0, 0x18, 0x58, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0x98, 0x38, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x70, 0x30, 0xB0, 0x98, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0xD8, 0x98, 0xB8, 0x30, 0x70, 0x60, 0xC0, 0x80, 0x00, 0x00, 0xC0, 0xF0, 0x38, 0x98, 0xD8, 0xD8, 0xD8, 0x98, 0x30, 0x60, 0xC0, 0x60, 0x30, 0x98, 0xCC, 0xE6, 0x73, 0x39, 0x3D, 0x65, 0xE5, 0xFD, 0x01, 0xFF, 0x9E, 0x1C, 0x38, 0xF0, 0xE0, 0xC0, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
  0xFE, 0xF2, 0xF2, 0xFE, 0x02, 0x88, 0x22, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xE1, 0x0D, 0x7D, 0x4D, 0x4D, 0x7D, 0x7D, 0x7D, 0x7D, 0xFD, 0xFD, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7C, 0x61, 0x00, 0x00, 0xE0, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xC7, 0x06, 0x00, 0xFF, 0xE0, 0x78, 0x1E, 0xC7, 0xF1, 0xFC, 0xFE, 0xFF, 0xFF, 0x7F, 0x1F, 0x07, 0x03, 0x01, 0x01, 0x01, 0x81, 0xE3, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xE7, 0xFE, 0x38, 0x03, 0x3F, 0x8F, 0xE3, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xE4, 0xE6, 0xFF, 0x3F, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x88, 0x22, 0x88, 0x22, 0x00, 0xFE, 0xF2, 0xF2, 0xFE,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xE2, 0x88, 0x20, 0x83, 0x1F, 0xFF, 0x8F, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x80, 0xE0, 0xF8, 0xE0, 0x83, 0x0F, 0x3F, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFE, 0xF8, 0xE0, 0x80, 0x38, 0xFF, 0xFF, 0xFE, 0xE0, 0x0F, 0xFF, 0x3F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xFD, 0xFD, 0xFD, 0x7D, 0x7D, 0x7C, 0x79, 0x73, 0x61, 0x0C, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x1F, 0x07, 0x07, 0x07, 0x07, 0x07, 0xC7, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0x3F, 0x0F, 0x03, 0x00, 0xE0, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x0F, 0x07, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x20, 0x88, 0x22, 0x08, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x4F, 0x49, 0x49, 0x4F, 0x4F, 0x4F, 0xCF, 0xCF, 0x6E, 0x28, 0x62, 0xC8, 0xC2, 0x48, 0x42, 0x48, 0x02, 0x08, 0x03, 0x1E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x38, 0x08, 0x03, 0x02, 0x02, 0x03, 0x03, 0x01, 0x01, 0xC1, 0x70, 0x1F, 0x07, 0x3F, 0xFF, 0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0x60, 0x66, 0x66, 0x60, 0x7F, 0x40, 0x40, 0x40, 0x40, 0x70, 0x7C, 0x7C, 0xFC, 0x80, 0x83, 0x83, 0x83, 0x83, 0x82, 0x82, 0x83, 0x83, 0x80, 0x80, 0x80, 0xE0, 0x38, 0xF8, 0xE0, 0x80, 0x80, 0x80, 0x80, 0x82, 0x8E, 0xB8, 0xE0, 0x80, 0x80, 0xE1, 0xC1, 0x80, 0x80, 0xC0, 0xE0, 0xC3, 0xC3, 0x87, 0x84, 0x0C, 0x0F, 0x00, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x00, 0x02, 0x48, 0x42, 0x48, 0x4F, 0x4F, 0x4F, 0x49, 0x49, 0x4F,
  0x00, 0x00, 0x00, 0x00, 0x0E, 0x1B, 0x31, 0x66, 0xC6, 0x80, 0xD0, 0x60, 0x31, 0x1B, 0x0E, 0x00, 0xE0, 0xA3, 0xE3, 0x00, 0x01, 0x3F, 0x3F, 0x3F, 0x33, 0x30, 0x30, 0x30, 0x30, 0x18, 0x18, 0x78, 0xF8, 0xFC, 0x67, 0x01, 0x00, 0x03, 0x03, 0x00, 0x01, 0x01, 0x01, 0xF1, 0xF9, 0xFD, 0xFD, 0xFD, 0x3D, 0x3C, 0x3C, 0xFC, 0xFC, 0xF8, 0xF0, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x1C, 0x1C, 0x3C, 0xFC, 0xFC, 0xF8, 0x71, 0x01, 0x01, 0xE1, 0xF9, 0xFD, 0xFD, 0x3D, 0x1D, 0x1D, 0x9D, 0xBD, 0xBC, 0xBC, 0xB8, 0x80, 0x01, 0x01, 0x01, 0x01, 0x01, 0x07, 0x67, 0x61, 0x01, 0x31, 0x79, 0x79, 0x3F, 0x0F, 0x0F, 0x0F, 0x07, 0xE3, 0xA7, 0xE7, 0x07, 0x07, 0x0F, 0x0E, 0x0E, 0x1C, 0x1C, 0x19, 0x1B, 0x1F, 0x1F, 0x1F, 0x00, 0x06, 0x06, 0x70, 0x50, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x07, 0x07, 0x07, 0x1F, 0x1F, 0x1F, 0x01, 0x1C, 0x14, 0x15, 0x1D, 0x01, 0x1F, 0x1F, 0x03, 0x07, 0x0F, 0x1F, 0x1F, 0x1E, 0x00, 0x1C, 0x14, 0x15, 0x1D, 0x01, 0x1F, 0x1F, 0x1E, 0x1E, 0x1F, 0x1F, 0x1F, 0x1F, 0x01, 0x1D, 0x14, 0x14, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

PROGMEM const unsigned char titleScreen[] = {
  // width, height 128, 64,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xE0, 0x70, 0x70, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x70, 0x70, 0xE0, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0xA0, 0x50, 0xA8, 0x54, 0xAA, 0x54, 0xAA, 0x55, 0xAA, 0x55, 0x2A, 0x55, 0x2A, 0x55, 0x2A, 0x55, 0x2A, 0x55, 0x2A, 0x55, 0x2A, 0x05, 0x00, 0x00, 0x00, 0x40, 0xA8, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x54, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xFF, 0x7F, 0xFF, 0x40, 0x00, 0x00, 0x00, 0x3C, 0x86, 0x13, 0xC1, 0x13, 0xC5, 0x0A, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x3E, 0xC3, 0xCF, 0x3E, 0x00, 0x00, 0x00, 0x06, 0xFF, 0x06, 0xFF, 0xF1, 0xFF, 0x80, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x04, 0x8A, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x50, 0xA8, 0x50, 0xA8, 0x50, 0xA8, 0x50, 0xA8, 0x50, 0xA8, 0x50, 0xA8, 0x50, 0xA8, 0x50, 0xA8, 0x50, 0xA8, 0x54, 0xAA, 0x55, 0xAA, 0x15, 0x8A, 0x15, 0x0A, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0xFF, 0x3F, 0xFF, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x07, 0xF8, 0xFF, 0x1F, 0xFF, 0xF8, 0x07, 0x00, 0x00, 0x00, 0x03, 0x1F, 0xFF, 0xFF, 0x7E, 0x1E, 0xDF, 0xDF, 0x00, 0x00, 0x00, 0xFF, 0x01, 0xFF, 0xFF, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xA0, 0x50, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x41, 0x80, 0x41, 0x80, 0x41, 0x80, 0x41, 0x80, 0x41, 0x80, 0x41, 0x00, 0x01, 0x00, 0x01, 0x80, 0x41, 0xA0, 0x51, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xC0, 0xDC, 0xDC, 0xDC, 0xDC, 0xDC, 0xDC, 0xFC, 0xFC, 0xFC, 0x38, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0xDC, 0xDC, 0xDC, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x82, 0x85, 0x8A, 0x95, 0x8A, 0x95, 0x8A, 0x95, 0x8A, 0x95, 0x8A, 0x95, 0x8A, 0x95, 0x8A, 0x95, 0x8A, 0x95, 0x8A, 0x85, 0x82, 0x80, 0x80, 0x80, 0x88, 0x95, 0x8A, 0x95, 0x8A, 0x15, 0x0A, 0x05, 0x0A, 0x05, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x9F, 0x80, 0x9C, 0x9C, 0x9C, 0x9C, 0x9C, 0x9C, 0x9F, 0x9F, 0x8F, 0x87, 0x80, 0x80, 0x9F, 0x9F, 0x9F, 0x9F, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x9F, 0x9F, 0x9F, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x07, 0x04, 0x04, 0xFC, 0x80, 0xFC, 0x04, 0x04, 0xFF, 0x80, 0x94, 0x94, 0x94, 0x9C, 0xFF, 0x80, 0xEC, 0xEC, 0xEC, 0x80, 0xFF, 0x80, 0x80, 0xFE, 0x11, 0xFE, 0x80, 0x80, 0xFF, 0x00, 0xFE, 0x82, 0xDA, 0xDA, 0x82, 0xFE, 0xA0, 0xFE, 0x82, 0xDA, 0xDA, 0xA2, 0xFE, 0xA0, 0xFE, 0x82, 0xBA, 0xAA, 0x8A, 0xFE, 0xA0, 0xE0, 0x00, 0xFF, 0x80, 0x80, 0x9C, 0x94, 0x84, 0xFF, 0x80, 0xEC, 0xEC, 0xEC, 0x80, 0xFF, 0x80, 0x80, 0xFE, 0x11, 0xFE, 0x80, 0x80, 0xFF, 0x80, 0x94, 0x94, 0x94, 0x9C, 0xFF, 0x90, 0x94, 0x94, 0x94, 0x84, 0xFF, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x87, 0x87, 0x8E, 0x8E, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x0C, 0x0C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x0C, 0x0C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8E, 0x8E, 0x87, 0x87, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x20, 0x3B, 0x3B, 0x20, 0x3F, 0x20, 0x2A, 0x2A, 0x2E, 0x3F, 0x20, 0x2F, 0x28, 0x28, 0x3F, 0x20, 0x3A, 0x0A, 0x08, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x20, 0x3A, 0x0A, 0x08, 0x3F, 0x20, 0x2F, 0x28, 0x28, 0x3F, 0x20, 0x36, 0x36, 0x20, 0x3F, 0x08, 0x3B, 0x23, 0x38, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x20, 0x3F, 0x20, 0x3D, 0x3B, 0x20, 0x3F, 0x20, 0x3A, 0x0A, 0x0E, 0x3F, 0x20, 0x2E, 0x2E, 0x20, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x20, 0x2E, 0x2A, 0x2B, 0x3F, 0x20, 0x2E, 0x2E, 0x20, 0x3F, 0x20, 0x3D, 0x3B, 0x20, 0x3F, 0x20, 0x3A, 0x0A, 0x0E, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

PROGMEM const unsigned char qrcode[] = {
  // width, height 64, 64,
  0xFF, 0xFF, 0xFF, 0x07, 0x07, 0xE7, 0xE7, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0xE7, 0xE7, 0x07, 0x07, 0xFF, 0xFF, 0x9F, 0x9F, 0xFF, 0xFF, 0x87, 0x87, 0xFF, 0xFF, 0x67, 0x67, 0xE7, 0xE7, 0xFF, 0xFF, 0x9F, 0x9F, 0x67, 0x67, 0x9F, 0x9F, 0xE7, 0xE7, 0x67, 0x67, 0xE7, 0xE7, 0xFF, 0xFF, 0x07, 0x07, 0xE7, 0xE7, 0x67, 0x67, 0x67, 0x67, 0x67, 0x67, 0xE7, 0xE7, 0x07, 0x07, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x7F, 0x7F, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7F, 0x7F, 0x00, 0x00, 0xFF, 0xFF, 0x19, 0x19, 0x81, 0x81, 0x79, 0x79, 0x9F, 0x9F, 0x18, 0x18, 0xF9, 0xF9, 0x01, 0x01, 0x9F, 0x9F, 0x7E, 0x7E, 0x81, 0x81, 0x61, 0x61, 0xE6, 0xE6, 0x01, 0x01, 0xFF, 0xFF, 0x00, 0x00, 0x7F, 0x7F, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7F, 0x7F, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xE6, 0xE6, 0xE6, 0xE6, 0xE6, 0xE6, 0xE6, 0xE6, 0x86, 0x86, 0xFE, 0xFE, 0x66, 0x66, 0x87, 0x87, 0xE6, 0xE6, 0xE1, 0xE1, 0x18, 0x18, 0xE1, 0xE1, 0x9E, 0x9E, 0x87, 0x87, 0x66, 0x66, 0x79, 0x79, 0x18, 0x18, 0xE7, 0xE7, 0x9E, 0x9E, 0x81, 0x81, 0x98, 0x98, 0x87, 0x87, 0x9E, 0x9E, 0x86, 0x86, 0x1E, 0x1E, 0xE6, 0xE6, 0xFE, 0xFE, 0xE6, 0xE6, 0x9E, 0x9E, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x81, 0x81, 0x99, 0x99, 0xE1, 0xE1, 0x87, 0x87, 0x19, 0x19, 0x19, 0x19, 0x66, 0x66, 0xE1, 0xE1, 0xE1, 0xE1, 0x67, 0x67, 0x66, 0x66, 0x7F, 0x7F, 0x61, 0x61, 0x87, 0x87, 0x60, 0x60, 0x60, 0x60, 0x1E, 0x1E, 0x87, 0x87, 0x19, 0x19, 0x81, 0x81, 0x79, 0x79, 0x1F, 0x1F, 0x9F, 0x9F, 0x81, 0x81, 0x98, 0x98, 0xE7, 0xE7, 0x07, 0x07, 0xF9, 0xF9, 0x9F, 0x9F, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x19, 0x19, 0x87, 0x87, 0x9F, 0x9F, 0x67, 0x67, 0xE0, 0xE0, 0x00, 0x00, 0x66, 0x66, 0xF9, 0xF9, 0x19, 0x19, 0xF8, 0xF8, 0x1E, 0x1E, 0xE0, 0xE0, 0x9E, 0x9E, 0x1F, 0x1F, 0x7E, 0x7E, 0x60, 0x60, 0x80, 0x80, 0x67, 0x67, 0x1E, 0x1E, 0x99, 0x99, 0x98, 0x98, 0x9E, 0x9E, 0x1F, 0x1F, 0x79, 0x79, 0x9F, 0x9F, 0x1F, 0x1F, 0x06, 0x06, 0xF9, 0xF9, 0x9F, 0x9F, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x60, 0x60, 0x7F, 0x7F, 0x67, 0x67, 0x66, 0x66, 0x79, 0x79, 0x7E, 0x7E, 0x66, 0x66, 0xF9, 0xF9, 0x18, 0x18, 0x19, 0x19, 0x00, 0x00, 0x7F, 0x7F, 0x61, 0x61, 0xF8, 0xF8, 0xE6, 0xE6, 0x7E, 0x7E, 0x19, 0x19, 0xE6, 0xE6, 0x9E, 0x9E, 0x19, 0x19, 0x07, 0x07, 0xE7, 0xE7, 0x66, 0x66, 0xE0, 0xE0, 0x01, 0x01, 0x1E, 0x1E, 0x06, 0x06, 0x81, 0x81, 0x87, 0x87, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0xFE, 0xFE, 0x00, 0x00, 0xFF, 0xFF, 0x06, 0x06, 0x66, 0x66, 0x1E, 0x1E, 0xE0, 0xE0, 0x9E, 0x9E, 0x1F, 0x1F, 0x19, 0x19, 0x60, 0x60, 0x1E, 0x1E, 0x87, 0x87, 0x87, 0x87, 0x98, 0x98, 0xE0, 0xE0, 0x07, 0x07, 0x66, 0x66, 0x07, 0x07, 0x60, 0x60, 0x00, 0x00, 0x66, 0x66, 0x01, 0x01, 0x87, 0x87, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xE0, 0xE0, 0xE7, 0xE7, 0xE6, 0xE6, 0xE6, 0xE6, 0xE6, 0xE6, 0xE7, 0xE7, 0xE0, 0xE0, 0xFF, 0xFF, 0xE0, 0xE0, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xE1, 0xE1, 0xF8, 0xF8, 0xE6, 0xE6, 0xF8, 0xF8, 0xF8, 0xF8, 0xE7, 0xE7, 0xFF, 0xFF, 0xE7, 0xE7, 0xF9, 0xF9, 0xFE, 0xFE, 0xF8, 0xF8, 0xE0, 0xE0, 0xE6, 0xE6, 0xE0, 0xE0, 0xE6, 0xE6, 0xF8, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

//define menu states (on main menu)
#define STATE_MENU_INTRO         0
#define STATE_MENU_MAIN          1
#define STATE_MENU_HELP          2
#define STATE_MENU_PLAY          3
#define STATE_MENU_INFO          4
#define STATE_MENU_SOUNDFX       5

//define game states (on main menu)
#define STATE_GAME_PLAYING       6


boolean soundYesNo;
int menuSelection;
byte counter = 0;

void stateMenuIntro()
{
  counter++;
  arduboy.drawBitmap(0, 8, TEAMarg, 128, 48, WHITE);
  if (counter > 180) gameState = STATE_MENU_MAIN;
}

void stateMenuMain()
{
  arduboy.drawBitmap(0, 0, titleScreen, 128, 64, WHITE);
  if (buttons.justPressed(LEFT_BUTTON) && (menuSelection < 5)) menuSelection++;
  if (buttons.justPressed(RIGHT_BUTTON) && (menuSelection > 2)) menuSelection--;
  if (buttons.justPressed(B_BUTTON)) gameState = menuSelection;
}

void stateMenuHelp()
{
  if (buttons.justPressed(A_BUTTON | B_BUTTON)) gameState = STATE_MENU_MAIN;
}


void stateMenuInfo()
{
  arduboy.drawBitmap(32, 0, qrcode, 64, 64, WHITE);
  if (buttons.justPressed(A_BUTTON | B_BUTTON)) gameState = STATE_MENU_MAIN;
}

void stateMenuSoundfx()
{
  if (buttons.justPressed(DOWN_BUTTON)) soundYesNo = true;
  if (buttons.justPressed(UP_BUTTON)) soundYesNo = false;
  if (buttons.justPressed(A_BUTTON | B_BUTTON))
  {
    arduboy.audio.saveOnOff();
    gameState = STATE_MENU_MAIN;
  }
  if (soundYesNo == true) arduboy.audio.on();
  else arduboy.audio.off();
}

#endif
