/* trackuino copyright (C) 2010  EA5HAV Javi
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifdef AVR

#ifndef __AFSK_AVR_H__
#define __AFSK_AVR_H__

#include <stdint.h>

//#define __PROG_TYPES_COMPAT__
#include <avr/pgmspace.h>

#include "config.h"

// Exported consts
extern const uint32_t MODEM_CLOCK_RATE;
extern const uint8_t REST_DUTY;
extern const uint16_t TABLE_SIZE;
extern const uint32_t PLAYBACK_RATE;

// Exported vars
//extern const unsigned char afsk_sine_table[] __ATTR_PROGMEM__;
extern const prog_uchar afsk_sine_table[];

// Inline functions (this saves precious cycles in the ISR)
#if AUDIO_PIN == 3
#  define OCR2 OCR2B
#endif
#if AUDIO_PIN == 11
#  define OCR2 OCR2A
#endif

inline uint8_t afsk_read_sample(int phase)
{
  return pgm_read_byte_near(afsk_sine_table + phase);
}

inline void afsk_output_sample(uint8_t s)
{
  OCR2 = s;
}

#ifdef DEBUG_MODEM
inline uint16_t afsk_timer_counter()
{
  uint16_t t = TCNT2;
  if ((TIFR2 & _BV(TOV2)) && t < 128)
    t += 256;
  return t;
}

inline int afsk_isr_overrun()
{
  return (TIFR2 & _BV(TOV2));
}
#endif


// Exported functions
void afsk_setup();
void afsk_send(const uint8_t *buffer, int len);
void afsk_start();
int afsk_busy();
void afsk_isr();
void afsk_timer_setup();
void afsk_timer_start();
void afsk_timer_stop();

#ifdef DEBUG_MODEM
void afsk_debug();
#endif

#endif
#endif // AVR
