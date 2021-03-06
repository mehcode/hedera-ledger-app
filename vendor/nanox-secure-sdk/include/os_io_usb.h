/* @BANNER@ */

#ifndef OS_IO_USB_H
#define OS_IO_USB_H

#include "os.h"
#include "os_io_seproxyhal.h"

#ifdef HAVE_USB_APDU

/* ----------------------------------------------------------------------- */
/* -                            IO FUNCTIONS                             - */
/* ----------------------------------------------------------------------- */
typedef REENTRANT(void (*io_send_t)(unsigned char *buffer,
                                    unsigned short length));

typedef REENTRANT(unsigned short (*io_recv_t)(unsigned char *buffer,
                                              unsigned short maxlenth));

typedef enum io_usb_hid_receive_status_e {
  IO_USB_APDU_RESET,
  IO_USB_APDU_MORE_DATA,
  IO_USB_APDU_RECEIVED,
} io_usb_hid_receive_status_t;

extern volatile unsigned int G_io_usb_hid_total_length;

void io_usb_hid_init(void);

/**
 * Receive next HID transport packet, returns IO_USB_APDU_RECEIVED when a
 * complete APDU has been received in the G_io_apdu_buffer To be called
 * typically upon USB OUT event
 */
io_usb_hid_receive_status_t
io_usb_hid_receive(io_send_t sndfct, unsigned char *buffer, unsigned short l);

/**
 * Mark the last chunk transmitted as sent.
 * To be called typically upon USB IN ACK event
 */
void io_usb_hid_sent(io_send_t sndfct);

/**
 * Request transmission of an APDU from the G_io_apdu_buffer using the HID
 * transport protocol
 */
void io_usb_hid_send(io_send_t sndfct, unsigned short sndlength);

#endif // HAVE_USB_APDU

#endif
