#include <avr/io.h>
#include "state.h"

static void handle_select_main(void)
{
    switch (gSCROLL_POS)
    {
        case 0: // Send
            gDISPLAY_STATE = SEND_SCREEN;
            gSCROLL_LIMIT = SEND_SCREEN_LENGTH;
            gSCROLL_POS = 0;
            gFLAGS |= _BV(UPDATE_DISPLAY);
            break;
        case 1: // Receive
            gDISPLAY_STATE = REC_SCREEN;
            gSCROLL_LIMIT = REC_SCREEN_LENGTH;
            gSCROLL_POS = 0;
            gFLAGS |= _BV(UPDATE_DISPLAY);
            break;
        default:
            break;
    }
}

static void handle_select_send(void)
{
    switch (gSCROLL_POS)
    {
        case 0: // Global
            break;
        case 2: // Throttle
            gDISPLAY_STATE = SPOOF_THROTTLE_SCREEN;
            gSCROLL_LIMIT = SPOOF_THROTTLE_SCREEN_LENGTH;
            gCAN_LEN = SPOOF_THROTTLE_CAN_LENGTH;
            gSCROLL_POS = 0;
            gFLAGS |= _BV(UPDATE_DISPLAY);
            break;
        case 10: // Back
            gDISPLAY_STATE = MAIN_SCREEN;
            gSCROLL_LIMIT = MAIN_SCREEN_LENGTH;
            gSCROLL_POS = 0;
            gFLAGS |= _BV(UPDATE_DISPLAY);
            break;
        default:
            break;
    }
}

static void handle_select_spoof_throttle(void)
{
    switch (gSCROLL_POS)
    {
        case 0: // CAN Rate
            gEDIT_CAN ^= 1;
            gFLAGS |= _BV(UPDATE_DISPLAY);
            break;
        case 1: // Torque 1
            gEDIT_CAN ^= 1;
            gFLAGS |= _BV(UPDATE_DISPLAY);
            break;
        case 2: // Torque 2
            gEDIT_CAN ^= 1;
            gFLAGS |= _BV(UPDATE_DISPLAY);
            break;
        case 3: // Brake
            gEDIT_CAN ^= 1;
            gFLAGS |= _BV(UPDATE_DISPLAY);
            break;
        case 4: // BSPD
            gEDIT_CAN ^= 1;
            gFLAGS |= _BV(UPDATE_DISPLAY);
            break;
        case 5: // Shutdown 0x05
            gEDIT_CAN ^= 1;
            gFLAGS |= _BV(UPDATE_DISPLAY);
            break;
        case 6: // Shutdown 0x06
            gEDIT_CAN ^= 1;
            gFLAGS |= _BV(UPDATE_DISPLAY);
            break;
        case 7: // Shutdown 0x07
            gEDIT_CAN ^= 1;
            gFLAGS |= _BV(UPDATE_DISPLAY);
            break;
        case 8: // CAN Errors
            break;
        case 9: // Back
            gDISPLAY_STATE = SEND_SCREEN;
            gSCROLL_LIMIT = SEND_SCREEN_LENGTH;
            gSCROLL_POS = 0;
            gFLAGS |= _BV(UPDATE_DISPLAY);
            break;
        default:
            break;
    }
}

static void handle_select_rec(void)
{
    switch (gSCROLL_POS)
    {
        case 10: // Back
            gDISPLAY_STATE = MAIN_SCREEN;
            gSCROLL_LIMIT = MAIN_SCREEN_LENGTH;
            gSCROLL_POS = 0;
            gFLAGS |= _BV(UPDATE_DISPLAY);
            break;
        default:
            break;
    }
}

void handle_select(void)
{
    if (gDISPLAY_STATE == MAIN_SCREEN)
    {
        handle_select_main();
    }
    else if (gDISPLAY_STATE == SEND_SCREEN)
    {
        handle_select_send();
    }
    else if (gDISPLAY_STATE == REC_SCREEN)
    {
        handle_select_rec();
    }
    else if (gDISPLAY_STATE == GAME_SCREEN)
    {
    }
    else if (gDISPLAY_STATE == SPOOF_THROTTLE_SCREEN)
    {
        handle_select_spoof_throttle();
    }
}
